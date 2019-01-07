
#include <ESP8266WiFi.h>
#define echo D7
#define trig D6

int duration;
int cm;


const char *ssid="NodeMCU Hotspot";           // SSID of your home WiFi
const char *pass="pawan12345";            // password of your home WiFi


IPAddress server(192,168,4,15);     // IP address of the AP
WiFiClient client;



void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, pass);           // connects to the WiFi AP
  Serial.println();
  Serial.println("Connection to the AP");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.println("Connected");
  Serial.println("station_bare_01.ino");
  Serial.print("LocalIP:"); Serial.println(WiFi.localIP());
  Serial.println("MAC:" + WiFi.macAddress());
  Serial.print("Gateway:"); Serial.println(WiFi.gatewayIP());
  Serial.print("AP MAC:"); Serial.println(WiFi.BSSIDstr());
 
  pinMode(echo,INPUT);
  pinMode(trig,OUTPUT);
  
}

void loop() {
  client.connect(server, 80);
 
  checkwl();
  if(cm<=10)
  {
    
    
    client.print("100\r");
    Serial.print("Data 100 sent to the AP");
    client.flush();
    
    }
   else if((cm>=12)&&(cm<=16))
   {
    
    
    client.print("75\r");
    Serial.println("  ");
    Serial.print("Data 75 sent to the AP");
    client.flush();
    
    }
   else if((cm>=17)&&(cm<=19))
   {
    
    
    client.print("50\r");
    Serial.println("  ");
    Serial.print("Data 50 sent to the AP");
    client.flush();
    
    }
   else if((cm>=20)&&(cm<=23))
   {
    
    
    client.print("25\r");
    Serial.println("  ");
    Serial.print("Data 25 sent to the AP");
    client.flush();
    
    }
   else if(cm>24)
   {
    
    
    client.print("0\r");
    Serial.println("  ");
    Serial.print("Data 0 sent to the AP");
    client.flush();
    
    }
  client.stop();
  delay(1000);
}

void checkwl()
{
  digitalWrite(trig,LOW);
   delayMicroseconds(2);
   digitalWrite(trig,HIGH);
   delayMicroseconds(10);
   digitalWrite(trig,LOW);
   duration=pulseIn(echo,HIGH);
   cm=duration/29/2;
   Serial.println(" ");
   Serial.print("Distance=");
   Serial.println(cm);
  
  }
