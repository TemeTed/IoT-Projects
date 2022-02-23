
/*------------------------------------------------------------------------------
  28/02/2019
  Authors: Maxim N. & Temesgen B.
  Based on: Makerbro
  Platforms: ESP8266
  Language: C++/Arduino
  File: wBsocketTempControl.ino
  ------------------------------------------------------------------------------
  Description: 
  Code for demonstrating IoT through the use of web socket for making a simple server 
  with an interactive html page.The application reads temprature from sensors 
  and controls a relay form the wab page.
------------------------------------------------------------------------------*/
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <WebSocketsServer.h>
#include "index.h"

ESP8266WebServer server;
WebSocketsServer webSocket = WebSocketsServer(81);

uint8_t pin_led = 2;
char* ssid = "IoThings";
char* password = "smartnetwork";
void setup()
{
  pinMode(pin_led, OUTPUT);
  WiFi.begin(ssid,password);
  Serial.begin(115200);
  while(WiFi.status()!=WL_CONNECTED)
  {
  //  Serial.print(".");
    delay(500);
  }
//  Serial.println("");
//  Serial.print("IP Address: ");
//  Serial.println(WiFi.localIP());

  server.on("/",[](){
    server.send_P(200, "text/html", webpage);  
  });
  server.begin();
  webSocket.begin();
  webSocket.onEvent(webSocketEvent);
}

void loop()
{
  webSocket.loop();
  server.handleClient();
  if(Serial.available() > 0){
    char c[] = {(char)Serial.read()};
    webSocket.broadcastTXT(c, sizeof(c));
  }
}

void webSocketEvent(uint8_t num, WStype_t type, uint8_t * payload, size_t length){
  if(type == WStype_TEXT){
    if(payload[0] == '#'){
      uint16_t relayVal = (uint16_t) strtol((const char *) &payload[1], NULL, 10);
      int sendDat = relayVal;
      Serial.println(sendDat); //Sends  value of 6 to the Arduino
    }
  }
  
}
