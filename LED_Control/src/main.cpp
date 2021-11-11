#include <Arduino.h>
#include <FastLED.h>

#define NUM_LEDS 60
#define LED_PIN 13

CRGB leds[NUM_LEDS];

void setAltLEDS(CRGB::HTMLColorCode color1, CRGB::HTMLColorCode color2, int dly)
{

  for (int i = 0; i < NUM_LEDS; i++)
  {
    if (i % 2 == 0)
    {
      leds[i] = color1;
    }
    else
    {
      leds[i] = color2;
    }
  }
  FastLED.show();
  delay(dly);
  for (int i = 0; i < NUM_LEDS; i++)
  {
    if (i % 2 != 0)
    {
      leds[i] = color1;
    }
    else
    {
      leds[i] = color2;
    }
  }
  FastLED.show();
  delay(dly);
}

void setup() {
  // put your setup code here, to run once:
  //initialize builtin LED
  // pinMode(LED_BUILTIN,OUTPUT);
  FastLED.addLeds<WS2812B, LED_PIN,GRB>(leds,NUM_LEDS);
  FastLED.setBrightness(25);

}

void loop() {
  // put your main code here, to run repeatedly:
  // digitalWrite(LED_BUILTIN, HIGH); // turn the LED on (HIGH is the voltage level)
  // delay(1000);                     // wait for a second
  // digitalWrite(LED_BUILTIN, LOW);  // turn the LED off by making the voltage LOW
  // delay(1000);
  // for(int i = 0; i < NUM_LEDS; i++) {
  //   if(i % 2 == 0) {
  //     leds[i] = CRGB::LightBlue;
  //   }
  //   else {
  //     leds[i] = CRGB::Blue;
  //   }
  // }
  int dly = 1000;
  setAltLEDS(CRGB::LightBlue,CRGB::Blue,dly);

}