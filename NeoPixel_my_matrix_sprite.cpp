/***********************
 NeoPixel Matrix Sprite
 February 2015
 Giovanni Gentile
 http://www.0lab.it
 Creative Common License
************************/

#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>
#ifndef PSTR
 #define PSTR // Make Arduino Due happy
#endif
#include "Definitions.h"
#include "Shape.h"

// Control PIN
#define PIN 6

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(8, 8, PIN,
  NEO_MATRIX_BOTTOM     + NEO_MATRIX_LEFT +
  NEO_MATRIX_COLUMNS + NEO_MATRIX_PROGRESSIVE,
  NEO_GRB            + NEO_KHZ800);

// --------------------------------------------  
// Set the color of animation (see Definitions.h)
const uint16_t colors[] = { matrix.Color(255, 0, 0), matrix.Color(0, 255, 0), matrix.Color(0, 0, 255) };
// Set the brightness (max 50)
int brigh = 40;
// Delay between animation
int wait = 300;
// ---------------------------------------------

void setup() {
  matrix.begin();
  matrix.setTextWrap(false);
  matrix.setBrightness(brigh);
}

// Variable to print text
int x = matrix.width();
int pass = 0;

void loop() {
// Set the color of text (see Definitions.h)
//  scrivi("Ciao Amoremiobello", MAGENTA);

// Text change color
//  scriviColor("Ciao");

// Set the animation
  battito();
  pacman();
  space();
  heart();
}

void sprite(const uint8_t* x, unsigned long y, int w){
  byte red = (y & 0xFF0000) >> 16;
  byte green = ( y & 0x00FF00) >> 8;
  byte blue = (y & 0x0000FF);
  matrix.drawBitmap(0,0, x, 8, 8, matrix.Color(red, green, blue));
  matrix.show();
  delay(w);
  matrix.fillScreen(0);
}

void scrivi(String z, unsigned long y) {
  int len = z.length();
  matrix.fillScreen(0);
  matrix.setCursor(x, 0);
  byte red = (y & 0xFF0000) >> 16;
  byte green = ( y & 0x00FF00) >> 8;
  byte blue = (y & 0x0000FF);
  matrix.print(z);
  if(--x < -len*6) {
    x = matrix.width();
  }
  matrix.setTextColor(matrix.Color(red,green,blue));
  matrix.show();
  delay(100);
}

void scriviColor(String y) {
  int len = y.length();
  matrix.fillScreen(0);
  matrix.setCursor(x, 0); 
  matrix.print(y);
  //matrix.print(F("Scrivi"));
  if(--x < -len*6) {
    x = matrix.width();
    if(++pass >= 3) pass = 0;
    matrix.setTextColor(colors[pass]);
  }
  matrix.show();
  delay(100);
}

 // ---Animation---
 void heart() {
   sprite(cuore1,RED,wait);
   sprite(cuore1,PINK,wait);
   sprite(cuore1,BLUE,wait);
   sprite(cuore1,MAGENTA,wait);
 }
 void space() {
   unsigned long COLOR = RED;
   sprite(alienoa1,BLUE,wait);
   sprite(alienoa2,BLUE,wait);
   sprite(alienoa1,BLUE,wait);
   sprite(alienob1,COLOR,wait);
   sprite(alienob2,COLOR,wait);
   sprite(alienob1,COLOR,wait);
   sprite(alienoc1,VIOLET,wait);
   sprite(alienoc2,VIOLET,wait);
   sprite(alienoc1,VIOLET,wait);
   sprite(navicella1,COLOR,wait);
   sprite(navicella2,COLOR,wait);
   sprite(navicella3,COLOR,wait);
   sprite(navicella4,COLOR,wait);
 }
 void pacman() {
   sprite(pacman1,YELLOW,wait);
   sprite(pacman2,YELLOW,wait);
   sprite(pacman1,YELLOW,wait);
   sprite(pacman2,YELLOW,wait); 
   sprite(pacman3,YELLOW,wait);
   sprite(pacman4,YELLOW,wait); 
   sprite(pacman5,YELLOW,wait); 
   sprite(pacman1,YELLOW,wait); 
   sprite(pacman2,YELLOW,wait); 
   sprite(pacman1,YELLOW,wait);
   sprite(pacman3,YELLOW,wait);
   sprite(gost4,RED,wait);
   sprite(gost5,RED,wait);
   sprite(gost1,RED,wait);
   sprite(gost2,RED,wait);
   sprite(gost3,RED,wait);
   sprite(gost4,HOTPINK,wait);
   sprite(gost5,HOTPINK,wait); 
   sprite(gost1,HOTPINK,wait);
   sprite(gost2,HOTPINK,wait);
   sprite(gost3,HOTPINK,wait);
   sprite(gost4,ORANGE,wait);
   sprite(gost5,ORANGE,wait); 
   sprite(gost1,ORANGE,wait);
   sprite(gost2,ORANGE,wait);
   sprite(gost3,ORANGE,wait);
   sprite(gost4,AQUA,wait);
   sprite(gost5,AQUA,wait);
   sprite(gost1,AQUA,wait);
   sprite(gost2,AQUA,wait); 
   sprite(gost3,AQUA,wait);
   sprite(pacman1,YELLOW,wait);
   sprite(pacman2,YELLOW,wait);
   sprite(pacman1,YELLOW,wait);
   sprite(pacman2,YELLOW,wait); 
   sprite(pacman3,YELLOW,wait);
   sprite(pacman4,YELLOW,wait); 
   sprite(pacman5,YELLOW,wait); 
   sprite(pacman1,YELLOW,wait); 
   sprite(pacman2,YELLOW,wait); 
   sprite(pacman1,YELLOW,wait);
   sprite(pacman3,YELLOW,wait);
 }
 void battito() {
   sprite(cuore1,RED,400);
   sprite(cuore2,RED,200);
   sprite(cuore3,RED,100);
   sprite(cuore2,RED,200);
   sprite(cuore1,RED,400);   
   sprite(cuore2,RED,200);
   sprite(cuore3,RED,100);
   sprite(cuore2,RED,200);
 }
