void setup (){
  analogWrite (11, 255);
  pinMode (12, 1);
  pinMode (13, 0) ;
  Serial.begin (9600) ;

}

void loop () {
  digitalWrite (12, 1);
  delay (10);
  digitalWrite (12, 0);
  long t = pulseIn (13, 1);
  long d = (t/2) * 0.034;
  Serial.print (d) ;
  Serial.println ("cm");
}
