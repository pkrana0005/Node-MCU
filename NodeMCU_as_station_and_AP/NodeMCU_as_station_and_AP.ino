#include<ESP8266WiFi.h>

const char *ssidhs="NodeMCU Hotspot";
const char *passwordhs="pawan12345";
const char *ssids="6pro";
const char *passwords="pk1234567";
void setup() {
  Serial.begin(115200);// put your setup code here, to run once:
  delay(10);
  Serial.println('\n');
  WiFi.begin(ssids,passwords);
  Serial.print("Connecting to ");
Serial.print(ssids);
Serial.println("....");
int i=0;
while(WiFi.status()!=WL_CONNECTED)
{delay(1000);
 Serial.print(++i);
 Serial.print(' ');
  }
 Serial.println('\n');
 Serial.println("Connection established");
 Serial.print("IP address:  ");
 Serial.println(WiFi.localIP());
 
 
 
 Serial.println('\n');
  WiFi.softAP(ssidhs,passwordhs);
  Serial.print("Access Point:  ");
  Serial.println(ssidhs);  
  Serial.print("IP Address");
  Serial.println(WiFi.softAPIP());

}

void loop() {
  // put your main code here, to run repeatedly:

}
