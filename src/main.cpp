#include "main_headers.h"

AsyncWebServer server(80);
int ncounter=0, nindex=0;
int dcounter=0, dindex=0;
char x[100][15]={0};
char y[100][10]={0};

void setup() {

  Serial.begin(115200);
  display_setup(); 
  //ota_setup();
  if(LittleFS.begin()){
    LittleFS.mkdir("/src/mi");
  }
  else{
    display.clearDisplay();
    display.print("littlefs not mounted");
    display.display();
  }

  mdisplay(2, 0, 0);

  /*strcpy(n, x.c_str());

  int cn_index=0, cd_index=0;
  display.clearDisplay();
  if (name.is_open()) {
    //name>>n;
    //strcat(n, "\0");
    mdisplay(2, 0, 32);
    display.print("we got a name");
    display.display();
    
    delay(1000);
    display.clearDisplay();
    
    mdisplay(3, 0, 0);
    display.print(n[0]);
    display.display();
    }
    //remove("n.txt");
  else{
    mdisplay(2, 0, 32);
    display.print("no name   muchacho");
    display.display();
    return;
  }*/
  /*else{

  }
  display.clearDisplay();
  if(!date){
    mdisplay_String("no date   muchacho", 2, 64, 32);
    return;
  }
  else{
    
    fgets(d, 2000, date);
    strcat(d, "\0");
    //remove("d.txt");
    if(d){
      mdisplay_String("date array:", 2, 0, 0);
      delay(1000);
      display.clearDisplay();
      mdisplay(d, 2, 0, 0);
    }
  }

  int j=2; //the beginning [" is automatically skipped

  do{
    if(n[j]!='"'){
      cn[cn_index]=n[j];
      cn_index++;
      j++;
    }
    else
      j++;
  }while(n[j]!=']');

  j=2;
  do{
    if(d[j]!='"'){
      cd[cd_index]=n[j];
      cd_index++;
      j++;
    }
    else
      j++;
  }while(d[j]!=']');

  /*for(size_t i=0; i<strlen(n); i++){
    if(n[i]!='[' && n[i]!=']' && n[i]!='"'){
      //n.remove(i, 1);
      strcat(cn, n[i]);
      i--;
    }
  }

  for(size_t i=0; i<strlen(d); i++){
    if(d[i]!='[' && d[i]!=']' && d[i]!='"'){
      //d.remove(i, 1);
      strcat(cd, d[i]);
      i--;
    }
  }

  for(size_t i=0; i<strlen(cn); i++){
    if(n[i]!=','){
      x[nindex][ncounter]=cn[i];
      ncounter++;
    }
    else{
      x[nindex][ncounter]='\0';
      nindex++;
      ncounter=0;
    }
  }

  for(size_t i=0; i<strlen(cd); i++){
    if(d[i]!=','){
      y[dindex][dcounter]=cd[i];
      dcounter++;
    }
    else{
      y[dindex][dcounter]='\0';
      dindex++;
      dcounter=0;
    }
  }*/
  //name.close();
  //fclose(date);
  //server.begin();
}


void loop() {
  ota_loop();

  int pos=0;
  display.clearDisplay();
  for(int ind=0; ind<=nindex; ind++){
    for(int j=0; j<strlen(x[ind]); j++){
        mdisplay(1, 6*j, pos);
        display.print(String(x[ind][j]));
        display.display();
    }

    delay(500);

    for(int j=0; j<strlen(y[ind]); j++){
        mdisplay(1, 5*j+80, pos);
        display.print(String(x[ind][j]));
        display.display();
    }
    
    pos+=10;

    if(pos>SCREEN_HEIGHT-5){
      pos=0;
      delay(1000);
      display.clearDisplay();}
    
    delay(100);}

}








