#include <NTPClient.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

//dados para conexão na wi-fi
const char *ssid     = "Deco2";
const char *password = "Lolicasa8";

//setando UTC -3 (-10800 segundos)
const long utcOffsetInSeconds = -10800;
int hora;//variavel para armazenar hora atual

//variavel para armazenamento de contador de tempo e intervalo de checagem de horario
unsigned long previousMillis = 0;
unsigned long interval = 120000;

const int botaoRele=5; //pino (D1) para colocar botao para ligar/desligar coolers. botao deve aterrar pino.
const int controleRele=2; //pino (D4) de saída para controle dos relés

// Define NTP Client to get time
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "south-america.pool.ntp.org", utcOffsetInSeconds);

void setup(){
  Serial.begin(115200);

  //Setup dos pinos
  pinMode(botaoRele, INPUT_PULLUP);
  pinMode(controleRele, OUTPUT);

  //bloco para conexão com rede
  WiFi.begin(ssid, password);
  while ( WiFi.status() != WL_CONNECTED ) {
    delay ( 500 );
    Serial.print ( "." );
  }

  timeClient.begin();
}

void loop() {
  unsigned long currentMillis = millis();//variavel para checar passagem de tempo
  if(currentMillis - previousMillis >= interval){
    //salvar o momento de ultima checagem
    previousMillis = currentMillis;
    timeClient.update();
    hora=timeClient.getHours();
    Serial.println(hora);
    Serial.print(timeClient.getHours());
    Serial.print(":");
    Serial.println(timeClient.getMinutes());
  }

  if (digitalRead(botaoRele)==0){//checagem do botão
    digitalWrite(controleRele, HIGH);
    Serial.println("relés ligados devido ao botão");
  }else if(hora>=10 && hora<=17){//checagem do horário: ligar relés entre 10:00 e 18:00.
    digitalWrite(controleRele, HIGH);
    Serial.println("relés ligados devido à hora");
  }else{//nada a fazer. relés desativados.
    digitalWrite(controleRele, LOW);
  }
}
