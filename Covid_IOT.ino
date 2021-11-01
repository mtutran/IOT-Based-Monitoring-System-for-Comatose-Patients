#include <Wire.h>
#include <ESP8266WiFi.h>
#include "config.h"
#include "manHinhLCD.h"
#include "camBienNhietDo.h"
#include "mayDoHuyetAp.h"
#include "nhipTim.h"
#include "guiDuLieuESP.h"

void setup() {
  Serial.begin(115200);
  Serial.println("Bat Dau");
  pinMode(bt1Pin, INPUT_PULLUP);
  pinMode(bt2Pin, INPUT_PULLUP);
  pinMode(bt3Pin, INPUT_PULLUP);
  pinMode(bt4Pin, INPUT_PULLUP);
  SetupManHinh();
  SetupNhietDo();
  setup_HuyetAp();
  SetupNhipTim();
}

void loop() {
  switch(page)
  {
    case 0: page0(); break;
    case 1: loop_HuyetAp(); break;
    case 2: LoopNhipTim(); break;
    case 3: LoopNhietDo(); break;
    case 4: GuiDuLieuThingSpeak(); break;
  }
  if(digitalRead(bt1Pin) == LOW)
  {
    page = 4;
  }
  if(digitalRead(bt2Pin) == LOW)
  {
    page = 1;      
    lcd.setCursor(0,0);
    lcd.print("Do huyet ap              ");
    
    lcd.setCursor(0,1);
    lcd.print("Khoi dong may do              ");
  }
  if(digitalRead(bt3Pin) == LOW)
  {
    page = 2;
  }
  if(digitalRead(bt4Pin) == LOW)
  {
    page = 3;
    lcd.setCursor(0,0);
    lcd.print("Do nhiet do         ");
    lcd.setCursor(0,1);
    lcd.print("dat tay vao       ");
  }
}
