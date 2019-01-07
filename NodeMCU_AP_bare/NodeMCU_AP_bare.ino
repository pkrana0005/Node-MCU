/*  Accesspoint - station communication without router
 *  see: https://github.com/esp8266/Arduino/blob/master/doc/esp8266wifi/soft-access-point-class.rst
 *       https://github.com/esp8266/Arduino/blob/master/doc/esp8266wifi/soft-access-point-examples.rst
 *       https://github.com/esp8266/Arduino/issues/504
 *  Works with: station_bare_01.ino
 */ 


#include <ESP8266WiFi.h>

WiFiServer server(80);
IPAddress IP(192,168,4,15);
IPAddress mask = (255, 255, 255, 0);

int man_mode_read;
int pump_read;
int supply_read;


const char *ssid="NodeMCU Hotspot";           // SSID of your home WiFi
const char *pass="pawan12345";            // password of your home WiFi

#define led100 D0
#define led75 D9
#define led50 D8
#define led25 D7
#define led0 D3
#define ledwin D4
#define man_mode D5
#define pump D6
#define supply D2
#define motor D1

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid,pass);
  WiFi.softAPConfig(IP, IP, mask);
  server.begin();
 
  Serial.println();
  
  Serial.println("Server started.");
  Serial.print("IP: ");     Serial.println(WiFi.softAPIP());
  Serial.print("MAC:");     Serial.println(WiFi.softAPmacAddress());

  pinMode(led100,OUTPUT);
  pinMode(led75,OUTPUT);
  pinMode(led50,OUTPUT);
  pinMode(led25,OUTPUT);
  pinMode(led0,OUTPUT);
  pinMode(man_mode,INPUT);
  pinMode(pump,INPUT);
 
  pinMode(ledwin,OUTPUT);
  pinMode(supply,INPUT);
  pinMode(motor,OUTPUT);
  digitalWrite(motor,LOW);
  digitalWrite(ledwin,LOW);
  digitalWrite(led100,LOW);
  digitalWrite(led0,LOW);
}

void loop() {

  supply_read=digitalRead(supply);
  man_mode_read=digitalRead(man_mode);
  pump_read=digitalRead(pump);
  
  WiFiClient client = server.available();
  
 
  String request = client.readStringUntil('\r');
  Serial.println("  ");
  Serial.println("From the station: " + request);
  
  

  if(request=="yes")  //water reaching tank
  {
    digitalWrite(ledwin,HIGH);
    Serial.println("  ");
    Serial.println(" yes ");
    }
   else if(request=="no")
   {
    digitalWrite(ledwin,LOW);
    Serial.println("  ");
    Serial.println(" no ");
    }
    
  
  

  if(request=="100")
  {
    digitalWrite(led100,HIGH);
    digitalWrite(led75,HIGH);
    digitalWrite(led50,HIGH);
    digitalWrite(led25,HIGH);
    digitalWrite(led0,HIGH);
    }
   else if(request=="75")
   {
    digitalWrite(led100,LOW);
    digitalWrite(led75,HIGH);
    digitalWrite(led50,HIGH);
    digitalWrite(led25,HIGH);
    digitalWrite(led0,HIGH);
    } 
   else if(request=="50")
   {
    digitalWrite(led100,LOW);
    digitalWrite(led75,LOW);
    digitalWrite(led50,HIGH);
    digitalWrite(led25,HIGH);
    digitalWrite(led0,HIGH);
    } 
   else if(request=="25")
   {
    digitalWrite(led100,LOW);
    digitalWrite(led75,LOW);
    digitalWrite(led50,LOW);
    digitalWrite(led25,HIGH);
    digitalWrite(led0,HIGH);
    }
    else if(request=="0")
   {
    digitalWrite(led100,LOW);
    digitalWrite(led75,LOW);
    digitalWrite(led50,LOW);
    digitalWrite(led25,LOW);
    digitalWrite(led0,HIGH);
    }  

  
  
man_mode_read=digitalRead(man_mode);
if(man_mode_read==1)   //Manual mode check
{ Serial.println("  ");
  Serial.println(" Manual Mode ");
  if((supply_read==1)&&(pump_read==1))
  {
    digitalWrite(motor,HIGH);
    Serial.println(" Motor Manually ON ");
    }
  else
  {digitalWrite(motor,LOW);
  Serial.println(" Motor Manually OFF ");}
  }
 else     //Automatic mode
 {
  
  Serial.println("  ");
  Serial.println(" Automatic mode ");
 
  supply_read=digitalRead(supply);
  if((supply_read==1)&&((request=="0")||(request=="25")||(request=="50")||(request=="75")))
  { digitalWrite(motor,HIGH);
    Serial.println(" Motor Auto ON ");
  }
  else if((request=="100")||(supply_read==0))
   { digitalWrite(motor,LOW);
      Serial.println(" Motor Auto OFF ");
 
 }

  
  
  }


  
}
