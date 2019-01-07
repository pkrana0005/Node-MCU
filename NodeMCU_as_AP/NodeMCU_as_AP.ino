#include<ESP8266WiFi.h>

const char *ssid="NodeMCU Hotspot";
const char *password="pawan12345";

void setup()
{
  Serial.begin(115200);
  delay(10);
  Serial.println('\n');
  WiFi.softAP(ssid,password);
  Serial.print("Access Point:  ");
  Serial.println(ssid);  
  Serial.print("IP Address");
  Serial.println(WiFi.softAPIP());


  
}
void loop(){}
