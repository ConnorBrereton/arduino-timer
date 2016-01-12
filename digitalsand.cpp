const int switchPin = 8; // tilt const on
unsigned long previousTime = 0;
int switchState = 0;
int prevswitchState = 0;
int led = 2; // sand fills up
long interval = 300000; // 5 minute timer
void setup() 
{
  for(int x = 2; x<8; x++)
  {
    pinMode(x, OUTPUT);
  }
  pinMode(switchPin, INPUT); // tilt sensor input
}

void loop()
{
  unsigned long currentTime = millis();
  if(currentTime - previousTime > interval)
  {
    previousTime = currentTime;
    digitalWrite(led, HIGH);
    led++;  
    if(led == 7)
    {
    // null f.n.
    }
  }  
  switchState = digitalRead(switchPin);
  if(switchState != prevswitchState)
  {
    for(int x = 2; x<8; x++)
    {
      digitalWrite(x, LOW);
    }
    led = 2;
    previousTime = currentTime;
   }
   prevswitchState = switchState;
}
