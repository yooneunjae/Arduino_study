const int BLED=9;
const int GLED=10;
const int RLED=11;
const int TEMP=0;

const int LOWER_BOUND = 155;
const int UPPER_BOUND = 164;

int val = 0;
void setup()
{
  pinMode (BLED, OUTPUT);
  pinMode (GLED, OUTPUT);
  pinMode (RLED, OUTPUT);
}

void loop()
{
  val = analogRead(TEMP);
  if (val < LOWER_BOUND)
  {
    digitalWrite(RLED, HIGH);
    digitalWrite(GLED, HIGH);
    digitalWrite(BLED, LOW);
  }

  else if (val > UPPER_BOUND)
  {
    digitalWrite(RLED, LOW);
    digitalWrite(GLED, HIGH);
    digitalWrite(BLED, HIGH);
  }
  else
  {
    digitalWrite(RLED, HIGH);
    digitalWrite(GLED, LOW);
    digitalWrite(BLED, HIGH);
  }
}
