const int LED1 = 9; // 첫 번째 LED 핀 번호
const int LED2 = 10; // 두 번째 LED 핀 번호

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
}

void loop() {
  // 밝기가 동시에 변화하도록 for 루프 수정
  for (int i = 0; i <= 255; i++) {
    analogWrite(LED1, i); // LED1 밝기 증가
    analogWrite(LED2, 255 - i); // LED2 밝기 감소
    delay(30);
  }
  for (int i = 255; i >= 0; i--) {
    analogWrite(LED1, i); // LED1 밝기 감소
    analogWrite(LED2, 255 - i); // LED2 밝기 증가
    delay(30);
  }
}
