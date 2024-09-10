const int EN = 9;
const int MC1 = 3;
const int MC2 = 2;
const int POT = 0;

const int RED_LED = 10;     // 빨간색 LED 핀 번호
const int YELLOW_LED = 11;  // 노란색 LED 핀 번호
const int BLUE_LED = 12;    // 파란색 LED 핀 번호

int val = 0;
int velocity = 0;

void setup() {
  pinMode(EN, OUTPUT);
  pinMode(MC1, OUTPUT);
  pinMode(MC2, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  
  brake(); // 초기 상태에서 정지
}

void loop() {
  val = analogRead(POT);

  if (val > 562) {
    velocity = map(val, 563, 1023, 0, 255);
    forward(velocity); // 시계방향 회전
  } 
  else if (val < 462) {
    velocity = map(val, 461, 0, 0, 255);
    reverse(velocity); // 반시계방향 회전
  } 
  else {
    brake(); // 정지
  }
}

void forward(int rate) {
  digitalWrite(EN, LOW);
  digitalWrite(MC1, HIGH);
  digitalWrite(MC2, LOW);
  analogWrite(EN, rate);

  digitalWrite(RED_LED, HIGH);     // 빨간색 LED 켜기 (시계방향)
  digitalWrite(YELLOW_LED, LOW);   // 노란색 LED 끄기 (정지 상태 아님)
  digitalWrite(BLUE_LED, LOW);     // 파란색 LED 끄기 (반시계방향 아님)
}

void reverse(int rate) {
  digitalWrite(EN, LOW);
  digitalWrite(MC1, LOW);
  digitalWrite(MC2, HIGH);
  analogWrite(EN, rate);

  digitalWrite(RED_LED, LOW);      // 빨간색 LED 끄기 (시계방향 아님)
  digitalWrite(YELLOW_LED, LOW);   // 노란색 LED 끄기 (정지 상태 아님)
  digitalWrite(BLUE_LED, HIGH);    // 파란색 LED 켜기 (반시계방향)
}

void brake() {
  digitalWrite(EN, LOW);
  digitalWrite(MC1, LOW);
  digitalWrite(MC2, LOW);
  digitalWrite(EN, HIGH);

  digitalWrite(RED_LED, LOW);      // 빨간색 LED 끄기
  digitalWrite(BLUE_LED, LOW);     // 파란색 LED 끄기
  digitalWrite(YELLOW_LED, HIGH);  // 노란색 LED 켜기 (정지 상태)
}
