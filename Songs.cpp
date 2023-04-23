
const float  A3 =   220.00;
const float Bb3 =   233.08;
const float  B3 =   246.94;
const float  C4 =   261.63;
const float Db4 =   277.18;
const float  D4 =   293.66;
const float Eb4 =   311.13;
const float  E4 =   329.63;
const float  F4 =  	349.23;
const float Gb4 =   369.99;
const float  G4 =   392.00;
const float Ab4 =   415.30;

const int buzzer = 8;

void CantHelpFallingInLove(){
    float bpm = 100.00;//bpm da música
    float note = bpm*1000/60;
    tone(buzzer, C4);
    delay(note*2);
    tone(buzzer, G4);
    delay(note*2);
    tone(buzzer, C4);
    delay(note*2);

}


void setup(){
    pinMode(8, OUTPUT);
    Serial.begin(9600);
}

void loop(){
    CantHelpFallingInLove();
}