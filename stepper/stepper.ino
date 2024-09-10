#include <Servo.h>

Servo nock_servo;
int degree = 0;

void setup () {
  nock_servo.attach (9);
}

void loop() {
  int data = analogRead (A0) ;
  if(data > 700){
    degree++;
    if (degree > 180) degree = 180; 
    nock_servo.write (degree) ;
  }else if(data < 300) {
    degree--;
    if(degree < 0) degree = 0;
    nock_servo.write (degree) ;
  }
  delay(10) ;
}
