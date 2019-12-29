#include<Wire.h>
#define BLYNK_PRINT Serial
#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3,POSITIVE);
int a;
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
char auth[] = "9f1accc018f94d14a3fefb797e02ab98";

char ssid[] = "note4";
char pass[] = "123456788";

void setup()
{
  Wire.begin();
  lcd.begin(16,2);
  Serial.begin(9600);
  pinMode(D4,INPUT);
  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  Blynk.run();
   a=digitalRead(D4);
  if(a==1)
  {
    Blynk.virtualWrite(V0,"Please be allert!!!");
    Wire.beginTransmission(5);
    Wire.write('H');
    Wire.endTransmission();
    
  }
  else
  {
    Blynk.virtualWrite(V0,"Everything all right");
    Wire.beginTransmission(5);
    Wire.write('L');
    Wire.endTransmission();
     
  
 
    }
Serial.print(a);
}
