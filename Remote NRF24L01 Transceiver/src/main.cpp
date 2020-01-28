/* nRF24L01 Circuitry

   1 - GND 
   2 - VCC 3.3V // 3.3v Not 5V !
   3 - CE - Arduino pin 7
   4 - CSN - Arduino pin 8
   5 - SCK - Arduino pin 13
   6 - MOSI - Arduino pin 11
   7 - MISO - Arduino pin 12
   8 - UNUSED rf

 */

#include <Arduino.h>
#include <nRF24L01.h>
#include <printf.h>
#include <RF24.h>
#include <RF24_config.h>

#define CE_PIN   7
#define CSN_PIN  8

#define FORWARD 9
#define REVERSE 6
#define LEFT 5
#define RIGHT 4
#define DOME_LEFT 3
#define DOME_RIGHT 2

const uint64_t pipe = 0xE8E8F0F0E1LL; // This is the transmit pipe for communication
RF24 radio(CE_PIN, CSN_PIN); // Activate  the Radio
int data[6];  // Six element array holding the Joystick+buttons readings

void setup()   
{
  pinMode(FORWARD, INPUT);
  pinMode(REVERSE, INPUT);
  pinMode(LEFT, INPUT);
  pinMode(RIGHT, INPUT);
  pinMode(DOME_LEFT, INPUT);
  pinMode(DOME_RIGHT, INPUT);
  radio.begin();
  radio.openWritingPipe(pipe);
}

void loop()
{

  data[0] = !digitalRead(FORWARD);
  data[1] = !digitalRead(REVERSE);
  data[2] = !digitalRead(LEFT);
  data[3] = !digitalRead(RIGHT);
  data[4] = !digitalRead(DOME_LEFT);
  data[5] = !digitalRead(DOME_RIGHT);
  
  radio.write(&data, sizeof(data) );
  delay(5);

}
