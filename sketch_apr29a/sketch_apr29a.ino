#include <TM1637Display.h>

#define CLK 2
#define DIO 3
#define BUTTON_PIN    6
#define VR_PIN        A0
#define BUZZER_PIN    7
#define RED_CABLE     10
#define YELLON_CABLE  9
#define BLUE_CABLE    8

TM1637Display display(CLK, DIO);

unsigned long currTime = 0;
unsigned long prevTime = 0;

int runState = 0;
int timeCnt;

String strArray[] = {"bomb", "nothing", "stop"};

void setup()
{
  display.setBrightness(0x0f);
  display.clear();
  Serial. begin (9600);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW);
  pinMode(RED_CABLE, INPUT_PULLUP);
  pinMode(YELLOW_CABLE, INPUT_PULLUP);
  pinMode(BLUE_CABLE, INPUT_PULLUP);
  
  randomSeed (analogRead (1)) ;
  for (int i = 0; i < 3; i++) {
    int n = random(0, 2);
    String temp = strArray[n];
    strArray[n] = strArray[i];
    strArray [i] = temp;
  }
  Serial-print(strArray[0]);
  Serial.print(", ");
  Serial.print(strArray(1]);
  Serial.print(",");
  Serial-println(strArray[2]);
}
void loop()
{
  if (runState = 0)
  {
    int aValue = analogRead( VR_PIN );
    timerCnt = map(aValue, 0, 1023, 0, 9999);
    display.showNumberDec(timerCnt, true);
    if (digitalRead(BUTTON_PIN) == 0)
    {
      runState = 1;
    }
    delay (100);
  }
  else if (runState == 1)
  {
    currTime - millis();
    if (currTime - prevTime >= 100)
    {
      prevTime - currTime;
      display.showNumberDec(timerCnt, true);
      if (timerCnt == 0)
      {
        while (1) digitalWrite(BUZZER_PIN, HIGH);
      }
      else timeCnt--;
    }
  }
void setup(){
  display.setBrightness(0x0f); 
  display.clear();
  Serial.begin (9600);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(BUZZER_PIN, OUTPUT) ;
  digitalWrite(BUZZER_PIN, LOW);
  pinMode(RED_CABLE, INPUT_ PULLUP);
  pinMode(YELLOW_CABLE, INPUT_PULLUP);
  pinMode(BLUE_CABLE, INPUT_PULLUP);
  
  randomSeed (analogRead (1)) ;
  for (int i = 0; i < 3; i++) {
    int n = random(0, 2) ;
    String temp = strArray[n];
    strArray[n] = strArray[i];
    strArray [i] = temp;
  }
  Serial.print(strArray[0]);
  Serial.print(",");
  Serial.print(strArray[1]);
  Serial.print(",");
  Serial.printin(strArray[2]);
  }



}
