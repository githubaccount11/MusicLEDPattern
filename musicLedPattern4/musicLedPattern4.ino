/* 
 *  by Leigh Fair-Smiley
 *  Began 2/24/2017
 *    Derived from:
 *      musicLedPattern3
 *  LED pattern that responds to sound:
 *    Pattern is a rainbow fade over a section of the LEDs
 *    Each spectrum gets its own section
 *    Amplitude of each spectrum determines speed of rainbow fade
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
int counterfull = 100;
int[] counter = {counterfull, counterfull, counterfull, counterfull, counterfull, counterfull, counterfull};

int strob = 4;
int rst = 5;
int amp[7];
int DATA = 9;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(numLEDs, DATA, NEO_GRBW + NEO_KHZ800);
 
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

 digitalWrite(rst, HIGH);
 digitalWrite(rst, LOW);

  for (int a = 0; a < 7; a++) {
    digitalWrite(strobe, LOW);
    delayMicroseconds(30);
    amp[0] = analogRead(1);
    digitalWrite(strobe, HIGH);
    counter[0] -= counterfull * (amp / ampMax);
    counter[0]--;
  }
  
  if (counter[0] <= 0) {
    for (int a = ((numLEDs / 10) + (remainder * numLEDs)); a >= 0 ; a--) {
      strip.setPixelColor(a, RGB[0][0], RGB[0][1], RGB[0][2]);
      strip.setPixelColor(numLEDs - a, RGB[0][0], RGB[0][1], RGB[0][2]);
    }
    if (RGB[0][0] > 0 && RGB[0][2] == 0) {
      RGB[0][0] -= 5;
      RGB[0][1] +=5;
    } else if (RGB[0][1] > 0 && RGB[0][0] == 0) {
      RGB[0][1] -= 5;
      RGB[0][2] +=5;
    } else if (RGB[0][2] > 0 && RGB[0][1] == 0) {
      RGB[0][2] -= 5;
      RGB[0][0] +=5;
    }
  }

  if (counter[1] <= 0) {
    for (int a = ((numLEDs / 12) + (remainder * numLEDs)); a >= 0 ; a--) {
      strip.setPixelColor(a, RGB[1][0], RGB[1][1], RGB[1][2]);
      strip.setPixelColor(numLEDs - a, RGB[1][0], RGB[1][1], RGB[1][2]);
    }
    if (RGB[1][0] > 0 && RGB[0][2] == 0) {
      RGB[1][0] -= 5;
      RGB[1][1] +=5;
    } else if (RGB[1][1] > 0 && RGB[0][0] == 0) {
      RGB[1][1] -= 5;
      RGB[1][2] +=5;
    } else if (RGB[1][2] > 0 && RGB[1][1] == 0) {
      RGB[1][2] -= 5;
      RGB[1][0] +=5;
    }
  }

  if (counter[2] <= 0) {
    for (int a = ((numLEDs / 12) + (remainder * numLEDs)); a >= 0 ; a--) {
      strip.setPixelColor(a, RGB[2][0], RGB[2][1], RGB[2][2]);
      strip.setPixelColor(numLEDs - a, RGB[2][0], RGB[2][1], RGB[2][2]);
    }
    if (RGB[2][0] > 0 && RGB[2][2] == 0) {
      RGB[2][0] -= 5;
      RGB[2][1] +=5;
    } else if (RGB[2][1] > 0 && RGB[2][0] == 0) {
      RGB[2][1] -= 5;
      RGB[2][2] +=5;
    } else if (RGB[2][2] > 0 && RGB[2][1] == 0) {
      RGB[2][2] -= 5;
      RGB[2][0] +=5;
    }
  }

  if (counter[3] <= 0) {
    for (int a = ((numLEDs / 12) + (remainder * numLEDs)); a >= 0 ; a--) {
      strip.setPixelColor(a, RGB[3][0], RGB[3][1], RGB[3][2]);
      strip.setPixelColor(numLEDs - a, RGB[3][0], RGB[3][1], RGB[3][2]);
    }
    if (RGB[3][0] > 0 && RGB[3][2] == 0) {
      RGB[3][0] -= 5;
      RGB[3][1] +=5;
    } else if (RGB[3][1] > 0 && RGB[3][0] == 0) {
      RGB[3][1] -= 5;
      RGB[3][2] +=5;
    } else if (RGB[3][2] > 0 && RGB[3][1] == 0) {
      RGB[3][2] -= 5;
      RGB[3][0] +=5;
    }
  }

  if (counter[4] <= 0) {
    for (int a = ((numLEDs / 12) + (remainder * numLEDs)); a >= 0 ; a--) {
      strip.setPixelColor(a, RGB[4][0], RGB[4][1], RGB[4][2]);
      strip.setPixelColor(numLEDs - a, RGB[4][0], RGB[4][1], RGB[4][2]);
    }
    if (RGB[4][0] > 0 && RGB[4][2] == 0) {
      RGB[4][0] -= 5;
      RGB[4][1] +=5;
    } else if (RGB[4][1] > 0 && RGB[4][0] == 0) {
      RGB[4][1] -= 5;
      RGB[4][2] +=5;
    } else if (RGB[4][2] > 0 && RGB[4][1] == 0) {
      RGB[4][2] -= 5;
      RGB[4][0] +=5;
    }
  }

  if (counter[5] <= 0) {
    for (int a = ((numLEDs / 12) + (remainder * numLEDs)); a >= 0 ; a--) {
      strip.setPixelColor(a, RGB[5][0], RGB[5][1], RGB[5][2]);
      strip.setPixelColor(numLEDs - a, RGB[5][0], RGB[5][1], RGB[5][2]);
    }
    if (RGB[5][0] > 0 && RGB[5][2] == 0) {
      RGB[5][0] -= 5;
      RGB[5][1] +=5;
    } else if (RGB[5][1] > 0 && RGB[5][0] == 0) {
      RGB[5][1] -= 5;
      RGB[5][2] +=5;
    } else if (RGB[5][2] > 0 && RGB[5][1] == 0) {
      RGB[5][2] -= 5;
      RGB[5][0] +=5;
    }
  }

  if (counter[6] <= 0) {
    for (int a = ((numLEDs / 12) + (remainder * numLEDs)); a >= 0 ; a--) {
      strip.setPixelColor(a, RGB[6][0], RGB[6][1], RGB[6][2]);
      strip.setPixelColor(numLEDs - a, RGB[6][0], RGB[6][1], RGB[6][2]);
    }
    if (RGB[6][0] > 0 && RGB[6][2] == 0) {
      RGB[6][0] -= 5;
      RGB[6][1] +=5;
    } else if (RGB[6][1] > 0 && RGB[6][0] == 0) {
      RGB[6][1] -= 5;
      RGB[6][2] +=5;
    } else if (RGB[6][2] > 0 && RGB[6][1] == 0) {
      RGB[6][2] -= 5;
      RGB[6][0] +=5;
    }
  }
  
  strip.show();

  for (int a = 0; a < 7; a++) {
    if (counter[a] <= 0) {
      counter[a] = counterfull;
    }
  }
}


