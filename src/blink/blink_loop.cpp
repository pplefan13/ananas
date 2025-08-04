#include "blink/libraries"

void blink(int pin){
for(int i=0; i<5; i++){            
    digitalWrite(pin, HIGH);
    delay(100);
    digitalWrite(pin, LOW);
    delay(100);
    }
}