#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define PIEZO_BUZZER 3
#define BUTTON1 13
#define BUTTON2 12
#define BUTTON3 11
#define BUTTON4 10
#define BUTTON5 9
#define BUTTON6 8
#define BUTTON7 7

#define RLED 6
#define GLED 5
#define BLED 4

#define MIC A0
#define LED 2

signed int soundAvg=0;

int ledState=0;

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup(){
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Welcome to 2024");
  lcd.setCursor(1,1);
  lcd.print("Piano Contest!");
  
  pinMode(BUTTON1, INPUT_PULLUP);
  pinMode(BUTTON2, INPUT_PULLUP);
  pinMode(BUTTON3, INPUT_PULLUP);
  pinMode(BUTTON4, INPUT_PULLUP);
  pinMode(BUTTON5, INPUT_PULLUP);
  pinMode(BUTTON6, INPUT_PULLUP);
  pinMode(BUTTON7, INPUT_PULLUP);
  
  pinMode(RLED, OUTPUT);
  pinMode(GLED, OUTPUT);
  pinMode(BLED, OUTPUT);
  setMode(0);
  
  Serial.begin(9600);
  int i;
  for (i=0;i<10;i++){
    soundAvg+=analogRead(MIC);
  }
  soundAvg=soundAvg/10;
  pinMode(LED, OUTPUT);
}

 void setMode(int mode) {
  if (mode == 0) { //꺼짐
    digitalWrite(RLED, HIGH);
    digitalWrite(GLED, HIGH);
    digitalWrite(BLED, HIGH);
  }
  else if (mode == 1) { //빨간색
    digitalWrite(RLED, LOW);
    digitalWrite(GLED, HIGH);
    digitalWrite(BLED, HIGH);
  }
  else if (mode == 2) {  //주황색
    analogWrite(RLED, 0);
    analogWrite(GLED, 200);
    analogWrite(BLED, 255);
  }
  else if (mode == 3) { //노란색
    analogWrite(RLED, 0);
    analogWrite(GLED, 0);
    analogWrite(BLED, 255);
  }
  else if (mode == 4) {  //초록색
    digitalWrite(RLED, HIGH);
    digitalWrite(GLED, LOW);
    digitalWrite(BLED, HIGH);
  }
  else if (mode == 5) {  //파란색
    analogWrite(RLED, 255);
    analogWrite(GLED, 70);
    analogWrite(BLED, 50);
  }
  else if (mode == 6) { //남색
    digitalWrite(RLED, HIGH);
    digitalWrite(GLED, HIGH);
    digitalWrite(BLED, LOW);
  }
  else if (mode == 7) { //보라색
    analogWrite(RLED, 127);
    analogWrite(GLED, 255);
    analogWrite(BLED, 127);
  }
 }
  
void loop(){
  if(digitalRead(BUTTON1) == 0) {
    tone(PIEZO_BUZZER, 261.6);
    setMode(1); //빨간색
  }
  else if(digitalRead(BUTTON2) == 0) {
    tone(PIEZO_BUZZER, 293.6);
    setMode(2); //주황색
  }
  else if(digitalRead(BUTTON3) == 0) {
    tone(PIEZO_BUZZER, 329.6);
    setMode(3); //노란색
  }
  else if(digitalRead(BUTTON4) == 0) {
    tone(PIEZO_BUZZER, 349.2);
    setMode(4); //초록색
  }
  else if(digitalRead(BUTTON5) == 0) {
    tone(PIEZO_BUZZER, 391.9);
    setMode(5); //파란색
  }
  else if(digitalRead(BUTTON6) == 0) {
    tone(PIEZO_BUZZER, 440.0);
    setMode(6); //남색
  }
  else if(digitalRead(BUTTON7) == 0) {
    tone(PIEZO_BUZZER, 493.8);
    setMode(7); //보라색
  }
  else {
    noTone(PIEZO_BUZZER);
    setMode(0); // RGB LED 끄기
  }
  int micValue = analogRead(MIC);
  if (micValue - soundAvg >=70)
  {
       Serial.println(micValue);
       ledState=!ledState;
       digitalWrite(LED,ledState);
       delay(100);
  }
}

 
