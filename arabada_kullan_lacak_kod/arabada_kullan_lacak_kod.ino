#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define CE_PIN   9
#define CSN_PIN 10
const uint64_t pipe = 0xE8E8F0F0E1LL;
RF24 radio(CE_PIN, CSN_PIN); 
int data[2];
const int Motor1_Ileri = 4;//Sağ Motor
const int Motor1_Geri = 2;
const int Motor1_PWM = 3;

const int Motor2_Ileri = 7;//Sol Motor
const int Motor2_Geri = 6;
const int Motor2_PWM = 5; 
void setup()   
{
   pinMode(Motor1_Ileri,OUTPUT);
  pinMode(Motor1_Geri,OUTPUT);
  pinMode(Motor1_PWM,OUTPUT);
  pinMode(Motor2_Ileri,OUTPUT);
  pinMode(Motor2_Geri,OUTPUT);
  pinMode(Motor2_PWM,OUTPUT);
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(1,pipe);
  radio.startListening();;
}


void loop() {
  if ( radio.available() ) //Eğer sinyal algılarsan...
  {
    int y = data[1];
    int x = data[0];
    radio.read( data, sizeof(data) ); 
    if(y >= 400 && y <= 600) {
     digitalWrite(Motor1_Ileri,LOW);
    digitalWrite(Motor1_Geri,LOW);
    analogWrite(Motor1_PWM,0);
    digitalWrite(Motor2_Ileri,LOW);
    digitalWrite(Motor2_Geri,LOW);
    analogWrite(Motor2_PWM,0);
    }
     if(y >= 800 && y <= 1023) {
     digitalWrite(Motor1_Ileri,LOW);
    digitalWrite(Motor1_Geri,HIGH);
    analogWrite(Motor1_PWM,255);
    digitalWrite(Motor2_Ileri,LOW);
    digitalWrite(Motor2_Geri,HIGH);
    analogWrite(Motor2_PWM,255);
    }
    if(y >= 0 && y <= 450) {
     digitalWrite(Motor1_Ileri,HIGH);
    digitalWrite(Motor1_Geri,LOW);
    analogWrite(Motor1_PWM,255);
    digitalWrite(Motor2_Ileri,HIGH);
    digitalWrite(Motor2_Geri,LOW);
    analogWrite(Motor2_PWM,255);
    }
    if(x >= 0 && x <= 450) {
     digitalWrite(Motor1_Ileri,LOW);
    digitalWrite(Motor1_Geri,HIGH);
    analogWrite(Motor1_PWM,255);
    digitalWrite(Motor2_Ileri,HIGH);
    digitalWrite(Motor2_Geri,LOW);
    analogWrite(Motor2_PWM,255);
    }
    if(x >= 600 && x <= 1023) {
     digitalWrite(Motor1_Ileri,HIGH);
    digitalWrite(Motor1_Geri,LOW);
    analogWrite(Motor1_PWM,255);
    digitalWrite(Motor2_Ileri,LOW);
    digitalWrite(Motor2_Geri,HIGH);
    analogWrite(Motor2_PWM,255);
    }
  }
}
