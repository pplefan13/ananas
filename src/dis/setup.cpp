#include "dis/dimensions"

  void display_setup(){
  Serial.begin(115200);

  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  // the library initializes this with an Adafruit splash screen.
  display.display();
  delay(200);

  // Clear the buffer
  display.clearDisplay();

  // Draw a single pixel in white
  //display.drawPixel(10, 10, SSD1306_WHITE);
  mdisplay("setup loading...", 2, 0, 13);

  // Show the display buffer on the screen. You MUST call display() after drawing 
  //commands to make them visible on screen!
  display.display();
  delay(200);
}