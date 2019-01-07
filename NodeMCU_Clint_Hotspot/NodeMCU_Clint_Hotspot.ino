/*  Connects to the home WiFi network
 *  Asks some network parameters
 *  Sends and receives message from the server in every 2 seconds
 *  Communicates: wifi_server_01.ino
 */ 
#include <SPI.h>
#include <ESP8266WiFi.h>

#define ledPin LED_BUILTIN 
const char *ssid="NodeMCU Hotspot";           // SSID of your Hotspot
const char *pass="pawan12345";            // password of your Hotspot

unsigned long askTimer = 0;

IPAddress server(192, 168, 4, 2);       // the fix IP address of the server
WiFiClient client;

void setup() {
  Serial.begin(115200);
  delay(10);
  Serial.println('\n');
  WiFi.softAP(ssid,pass);
  Serial.print("Access Point:  ");
  Serial.println(ssid);  
  Serial.print("IP Address : ");
  Serial.println(WiFi.softAPIP());
  pinMode(ledPin, OUTPUT);
}

void loop () {
  client.connect(server, 80);   // Connection to the server
  digitalWrite(ledPin, LOW);    // to show the communication only (inverted logic)
  Serial.println(".");
  client.println("Hello server! Are you sleeping?\r");  // sends the message to the server
  String answer = client.readStringUntil('\r');   // receives the answer from the sever
  Serial.println("from server: " + answer);
  client.flush();
  digitalWrite(ledPin, HIGH);
  delay(2000);                  // client will trigger the communication after two seconds
}
