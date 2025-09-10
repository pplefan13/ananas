#include "file_handling.h"

void file_checking(File &name, File &date){
  if(!name){
    display.clearDisplay();
    mdisplay("no name   muchacho", 2, 0, 32);
  }
  if(!date){
    mdisplay("no date   muchacho", 2, 64, 32);
  }
}

void string_handling(String &s){
  for(int i=0; i<s.length(); i++){
    if(s[i]=='[' || s[i]==']' || s[i]=='"'){
      s.remove(i, 1);
      i--;
    }
  }
}