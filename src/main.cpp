#include "main_lib.h"
int ncounter=0, nindex=0;
int dcounter=0, dindex=0;
char x[100][15]={0};
char y[100][15]={0};

void setup() {
  Serial.begin(115200);
  display_setup(); 
  ota_setup();

  if(!LittleFS.begin()) {
    display.clearDisplay();
    mdisplay("LittleFS Mount Failed", 1, 0, 0);
    return;
  }
  delay(1000);

  //opening files and checking they alright
  File name=LittleFS.open("n.txt", "r");
  File date=LittleFS.open("e.txt", "r");

  file_checking(name, date);
  
  String n=name.readString();
  String d=date.readString();

  string_handling(n);
  string_handling(d);

  nindex=array_handling(n, x, nindex, ncounter);
  array_handling(d, y, dindex, dcounter);

  name.close();
  date.close();
}


void loop() {
  ota_loop();

  int pos=0;
  display.clearDisplay();
  
  for(int ind=0; ind<=nindex; ind++){
    for(int j=0; j<strlen(x[ind]); j++)
      mdisplay(String(x[ind][j]), 1, 6*j, pos);
    
    delay(500);

    if(y[ind][0]=='-'){
      for(int j=1; j<strlen(y[ind]); j++){ //to skip the -
        String message1="acum "+String(y[ind][j]);
        mdisplay(message1, 1, 5*(j-1)+80, pos); //to make it aligned and have it start at 80
      }
    }else if(y[ind][0]=='0'){
      mdisplay("azi", 1, 80, pos);
    }else if(y[ind][0]!='-'&& y[ind][0]!='0') {
      for(int j=0; j<strlen(y[ind]); j++)
        mdisplay(String(y[ind][j]), 1, 5*j+80, pos); 
    }
    
    pos+=10;

    if(pos>SCREEN_HEIGHT-5){
      pos=0;
      delay(3000);
      display.clearDisplay();}
    
    delay(1000);
  }
}








