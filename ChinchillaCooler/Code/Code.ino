#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>

const int botaoRele=5; //pino (D1) para colocar botao para ligar/desligar coolers. botao deve aterrar pino.
const int controleRele=2; //pino (D4) de saída para controle dos relés
bool sensorBotao; //variável de leitura do estado do botão

void setup() {
  pinMode(botaoRele, INPUT_PULLUP);
  pinMode(controleRele, OUTPUT);

  Serial.begin(115200);
}

void loop() {
  digitalWrite(controleRele, digitalRead(botaoRele));
}
