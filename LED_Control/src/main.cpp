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

void setLightning(CRGB::HTMLColorCode color1, CRGB::HTMLColorCode color2, int dly, int num_lit, bool ret=false) {
  for(int i = 0; i < NUM_LEDS; i++) {
    for(int j = 0; j < num_lit; j++) {
      if(i + j < NUM_LEDS) {
        if (j % 2 == 0)
        {
          leds[i + j] = color1;
        }
        else
        {
          leds[i + j] = color2;
        }
      }
    }
    FastLED.show();
    delay(dly);
    fill_solid(leds, NUM_LEDS, CRGB::Black);
    FastLED.show();
  }
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
  int dly = 30;
  int numLit = 5;
  // setAltLEDS(CRGB::LightBlue,CRGB::Blue,dly);
  setLightning(CRGB::LightBlue,CRGB::Blue,dly,numLit);

}