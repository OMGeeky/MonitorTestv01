#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Fonts/Picopixel.h>
#include <Fonts/FreeMono12pt7b.h>
#include <LedControl.h>
//
LedControl lc = LedControl(12, 10, 11, 1);

unsigned long delaytime1 = 500;
unsigned long delaytime2 = 50;

//Display Definition

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

int cursorX = 10;
int cursorY = 30;

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET 4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup()
{
  //Serial Monitor Setup
  Serial.begin(9600);
  //Display Setup
  {
    // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
    { // Address 0x3C for 128x32
      Serial.println(F("SSD1306 allocation failed"));
      for (;;)
        ; // Don't proceed, loop forever
    }

    // Clear the buffer
    display.clearDisplay();

    // Draw a single pixel in white
    display.drawPixel(cursorX, cursorY, WHITE);

    // Show the display buffer on the screen. You MUST call display() after
    // drawing commands to make them visible on screen!
    display.display();
    delay(2000);
  }

  //Matrix Setup
  {
    lc.shutdown(0, false);
    lc.setIntensity(0, 8);
    lc.clearDisplay(0);
  }
}

void writeArduinoOnMatrix()
{
  /* here is the data for the characters */
  byte a[5] = {B01111110, B10001000, B10001000, B10001000, B01111110};
  byte r[5] = {B00010000, B00100000, B00100000, B00010000, B00111110};
  byte d[5] = {B11111110, B00010010, B00100010, B00100010, B00011100};
  byte u[5] = {B00111110, B00000100, B00000010, B00000010, B00111100};
  byte i[5] = {B00000000, B00000010, B10111110, B00100010, B00000000};
  byte n[5] = {B00011110, B00100000, B00100000, B00010000, B00111110};
  byte o[5] = {B00011100, B00100010, B00100010, B00100010, B00011100};

  /* now display them one by one with a small delay */
  lc.setRow(0, 0, a[0]);
  lc.setRow(0, 1, a[1]);
  lc.setRow(0, 2, a[2]);
  lc.setRow(0, 3, a[3]);
  lc.setRow(0, 4, a[4]);
  delay(delaytime1);
  lc.setRow(0, 0, r[0]);
  lc.setRow(0, 1, r[1]);
  lc.setRow(0, 2, r[2]);
  lc.setRow(0, 3, r[3]);
  lc.setRow(0, 4, r[4]);
  delay(delaytime1);
  lc.setRow(0, 0, d[0]);
  lc.setRow(0, 1, d[1]);
  lc.setRow(0, 2, d[2]);
  lc.setRow(0, 3, d[3]);
  lc.setRow(0, 4, d[4]);
  delay(delaytime1);
  lc.setRow(0, 0, u[0]);
  lc.setRow(0, 1, u[1]);
  lc.setRow(0, 2, u[2]);
  lc.setRow(0, 3, u[3]);
  lc.setRow(0, 4, u[4]);
  delay(delaytime1);
  lc.setRow(0, 0, i[0]);
  lc.setRow(0, 1, i[1]);
  lc.setRow(0, 2, i[2]);
  lc.setRow(0, 3, i[3]);
  lc.setRow(0, 4, i[4]);
  delay(delaytime1);
  lc.setRow(0, 0, n[0]);
  lc.setRow(0, 1, n[1]);
  lc.setRow(0, 2, n[2]);
  lc.setRow(0, 3, n[3]);
  lc.setRow(0, 4, n[4]);
  delay(delaytime1);
  lc.setRow(0, 0, o[0]);
  lc.setRow(0, 1, o[1]);
  lc.setRow(0, 2, o[2]);
  lc.setRow(0, 3, o[3]);
  lc.setRow(0, 4, o[4]);
  delay(delaytime1);
  lc.setRow(0, 0, 0);
  lc.setRow(0, 1, 0);
  lc.setRow(0, 2, 0);
  lc.setRow(0, 3, 0);
  lc.setRow(0, 4, 0);
  delay(delaytime1);
}

void loop()
{
  writeArduinoOnMatrix();
/*
  delay(1000);

  display.clearDisplay();

  display.setFont(&FreeMono12pt7b);
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.setTextWrap(true);
  display.setCursor(cursorX, cursorY);
  display.println(F("hi! "));
  display.display();
  delay(1000);
  display.startscrolldiagright(0, 63);
  delay(3000);
  display.stopscroll();
  //display.setCursor(cursorX+50,cursorY);
  display.startscrolldiagleft(0, 31);
  delay(5000);
  display.stopscroll();
  delay(2000);
  display.clearDisplay();
  display.setCursor(cursorX, cursorY);
  display.println("hi ");
  display.display();
  delay(2000);
  display.clearDisplay();
  display.setCursor(cursorX, cursorY);
  display.println("test");
  display.display();
  delay(2000);
  */
}
