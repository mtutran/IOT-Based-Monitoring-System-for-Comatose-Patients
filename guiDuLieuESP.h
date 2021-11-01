WiFiClient client;

void KetNoiWifi()
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("ThingSpeak");
  lcd.setCursor(0,1);
  lcd.print("Ket noi wifi");
  if(WiFi.status() != WL_CONNECTED) 
  {
    Serial.print("Connecting to ");
    Serial.println(ssid);
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
  
    while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
    }
  
    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("ThingSpeak");
    lcd.setCursor(0,1);
    lcd.print("Da ket noi internet");
    delay(1000);
  }
}

void GuiDuLieuThingSpeak()
{
//  KetNoiWifi();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("ThingSpeak");
  lcd.setCursor(0,1);
  lcd.print("Gui du lieu");
  if (client.connect(server, 80)) {
          String body = "field1=" + String(thanNhiet, 2) + "&field2=" 
                      + String(nhipTim) + "&field3=" + String(SPO2) 
                      + "&field4=" + String(SYS)+ "&field5" + String(DIA)
                      + "&field6=" + String(PULSE);

          client.print("POST /update HTTP/1.1\n");
          client.print("Host: api.thingspeak.com\n");
          client.print("Connection: close\n");
          client.print("X-THINGSPEAKAPIKEY: " + writeAPIKey + "\n");
          client.print("Content-Type: application/x-www-form-urlencoded\n");
          client.print("Content-Length: ");
          client.print(body.length());
          client.print("\n\n");
          client.print(body);
          client.print("\n\n");
  }
  client.stop();
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("ThingSpeak");
  lcd.setCursor(0,1);
  lcd.print("Gui Oke");
}
