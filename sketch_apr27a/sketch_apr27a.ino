#define BUTTON 4
#define BLUE 9 
#define RED 8
#define DELAY 80

int state = 0;

void setup() {
  Serial.begin (9600);
  pinMode(BUTTON, 2);
  pinMode(BLUE, 1);
  pinMode(RED,1);
}

void loop() {
  int buttonValue = !digitalRead(BUTTON);

  if (buttonValue == 1)
{
  state = !state;
  delay(500);
}

if(state == 0)
{
  digitalWrite(BLUE,1);
  digitalWrite(RED, 0);
  delay(DELAY);
  digitalWrite(RED, 1);
  digitalWrite(BLUE, 0);
  delay(DELAY);
}
else if (state == 1)
{
  digitalWrite(BLUE, 0);
  digitalWrite(RED, 0);
}
}
