#include "MAX30100_PulseOximeter.h"

#define REPORTING_PERIOD_MS     1000


PulseOximeter pox;

uint32_t tsLastReport = 0;

void onBeatDetected()
{
    if(DEBUG)
    {
      Serial.println("Beat!");
    }
}
int nhipTimOke = true;
void SetupNhipTim()
{
      if (!pox.begin()) {
        Serial.println("FAILED");
        nhipTimOke = false;
        for(;;);//reset
    } else {
        Serial.println("SUCCESS");
    }
    if (nhipTimOke)
    {
      pox.setIRLedCurrent(MAX30100_LED_CURR_7_6MA);
      pox.setOnBeatDetectedCallback(onBeatDetected);
    }
}

void LoopNhipTim()
{
    if(nhipTimOke)
    {
      pox.update();
      if (millis() - tsLastReport > REPORTING_PERIOD_MS) {
  
          lcd.setCursor(0,0);
          lcd.print("Nhip tim: ");
          lcd.print(pox.getHeartRate());
          lcd.print("         ");
          lcd.setCursor(0,1);
          lcd.print("bpm / SpO2: ");
          lcd.print(pox.getSpO2());
          lcd.print("           ");
          
          if(DEBUG)
          {
            Serial.print("Heart rate:");
            Serial.print(pox.getHeartRate());
            Serial.print("bpm / SpO2:");
            Serial.print(pox.getSpO2());
            Serial.println("%");
          }
          tsLastReport = millis();
      }
    }
    else
    {
          lcd.setCursor(0,0);
          lcd.print("Nhip tim: Error                     ");
          lcd.setCursor(0,1);
          lcd.print("bpm / SpO2: Error              ");
    } 
}
