const int LED = 9;
const int BUTTON = 2;
boolean lastButton = LOW;
boolean currentButton = LOW;
boolean led0n = false;

void setup()
{
  pinMode (LED, OUTPUT);
  pinMode (BUTTON, INPUT);
}

boolean debounce(boolean last)
{
  boolean current = digitalRead(BUTTON);
  if (last != current)
  {
    delay(5);
    current = digitalRead(BUTTON);
  }
  return current;
}

void loop()
{
  currentButton = debounce(lastButton);
  if (lastButton == LOW&& currentButton == HIGH)
  {
    led0n=!led0n;
  }
  lastButton = currentButton;
  digitalWrite(LED, led0n);
}
