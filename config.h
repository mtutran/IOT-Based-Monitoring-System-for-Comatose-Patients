#define DEBUG true


#ifndef STASSID
#define STASSID "Co&Com"
#define STAPSK  "20172018"
#endif

const char* ssid     = STASSID;
const char* password = STAPSK;

const int channelID = 12345; //
String writeAPIKey = "YOUR-API-KEY"; // write API key for your ThingSpeak Channel
const char* server = "api.thingspeak.com";

int bt1Pin = D3;
int bt2Pin = D7;
int bt3Pin = D6;
int bt4Pin = D5;

int page = 0;

float thanNhiet = 36.5;
int SYS = 120;
int DIA = 80;
int PULSE = 60;
int nhipTim = 60;
int SPO2 = 95;
