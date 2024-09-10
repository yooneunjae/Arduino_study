#include <TM1637TinyDisplay.h>

#define CLK 2
#define DIO 3
#define BUTTON_PIN  6
#define VR_PIN  A0
#define BUZZER_PIN  7
#define RED_CABLE 10
#define YELLOW_CABLE 9
#define BLUE_CABLE 8

TM1637TinyDisplay display(CLK, DIO); // display 객체를 생성하도록 수정

unsigned long currTime = 0;
unsigned long prevTime = 0;

int runState = 0;
int timerCnt;

String strArray[] = {"bomb", "nothing", "stop"};

void setup() {
  display.setBrightness(0x0f);
  display.clear();
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(BUZZER_PIN, OUTPUT); // BUTTON_PIN의 pinMode이 두 번 지정되었던 것을 수정
  pinMode(RED_CABLE, INPUT_PULLUP);
  pinMode(YELLOW_CABLE, INPUT_PULLUP);
  pinMode(BLUE_CABLE, INPUT_PULLUP);

  randomSeed(analogRead(1));
  for(int i = 0; i < 3; i++){
    int n = random(0, 3); // 인덱스 범위 수정
    String temp = strArray[n];
    strArray[n] = strArray[i];
    strArray[i] = temp;
  }
  Serial.print(strArray[0]);
  Serial.print(",");
  Serial.print(strArray[1]);
  Serial.print(",");
  Serial.print(strArray[2]);
}

void loop() {
  if(runState == 0){
    int aValue = analogRead(VR_PIN); // 변수 이름 오타 수정
    timerCnt = map(aValue, 0, 1023, 0, 9999); // timeCnt -> timerCnt 수정
    display.showNumberDec(timerCnt, true); // dispaly -> display 수정
    if(digitalRead(BUTTON_PIN) == LOW){ // 버튼이 눌렸을 때 LOW로 체크
      runState = 1;
    }
    delay(100);
  }
  else if (runState == 1){
    currTime = millis();
    if(currTime - prevTime >= 100){
      prevTime = currTime;
      display.showNumberDec(timerCnt, true);
      if(timerCnt == 0){
        while (1) digitalWrite(BUZZER_PIN, HIGH);
      }
      else timerCnt--;
    }
    String result = " ";
    if(digitalRead(RED_CABLE) == HIGH ) result = strArray[0]; // HIGH로 체크
    else if (digitalRead(YELLOW_CABLE) == HIGH) result = strArray[1]; // HIGH로 체크
    else if (digitalRead(BLUE_CABLE) == HIGH) result = strArray[2]; // HIGH로 체크

    if(result.indexOf("bomb") >= 0)
    {
      Serial.println("bomb");
      while (1) digitalWrite(BUZZER_PIN, HIGH);
    }
    else if (result.indexOf("stop") >= 0)
    {
      Serial.println("stop");
      while (1) digitalWrite(BUZZER_PIN, LOW);
    }
    else if (result.indexOf("nothing") >= 0)
    {
      Serial.println("nothing");
    }
  }
}
