
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

void SetupManHinh()
{
  lcd.begin();
  lcd.backlight();
  lcd.print(" THCS Tien An  ");
}

void page0()
{
  lcd.begin();
  lcd.setCursor(0,0);
  lcd.print("Chon cac che do  ");

  lcd.setCursor(0,1);
  lcd.print("An vao button      ");
}
