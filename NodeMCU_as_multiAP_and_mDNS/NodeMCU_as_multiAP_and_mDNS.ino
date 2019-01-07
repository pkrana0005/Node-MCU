#include<ESP8266WiFi.h>
#include<ESP8266WiFiMulti.h>
#include<ESP8266mDNS.h>

ESP8266WiFiMulti wifimulti;


void setup() {
 Serial.begin(115200);// put your setup code here, to run once:
 delay(10);
 wifimulti.addAP("Moto","papa123456789");
 wifimulti.addAP("Redmi","pawan12345");
 Serial.print('\n');
 Serial.println("Connecting.....");
 int i=0;
 while(wifimulti.run()!=WL_CONNECTED)
 {
  delay(1000);
  Serial.print(++i);
  Serial.print(" ");}
  
  Serial.println('\n');
  Serial.print("Connected to:  ");
  Serial.println(WiFi.SSID());
  Serial.print("IP address:   ");
  Serial.println(WiFi.localIP());
  

  if(MDNS.begin("myesp"))
  {Serial.println("mDNS responder started!");}
  else{Serial.println("Error setting up mDNS responder!");}
  
}

void loop() {
  // put your main code here, to run repeatedly:

}
