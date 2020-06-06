
#include <SPI.h> 
#include <nRF24L01.h>
#include <RF24.h>


#define CE_PIN  9
#define CSN_PIN 10
#define x_axis A1 // x axis
#define y_axis A2 //y axis




const uint64_t pipe = 0xE8E8F0F0E1LL; 
RF24 radio(CE_PIN, CSN_PIN); 
int data[2];  

void setup() 
{
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(pipe);
}

void loop()   
{

  data[0] = analogRead(x_axis);
  data[1] = analogRead(y_axis);
  radio.write( data, sizeof(data) ); 
 
//HATA AYIKLAMA (DEBUG)
  Serial.print(analogRead(x_axis));
  Serial.print(" ");
  Serial.print(analogRead(A1));
  Serial.print(" ");
  //Serial.print(digitalRead(BUTON));
}
