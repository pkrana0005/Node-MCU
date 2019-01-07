#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>

const char* ssid="Moto";
const char* password="papa123456789";

void setup() {
 Serial.begin(115200); // put your setup code here, to run once:
delay(10);
Serial.println('\n');

WiFi.begin(ssid,password);
Serial.print("Connecting to ");
Serial.print(ssid);
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

 if(!MDNS.begin("myesp"))
 {Serial.println("Error setting up mDNS responder!");}
 Serial.println("mDNS responder started");
 
}

void loop() {
  // put your main code here, to run repeatedly:

}
