#include<ESP8266WiFi.h>
#include<ESP8266WiFiMulti.h>
#include<ESP8266mDNS.h>
#include<WiFiClient.h>
#include<ESP8266WebServer.h>

ESP8266WiFiMulti wifiMulti;
ESP8266WebServer server(80);

void handleRoot();
void handleNotFound();



void setup() {
  Serial.begin(115200);// put your setup code here, to run once:
  delay(10);
  Serial.println('\n');
  wifiMulti.addAP("Moto","papa123456789");
  wifiMulti.addAP("ASUS","keshav12345");
  Serial.println("Connecting.....");
  while(wifiMulti.run()!=WL_CONNECTED)
  {delay(205);Serial.print('.');}
  Serial.println('\n');
  Serial.print("Connected to :  ");
  Serial.println(WiFi.SSID());
  Serial.print("IP address :  ");
  Serial.println(WiFi.localIP());
  if(MDNS.begin("esp8266"))
  {Serial.println("mDNS responder started");
    }
    else {Serial.println("Error setting up mDNS responder!");}
    server.on("/",handleRoot);
    server.onNotFound(handleNotFound);
    server.begin();
    Serial.println("HTTP server started");
}

void loop() {
 server.handleClient();

}
void handleRoot()
{
  server.send(200,"text/plain","Hello world");
  }
void handleNotFound()
{
  server.send(404,"text/plain","404:Not found");
  }
