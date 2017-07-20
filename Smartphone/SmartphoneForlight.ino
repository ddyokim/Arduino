#define BLYNK_PRINT Serial
#define PIN 6
#include <BlynkSimpleSerialBLE.h>
#include <SoftwareSerial.h>
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif
 
// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "********************************";
 
SoftwareSerial SerialBLE(7, 8); // RX, TX
Adafruit_NeoPixel strip = Adafruit_NeoPixel(5, PIN, NEO_GRB + NEO_KHZ800);
 
int red;
int green;
int blue;
 

boolean isLightOn = false;
boolean connectioncheck = false; 
 
BLYNK_WRITE(V0)
{
  Serial.println("Color is: ");
  red = param[0].asInt();
  green = param[1].asInt();
  blue = param[2].asInt();
 
  Serial.print("red : ");
  Serial.println(red);
  Serial.print("green : ");
  Serial.println(green);
  Serial.print("blue : ");
  Serial.println(blue);

 //light on
  for (int i = 0; i < 5; i++) {
    strip.setPixelColor(i, strip.Color(red, green, blue));
    strip.show();
  }
  isLightOn = true;

}

void setup()
{
  // Debug console
  Serial.begin(9600);
  SerialBLE.begin(9600);
  Blynk.begin(SerialBLE, auth);
  strip.begin();

  Serial.println("Waiting for connections...");

  //light off
  connectioncheck = true;
  for (int i = 0; i < 5; i++) {
    strip.setPixelColor(i, strip.Color(0, 0, 0));
    strip.show();
  }
}
 
void loop()
{
  SerialBLE.listen();
  Blynk.run();
  if (connectioncheck == true) {
    delay(3000);
    connectioncheck = false;
  }
  delay(1000);
}

