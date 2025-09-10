#include "main_lib.h"


void setup() {
  Serial.begin(115200);
  display_setup(); 
  ota_setup();

  if(!LittleFS.begin()) {
    display.clearDisplay();
    mdisplay("LittleFS Mount Failed", 1, 0, 0);
    return;
  } else{
    display.clearDisplay();
    mdisplay("LittleFS Mounted", 1, 0, 0);
  }
  delay(1000);
  //opening files and checking they alright
  File name=LittleFS.open("n.txt", "r");
  File date=LittleFS.open("d.txt", "r");
  
  display.clearDisplay();
  file_checking(name, date);

  delay(1000);
  
  String n=name.readString();
  String d=date.readString();

  string_handling(n);
  string_handling(d);

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
  //server.begin();
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








