
#include <Adafruit_MLX90614.h>

Adafruit_MLX90614 mlx = Adafruit_MLX90614();

long long last_mlx = 0;
const int step_mlx = 1000;

void SetupNhietDo()
{
  mlx.begin();
}

void LoopNhietDo()
{
   if (millis() - last_mlx > step_mlx)
  {
    if(DEBUG)
    {
      Serial.print("Ambient = "); Serial.print(mlx.readAmbientTempC());
      Serial.print("*C\tObject = "); Serial.print(mlx.readObjectTempC()); Serial.println("*C");
    }
    if(mlx.readObjectTempC() > mlx.readAmbientTempC() + 2)
    {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Do nhiet do");
      lcd.setCursor(0,1);
      lcd.print("Xin cho 2s");
      delay(1000);
      lcd.setCursor(0,1);
      lcd.print("Xin cho 1s             ");
      delay(1000);
      lcd.setCursor(0,1);
      lcd.print("           ");
      lcd.setCursor(0,1);
      lcd.print("Nhiet do: ");
      float tmp = mlx.readObjectTempC();
      lcd.print(String(tmp,2));
      lcd.print("*C");
      delay(3000);
      lcd.setCursor(0,0);
      lcd.print("Do nhiet do         ");
      lcd.setCursor(0,1);
      lcd.print("dat tay vao       ");
    }
    last_mlx = millis();
  }
  
}
