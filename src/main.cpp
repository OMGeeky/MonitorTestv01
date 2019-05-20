#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Fonts/Picopixel.h>



int adaiwjdlk = 5;


#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

int cursorX = 10;
int cursorY = 30;

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(9600);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x32
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Don't proceed, loop forever
  }

  // Clear the buffer
  display.clearDisplay();

  // Draw a single pixel in white
  display.drawPixel(cursorX, cursorY, WHITE);

  // Show the display buffer on the screen. You MUST call display() after
  // drawing commands to make them visible on screen!
  display.display();
  delay(200);
  // display.display() is NOT necessary after every single drawing command,
  // unless that's what you want...rather, you can batch up a bunch of
  // drawing operations and then update the screen all at once by calling
  // display.display(). These examples demonstrate both approaches...
}
void loop() {


  delay(1000);

  display.clearDisplay();
  display.setTextColor(WHITE);
  //void setTextColor(uint16_t color, uint16_t backgroundcolor);
  display.setTextSize(2);
  //display.setFont(&Picopixel);
  display.setTextWrap(true);
  display.setCursor(cursorX, cursorY);
  display.println(F("hi! "));
  display.display();
  delay(1000);
  display.startscrolldiagright(0x00, 0x0F);
  delay(5000);
  display.stopscroll();
  display.setCursor(cursorX, cursorY);
  display.println("hi ");
  display.display();
  delay(2000);
  display.println("test");
  display.display();
  delay(2000);
//  Serial.println("test shown");
//  delay(2000);
//  display.setCursor(cursorX, cursorY);
//  display.println("hi!");
//  display.display();
//  display.clearDisplay();
//  delay(2000);
//  display.setCursor(cursorX, cursorY);
//  display.println("HI!!");
//  display.display();
//  delay(2000);
//  display.clearDisplay();
//  display.setCursor(cursorX, cursorY);
//  display.println("hallo");
//  display.display();
//  delay(2000);
//
}