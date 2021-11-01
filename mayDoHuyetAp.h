
int HexToDec(char k)
{
  switch (k)
  {
      case '0':
        return 0;
        break;
      case '1':
        return 1;
        break;
      case '2':
        return 2;
        break;
      case '3':
        return 3;
        break;
      case '4':
        return 4;
        break;
      case '5':
        return 5;
        break;
      case '6':
        return 6;
        break;
      case '7':
        return 7;
        break;
      case '8':
        return 8;
        break;
      case '9':
        return 9;
        break;
      case 'A':
        return 10;
        break;
      case 'B':
        return 11;
        break;
      case 'C':
        return 12;
        break;
      case 'D':
        return 13;
        break;
      case 'E':
        return 14;
        break;
      case 'F':
        return 15;
        break;
  }
 
}
int StrToHex(String str)
{
  return HexToDec(str[0])*16 + HexToDec(str[1]);
}
void setup_HuyetAp()
{
  
}

int i_check = 0;
void loop_HuyetAp()
{  
  if (Serial.available() > 0)
  {
    String tmp = "";
    delay(20);
    while (Serial.available() > 0)
    {
      char t = Serial.read();
      tmp += t;
    }
//    Serial.println(tmp);
    if (i_check == 1)i_check++;
    if (i_check == 2)
    {
      tmp.trim();
      
      Serial.println("Data:" + tmp + ";");
      Serial.print("SYS: ");
      int s1 = StrToHex(tmp.substring(0, 2));
      Serial.println(s1);

      Serial.print("DIA: ");
      int s2 = StrToHex(tmp.substring(3, 5));
      Serial.println(s2);

      Serial.print("PULSE: ");
      int s3 = StrToHex(tmp.substring(9, 11));
      Serial.println(s3);
      
      Serial.println("Saved....");

      
      lcd.setCursor(0,0);
      lcd.print("SYS | DIA | PULSE");
      lcd.setCursor(0,1);
      lcd.print(s1);lcd.print("   ");
      lcd.print(s2);lcd.print("   ");
      lcd.print(s3);
      delay(5000);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Saved");
      delay(3000);
      lcd.clear();
      i_check = 3;
    }

    if (tmp.indexOf("start test") != -1)
    {
      lcd.setCursor(0,0);
      lcd.print("May do huyet ap           ");
      lcd.setCursor(0,1);
      lcd.print("bat bom           ");
    }

    if (tmp.indexOf("addQas") != -1)
    {
      lcd.setCursor(0,0);
      lcd.print("May do huyet ap           ");
      lcd.setCursor(0,1);
      lcd.print("Tat bom                ");
    }

    if (tmp.indexOf("test return:0save record") != -1)
    {
      lcd.setCursor(0,0);
      lcd.print("May do huyet ap           ");
      lcd.setCursor(0,1);
      lcd.print("Do thanh cong                ");
      Serial.println("Do thanh cong");
    }

    if (tmp.indexOf("save record") != -1)
    {
      lcd.setCursor(0,0);
      lcd.print("May do huyet ap           ");
      lcd.setCursor(0,1);
      lcd.print("Doc du lieu                ");
      Serial.println("GET DATA.....................");
      i_check = 1;
    }

  }
}
