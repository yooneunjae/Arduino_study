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

void setup() {
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
}

void setMode(int mode) {
  // 모든 LED를 끄기
  analogWrite(RLED, 255);
  analogWrite(GLED, 255);
  analogWrite(BLED, 255);

  if (mode == 0) {
    // 꺼짐 (모든 LED를 HIGH로 설정하여 끄기)
    analogWrite(RLED, 255);
    analogWrite(GLED, 255);
    analogWrite(BLED, 255);
  } else if (mode == 1) {
    // 빨간색
    analogWrite(RLED, 0);
    analogWrite(GLED, 255);
    analogWrite(BLED, 255);
  } else if (mode == 2) {
    // 주황색
    analogWrite(RLED, 127);
    analogWrite(GLED, 127);
    analogWrite(BLED, 255);
  } else if (mode == 3) {
    // 흰색
    analogWrite(RLED, 85);
    analogWrite(GLED, 85);
    analogWrite(BLED, 85);
  } else if (mode == 4) {
    // 초록색
    analogWrite(RLED, 255);
    analogWrite(GLED, 0);
    analogWrite(BLED, 255);
  } else if (mode == 5) {
    // 청록색
    analogWrite(RLED, 255);
    analogWrite(GLED, 127);
    analogWrite(BLED, 127);
  } else if (mode == 6) {
    // 파란색
    analogWrite(RLED, 255);
    analogWrite(GLED, 255);
    analogWrite(BLED, 0);
  } else if (mode == 7) {
    // 보라색
    analogWrite(RLED, 127);
    analogWrite(GLED, 255);
    analogWrite(BLED, 127);
  }
}

void loop() {
  if (digitalRead(BUTTON1) == LOW) {
    tone(PIEZO_BUZZER, 261.6);
    setMode(1); // Red
  } else if (digitalRead(BUTTON2) == LOW) {
    tone(PIEZO_BUZZER, 293.6);
    setMode(2); // Orange
  } else if (digitalRead(BUTTON3) == LOW) {
    tone(PIEZO_BUZZER, 329.6);
    setMode(3); // White
  } else if (digitalRead(BUTTON4) == LOW) {
    tone(PIEZO_BUZZER, 349.2);
    setMode(4); // Green
  } else if (digitalRead(BUTTON5) == LOW) {
    tone(PIEZO_BUZZER, 391.9);
    setMode(5); // Cyan
  } else if (digitalRead(BUTTON6) == LOW) {
    tone(PIEZO_BUZZER, 440.0);
    setMode(6); // Blue
  } else if (digitalRead(BUTTON7) == LOW) {
    tone(PIEZO_BUZZER, 493.8);
    setMode(7); // Violet
  } else {
    noTone(PIEZO_BUZZER);
    setMode(0); // Turn off RGB LED
  }
}
