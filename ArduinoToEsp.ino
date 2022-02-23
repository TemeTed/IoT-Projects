/*------------------------------------------------------------------------------
  28/02/2019
  Author: Maxim N. & Temesgen B.
  Based on: Makerbro
  Platform: Arduino Uno
  Language: C++/Arduino
  File: ArduinoToEsp.ino
  ------------------------------------------------------------------------------
  Description:
  This application uses virtual serial port for transmitting data from sensors to
  the wifi module.It also recieves commands from the ESP module for controlling
  the connected actuators.
  ------------------------------------------------------------------------------*/

#include <SoftwareSerial.h>
SoftwareSerial ESP_Serial(10,11); //Rx,Tx

const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
const int relayPin = 3; // Digital output pin for the relay
int sensorValue = 0;
boolean flag = false;
void setup() {
  Serial.begin(9600);
  ESP_Serial.begin(115200);
  pinMode(relayPin, OUTPUT);
  delay(3000);
  Serial.println(" Preparing to communicate with the ESP module");
}

void loop() {
   if(ESP_Serial.available() > 0){
    char c[] = {(char)ESP_Serial.read()};
    if ( c[0] =='6') {
   Serial.println("Data recieved");
    if (flag)
      digitalWrite(relayPin, LOW);
    else
      digitalWrite(relayPin, HIGH);
    flag = !flag;
}
  }
   
  else{
  sensorValue = analogRead(analogInPin);

  ESP_Serial.print("Temperature "); //data to ESP module
  ESP_Serial.println(sensorValue);
  Serial.print("Temperature "); // For debug purpose
  Serial.println(sensorValue);
}
  delay(3000);
  Serial.flush();
}
