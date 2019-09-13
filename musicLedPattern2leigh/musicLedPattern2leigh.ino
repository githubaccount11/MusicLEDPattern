/*
 * musicLedPattern2:
   * By Leigh Fair-Smiley
   * Began 2/10/2017-2/20/2017 
   * 
   *  Sound is split into 7 spectrums using the MSGEQ7
   *  LEDs are individually addressable (I used the WS2812b)
   * 
   * Description: LED pattern that responds to sound
   *  Large centered red/orange for lowest (base) frequency and second lowest respectively (the orange is 1/5th shorter)
   *    amp controls size
   *  Three white LEDs every 5 LEDs for middle (vocal) ranged
   *    amp controls brightness
   *  The Three highest freqency bands show in seperate sections at ends of LED strip colored (turquoise, blue, purple)
   *    amp controls brightness
 *    
 * musicLedPattern3:
   * by Leigh Fair-Smiley
   * Began 2/23/2017
   *   Modified on:
   *     2/24/2017 to: 
   *       added code for MSGEQ7
   *       include and integrate neoPixel Library
   *         added lots of "strip.", line defining DATA pin, and begin
   * LED pattern that responds to sound:
   *   Pattern is a rainbow chase over a section of the LEDs
   *   Each spectrum gets its own section
   *   Amplitude of each spectrum determines speed of rainbow chase
   * Sound is split into 7 spectrums using the MSGEQ7
   * LEDs are individually addressable (I used the WS2812b)
   * 
 * 
 * musicLedPattern4:
   * by Leigh Fair-Smiley
   * Began 2/24/2017
   *   Derived from:
   *     musicLedPattern3
   * LED pattern that responds to sound:
   *   Pattern is a rainbow fade over a section of the LEDs
   *   Each spectrum gets its own section
   *   Amplitude of each spectrum determines speed of rainbow fade
   * Sound is split into 7 spectrums using the MSGEQ7
   * LEDs are individually addressable (I used the WS2812b)
 */



#include <Adafruit_NeoPixel.h>


int RGB[7][3];

int ampMax = 1024;
int numLEDs = 27;
double remainderOfLEDs = 6346/100000;
int cycleAmount = 5; /* complete rainbow in ~150 LEDs */
int counterfull = 100;
int counter[] = {counterfull, counterfull, counterfull, counterfull, counterfull, counterfull, counterfull};
int brightness = 0;

int strobe = 4;
int rst = 5;
int amp[7];
int DATA = 9;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(numLEDs, DATA, NEO_GRBW + NEO_KHZ800);
 
void setup() {
  
  RGB[0][0] = 255;
  RGB[1][0] = 255;
  RGB[2][0] = 255;
  RGB[3][0] = 255;
  RGB[4][0] = 255;
  RGB[5][0] = 255;
  RGB[6][0] = 255;

 Serial.begin(115200);
 pinMode(rst, OUTPUT);
 pinMode(strobe, OUTPUT);
 digitalWrite(rst, LOW);
 digitalWrite(strobe, HIGH);
 strip.begin();
 strip.show();
}

void loop() {
  
  for (int a = 0; a < ((amp[0] / ampMax) * (numLEDs / 2)); a++) {
    strip.setPixelColor((numLEDs / 2) + a, 255, 0, 0);
    strip.setPixelColor((numLEDs / 2) - a, 255, 0, 0);
  }

  for (int a = 0; a < ((amp[1] / ampMax) * (numLEDs / 2)); a++) {
    strip.setPixelColor((numLEDs / (9 / 5)) + a, 170, 85, 0);
    strip.setPixelColor((numLEDs / (9 / 5)) - a, 170, 85, 0);
  }

  brightness = (amp[5] / ampMax) * 255;
  for (int a = 0; a < (numLEDs / 20); a++) {
    strip.setPixelColor(a, 0, 128, 127, brightness);
    strip.setPixelColor(numLEDs - a, 0, 128, 127, brightness);
  }
  
  brightness = (amp[6] / ampMax) * 255;
  for (int a = 0; a < (numLEDs / 20); a++) {
    strip.setPixelColor(a + (numLEDs / 20), 0, 0, 255, brightness);
    strip.setPixelColor(numLEDs - (a + (numLEDs / 20)), 0, 0, 255, brightness);
  }
  
  brightness = (amp[7] / ampMax) * 255;
  for (int a = 0; a < (numLEDs / 20); a++) {
    strip.setPixelColor(a + ((numLEDs / 20) * 2), 127, 0, 128, brightness);
    strip.setPixelColor(numLEDs - (a + ((numLEDs / 20) * 2)), 127, 0, 128, brightness);
  }
  
  brightness = (amp[4] / ampMax) * 255;
  for (int a = 0; a < numLEDs; a+=5) {
    for (int b = 0; b < (a + 3) && a < numLEDs; b++) {
      strip.setPixelColor(a, 255, 255, 255, brightness);
      a++;
    }
  }

  strip.show();
}
