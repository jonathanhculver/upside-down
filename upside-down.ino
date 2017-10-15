/*
  G35: An Arduino library for GE Color Effects G-35 holiday lights.
  Copyright © 2011 The G35 Authors. Use, modification, and distribution are
  subject to the BSD license as described in the accompanying LICENSE file.
*/

#include <G35String.h>

#define LIGHT_COUNT (25)
#define G35_PIN (13)

G35String lights(G35_PIN, LIGHT_COUNT);

String letters = "abcdefgponmlkjihqrstuvzyx";
char colorArray[12] = {COLOR_WHITE, COLOR_RED, COLOR_GREEN, COLOR_CYAN, COLOR_MAGENTA, COLOR_YELLOW, COLOR_PURPLE, COLOR_ORANGE, COLOR_PALE_ORANGE, COLOR_WARMWHITE, COLOR_INDIGO, COLOR_VIOLET};    

void setup() {
  lights.enumerate();
  
  Serial.begin(9600);
  lightsOff();
  delay(200);
}

void loop() {   
   goCrazy();
   delay(1000);
   lightWord("run");
   delay(1000);
}

void lightWord(String wordString) {
  for(int i=0; i<wordString.length(); i=i+1) {
    lightLetter(wordString.charAt(i));
  }
}

void lightLetter(char letter) {
  int letterIndex = letters.indexOf(letter);
  lights.fill_color(letterIndex, 1, G35::MAX_INTENSITY, COLOR_RED);
  delay(1000);
  lights.fill_color(letterIndex, 1, 0, COLOR_RED);
  delay(200);
}

void goCrazy() {
  for(int i=0; i<100; i=i+1) {
    allOfTheLights();
  }
  lightsOff();
}

void allOfTheLights() {
  for(int i=0; i<LIGHT_COUNT; i=i+1) {
    int num = random(0,12);
    lights.fill_color(i, 1, G35::MAX_INTENSITY, colorArray[num]);
  }
  delay(100);
}

void lightsOff() {
  lights.fill_color(-1, LIGHT_COUNT, 0, COLOR_RED);
}







