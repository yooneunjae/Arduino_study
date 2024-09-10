const int LED =9; //LED 핀을 9번으로 정의

void setup()
{
  pinMode(LED, OUTPUT); //LED 핀을 출력으로 설정
  digitalWrite(LED, HIGH); //LED 핀을 HIGH로 설정, LED 켜기 
}

void loop()
{
  //loop 함수에서는 아무 작업도 하지 않는다.
}


//외부에서 데이터 받아올때 input 외부로 데이터 보낼때 output
