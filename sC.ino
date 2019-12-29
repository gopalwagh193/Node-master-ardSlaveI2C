#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3,POSITIVE);
#include<Wire.h>
void setup() 
{
  Wire.begin(5);
  Wire.onReceive(reciveEvent);
  pinMode(8,OUTPUT);
  digitalWrite(8,LOW);
  lcd.begin(16,2);
}

void loop()
{

}

void reciveEvent(int howMany)
{
  while(Wire.available())
  {
    char c=Wire.read();
    if(c=='H')
    {
      digitalWrite(8,HIGH);
      
    }
    else if(c=='L')
    {
      digitalWrite(8,LOW);
      
    }
  }
}
