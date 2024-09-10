const int RED = 9;  //빨간색 LED 핀을 9번 핀으로 정의
const int GREEN = 10;  //초록색 LED 핀을 10번 핀으로 정의
const int YELLOW = 11; //노란색 LED 핀을 11번 핀으로 정의
const int BLUE = 12; //파란색 LED 핀을 12번 핀으로 정의


void setup()
{
  //LED 핀을 출력으로 설정
  pinMode(RED, OUTPUT);  
  pinMode(GREEN, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(BLUE, OUTPUT);
}

void loop()
{
  //LED 깜빡이기
  for (int i = 100; i <= 1000; i += 100) {
    digitalWrite(RED, HIGH); 
    digitalWrite(GREEN, HIGH); 
    digitalWrite(YELLOW, HIGH); 
    digitalWrite(BLUE, HIGH); 
    delay(i);
    digitalWrite(RED, LOW); 
    digitalWrite(GREEN, LOW); 
    digitalWrite(YELLOW, LOW);  
    digitalWrite(BLUE, LOW);  
    delay(i);
  }
}

 
