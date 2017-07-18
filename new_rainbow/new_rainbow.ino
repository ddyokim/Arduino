#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif
 
#define PIN 6
 
Adafruit_NeoPixel strip = Adafruit_NeoPixel(5, PIN, NEO_GRB + NEO_KHZ800);
 
int red = 0;
int green = 0;
int blue = 0;
int colors[5][3];

void setup() {
  strip.begin();
  Serial.begin(9600);
  red = 255;
  green = 255;
  blue = 255;
  
  //color initializing
  rainbow();
}

void rainbow() {
  colors[0][0] = 255; colors[0][1] = 0; colors[0][2] = 0; //빨
  colors[1][0] = 255; colors[1][1] = 255; colors[1][2] = 0; //노
  colors[2][0] = 0; colors[2][1] = 255; colors[2][2] = 0; //초
  colors[3][0] = 0; colors[3][1] = 0; colors[3][2] = 255; //파
  colors[4][0] = 253; colors[4][1] = 0; colors[4][2] = 255; //보  
}

void loop() {
  int tmp[3] = {colors[0][0], colors[0][1], colors[0][2]};
  for (int i = 0; i < 4; i++) {
    int idx = i+1;
    for (int j = 0; j < 3; j++)
      colors[i][j] = colors[idx][j];
  }
  for (int j = 0; j < 3; j++)
      colors[4][j] = tmp[j];
      
  for (int i = 0; i < 5; i++) {
    strip.setPixelColor(i, strip.Color(colors[i][0], colors[i][1], colors[i][2]));
    strip.show();
  }
  delay(100);
}
