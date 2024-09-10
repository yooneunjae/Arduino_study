#include "DHT.h" 
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

#define DHTPIN 3

#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

LiquidCrystal_I2C lcd (0x27, 20, 4);

void setup () {
  Serial. begin (9600);
  dht.begin (); lcd.init ();
  lcd.backlight () ;
}
void loop (){
  float humi = dht.readHumidity ();
  float temp = dht. readTemperature () ;
  
  Serial.print (temp); Serial.print ("C");
  Serial.print ("      ");
  Serial.print (humi); Serial.println ("%");
  
  lcd.clear () ;
  lcd. setCursor (0, 0); 
  lcd.print ("TEMP:");
  lcd.print (temp); 
  lcd. setCursor (0, 1); 
  lcd.print ("HUMI: ");
  lcd.print (humi);
  
  delay (1500);
}
