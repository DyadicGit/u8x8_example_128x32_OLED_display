#include <Arduino.h>
#include <U8x8lib.h>
#include "../lib/icons/HVACIcons.h"
U8X8_SSD1306_128X32_UNIVISION_SW_I2C u8x8(/* clock=A5*/ 19, /* data=A4*/ 18);
void displayLCD();

void setup(void) {
  u8x8.begin();
  u8x8.setPowerSave(0);
}

void loop(void) {
  u8x8.setFont(u8x8_font_chroma48medium8_r);
  uint8_t rows = u8x8.getRows();
  uint8_t cols = u8x8.getCols();
  char rowsArr[3];
  char colArr[3];
  String(rows).toCharArray(rowsArr, 4);
  String(cols).toCharArray(colArr, 4);
  u8x8.draw2x2String(0, 0, "rows:");
  u8x8.draw2x2String(12, 0, rowsArr);
  u8x8.drawString(0, 2, "cols:");
  u8x8.draw2x2String(8, 2, colArr);
  delay(2000);

  u8x8.clearDisplay();
  u8x8.setPowerSave(1);
  delay(1000);
  u8x8.setPowerSave(0);

  u8x8.setFont(u8x8_font_pxplusibmcgathin_f);
  displayLCD();
  u8x8.drawTile(9, 0, 1, HVACIcons::ventilator8x8);
  u8x8.drawTile(15, 4, 1, HVACIcons::house);
  delay(2000);
  u8x8.clearDisplay();

  u8x8.setFont(u8x8_font_pxplusibmcgathin_f);
  u8x8.setCursor(0, 0);
  u8x8.print("fan working");
  u8x8.drawTile(12, 2, 2, HVACIcons::ventilator16x16_1of2);
  u8x8.drawTile(12, 3, 2, HVACIcons::ventilator16x16_2of2);
  u8x8.setCursor(1, 2);
  int timeCounter = (int) round(38000/1000);
  u8x8.print(timeCounter);
  while (timeCounter>=0 ) {
    u8x8.setCursor(1, 2);
    u8x8.print(timeCounter);
    if (timeCounter < 10000) {u8x8.print("    ");}
    timeCounter--;
    delay(300);
  }
  u8x8.clearDisplay();
}

void displayLCD() {
  u8x8.setCursor(0, 0);
  u8x8.print("CO2:");
  u8x8.setCursor(4, 0);
  u8x8.print(109);

  u8x8.setCursor(0, 2);
  u8x8.print("CH4:");
  u8x8.setCursor(4, 2);
  u8x8.print(6691);

  u8x8.setCursor(11, 0);
  u8x8.print("temp:");
  u8x8.setCursor(11, 2);
  String strg = String(2224*5/1024) + (char) 0xB0 + "C";
  u8x8.print(strg);
}
