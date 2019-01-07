/*  Accesspoint - station communication without router
 *  see: https://github.com/esp8266/Arduino/blob/master/doc/esp8266wifi/station-class.rst
 *  Works with: accesspoint_bare_01.ino
 */

#include <ESP8266WiFi.h>


#define wl25 D5                //25% water level
#define wl50 D1                //50% water level
#define wl75 D2                //75% water level
#define wl100 D7               //100% water level
#define win D8                //water successfully coming from water pump
 
const char *ssid="NodeMCU Hotspot";           // SSID of your home WiFi
const char *pass="pawan12345";            // password of your home WiFi


IPAddress server(192,168,4,15);     // IP address of the AP
WiFiClient client;

int wl0r;
int wl25r;
int wl50r;
int wl75r;
int wl100r;
int winr;

void setup() {
  Serial.begin(115200);
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
 
  
  pinMode(wl25,INPUT);
  pinMode(wl50,INPUT);
  pinMode(wl75,INPUT);
  pinMode(wl100,INPUT);
  pinMode(win,INPUT);
}

void loop() {
  client.connect(server, 80);
 /* checkwin();
  if(winr==1)
  {
   
    
    client.print("yes\r");
    Serial.println("Data yes sent to the AP");
    client.flush();
   
    }
   else
   {
    
    ;
    client.print("no\r");
    Serial.print("Data no sent to the AP");
    client.flush();
    
    }*/
  checkwl();
  if(wl100r==1)
  {
    
    
    client.print("100\r");
    Serial.print("Data 100 sent to the AP");
    client.flush();
    
    }
   else if(wl75r==1)
   {
    
    
    client.print("75\r");
    Serial.println("  ");
    Serial.print("Data 75 sent to the AP");
    client.flush();
    
    }
   else if(wl50r==1)
   {
    
    
    client.print("50\r");
    Serial.println("  ");
    Serial.print("Data 50 sent to the AP");
    client.flush();
    
    }
   else if(wl25r==1)
   {
    
    
    client.print("25\r");
    Serial.println("  ");
    Serial.print("Data 25 sent to the AP");
    client.flush();
    
    }
   else
   {
    
    
    client.print("0\r");
    Serial.println("  ");
    Serial.print("Data 0 sent to the AP");
    client.flush();
    
    }
  client.stop();
  delay(2000);
}

void checkwl()
{
  
  wl25r=digitalRead(wl25);
  wl50r=digitalRead(wl50);
  wl75r=digitalRead(wl75);
  wl100r=digitalRead(wl100);
  Serial.println("  ");
  Serial.print("wl100r= "); Serial.println(wl100r);
  Serial.print("wl75r= "); Serial.println(wl75r);
  Serial.print("wl50r= "); Serial.println(wl50r);
  Serial.print("wl25r= "); Serial.println(wl25r);
  }

void checkwin()
{
  winr=digitalRead(win);
  Serial.println("  ");
  Serial.print("winr= ");
  Serial.println(winr);
  }
