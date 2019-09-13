void setup() {
  // put your setup code here, to run once:

}

void loop() {
  int numLEDs = 0;
  int ampMax = 1024;
  int[] amp = new int[7]
  int brigtness = 0;
  
  while (int a = 0; a < ((amp[0] / ampMax) * (numLEDs / 2)); a++) {
    setPixelColor((numLEDs / 2 ) + a, 255, 0, 0);
    setPixelColor((numLEDs / 2) - a, 255, 0, 0);
  }

  while (int a = 0; a < ((amp[1] / ampMax) * (numLEDs / 2)); a++) {
    setPixelColor((numLEDs / 2 ) + a, 170, 85, 0);
    setPixelColor((numLEDs / 2) - a, 170, 85, 0);
  }

  brigtness = (amp[5] / ampMax) * 255;
  for (int a = 0; a < (numLEDs / 20); a++) {
    setPixelColor(a, 0, 128, 127, brightness);
    setPixelColor(numLEDs - a, 0, 128, 127, brightness);
  }
  
  brigtness = (amp[6] / ampMax) * 255;
  for (int a = 0; a < (numLEDs / 20); a++) {
    setPixelColor(a + (numLEDs / 20), 0, 0, 255, brightness);
    setPixelColor(numLEDs - (a + (numLEDs / 20)), 0, 0, 255, brightness);
  }
  
  brigtness = (amp[7] / ampMax) * 255;
  for (int a = 0; a < (numLEDs / 20); a++) {
    setPixelColor(a + ((numLEDs / 20) * 2), 127, 0, 128, brightness);
    setPixelColor(numLEDs - (a + ((numLEDs / 20) * 2)), 127, 0, 128, brightness);
  }
  
  brightness = (amp[4] / ampMax) * 255;
  for (int a = 0; a < numLEDs; a+=5) {
    for (int b = 0; b < (a + 3) && a < numLEDs; b++) {
      setPixelColor(a, 255, 255, 255, brightness);
      a++;
    }
  }

  Pixels.show();
}
