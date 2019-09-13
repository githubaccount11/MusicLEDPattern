/* 
 *  by Leigh Fair-Smiley
 *  Began 2/23/2017
 *    Modified on:
 *      2/24/2017 to: 
 *        added code for MSGEQ7
 *        include and integrate neoPixel Library
 *          added lots of "strip.", line defining DATA pin, and begin
 *  LED pattern that responds to sound:
 *    Pattern is a rainbow chase over a section of the LEDs
 *    Each spectrum gets its own section
 *    Amplitude of each spectrum determines speed of rainbow chase
 *  Sound is split into 7 spectrums using the MSGEQ7
 *  LEDs are individually addressable (I used the WS2812b)
 */

#include <Adafruit_NeoPixel.h>


int RGB[7][3];
RGB[0] = {255, 0, 0};
RGB[1] = {255, 0, 0};
RGB[2] = {255, 0, 0};
RGB[3] = {255, 0, 0};
RGB[4] = {255, 0, 0};
RGB[5] = {255, 0, 0};
RGB[6] = {255, 0, 0};

int ampMax = 1024;
int numLEDs = 0;
double remainderOfLEDs = 6346/100000;
int cycleAmount = 5; /* complete rainbow in ~150 LEDs */

int strob = 4;
int rst = 5;
int amp[7];
int DATA = 9;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(numLEDs, DATA, NEO_GRB + NEO_KHZ800);
 
void setup() {
 Serial.begin(115200);
 pinMode(rst, OUTPUT);
 pinMode(strobe, OUTPUT);
 digitalWrite(rst, LOW);
 digitalWrite(strobe, HIGH);
 strip.begin();
 strip.show();
}

void loop() {
  int rgb[3];

 digitalWrite(rst, HIGH);
 digitalWrite(rst, LOW);

  for (int a = 0; a < 7; a++) {
    digitalWrite(strobe, LOW);
    delayMicroseconds(30);
    amp[0] = analogRead(1);
    digitalWrite(strobe, HIGH);
  }

  for (int a = 0; a < (numLEDs * amp[0] / 4) / amp; a++) {
      strip.setPixelColor((numLEDs / 4) + a, 255, 100, 100);
      strip.setPixelColor((numLEDs / 4) - a, 255, 100, 100);
      strip.setPixelColor((numLEDs * 3 / 4) + a, 255, 100, 100);
      strip.setPixelColor((numLEDs * 3 / 4) - a, 255, 100, 100);
  }

   

  strip.show();
}


