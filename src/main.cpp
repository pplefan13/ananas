#include <iostream>
#include <string.h>
#include "blink/libraries"
#include "ota/ota.h"
#include "dis/dimensions"
#include <FS.h>
#include <LittleFS.h>
#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <ArduinoJson.h>

AsyncWebServer server(80);
int ncounter=0, nindex=0;
int dcounter=0, dindex=0;
char x[100][15]={0};
char y[100][10]={0};

void setup() {
  Serial.begin(115200);
  display_setup(); 
  ota_setup();

  if(!LittleFS.begin()) {  // Add this check
        Serial.print("LittleFS Mount Failed");
        return;
    }

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(LittleFS, "/ananasite.html", "text/html");});

  server.on("/ananasite.html", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(LittleFS, "/ananasite.html", "text/html");});

  server.on("/frigider.html", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(LittleFS, "/frigider.html", "text/html");});

  server.on("/home_style.css", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(LittleFS, "/home_style.css", "text/css");});

  server.on("/frigider_style.css", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(LittleFS, "/frigider_style.css", "text/css");});
  
  server.on("/functions.js", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(LittleFS, "/functions.js", "application/javascript");});
  
  server.on("/line.png", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(LittleFS, "/line.png", "image/png");});  
  
  server.on("/line_orange.png", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(LittleFS, "/line_orange.png", "image/png");}); 
  
  server.on("/emoji.png", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(LittleFS, "/emoji.png", "image/png");});  
  
  server.on("/favicon.ico", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(LittleFS, "/favicon.ico", "image/x-icon");});  

  //opening files and checking they alright
  File name=LittleFS.open("n.txt", "r");
  File date=LittleFS.open("d.txt", "r");
  
  display.clearDisplay();
  if (!name) {
    mdisplay("no name   muchacho", 2, 0, 32);
    return;
  }
  if(!date){
    mdisplay("no date   muchacho", 2, 64, 32);
    return;
  }
  
  String n=name.readString();
  String d=date.readString();

  for(int i=0; i<n.length(); i++){
    if(n[i]=='[' || n[i]==']' || n[i]=='"'){
      n.remove(i, 1);
      i--;
    }
    if(d[i]=='[' || d[i]==']' || d[i]=='"'){
      d.remove(i, 1);
      i--;
    }
  }

  for(int i=0; i<n.length(); i++){
    if(n[i]!=','){
      x[nindex][ncounter]=n[i];
      ncounter++;
    }
    else{
      x[nindex][ncounter]='\0';
      nindex++;
      ncounter=0;
    }
  }

  for(int i=0; i<d.length(); i++){
    if(d[i]!=','){
      y[dindex][dcounter]=d[i];
      dcounter++;
    }
    else{
      y[dindex][dcounter]='\0';
      dindex++;
      dcounter=0;
    }
  }

  name.close();
  date.close();
  server.begin();
}


void loop() {
  ota_loop();

  int pos=0;
  display.clearDisplay();
  for(int ind=0; ind<=nindex; ind++){
    for(int j=0; j<strlen(x[ind]); j++)
        mdisplay(String(x[ind][j]), 1, 6*j, pos);
    delay(500);

    for(int j=0; j<strlen(y[ind]); j++)
        mdisplay(String(y[ind][j]), 1, 5*j+80, pos);
    
    pos+=10;

    if(pos>SCREEN_HEIGHT-5){
      pos=0;
      delay(1000);
      display.clearDisplay();}
    
    delay(100);}

}








