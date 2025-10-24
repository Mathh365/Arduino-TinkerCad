const int led = 13;
const int btn = 9;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(btn, INPUT);    
}
//----------------------------------------------------------------
void loop() {
  digitalWrite(led, toggle(btn));
}
//----------------------------------------------------------------
bool toggle(int btn){
  static bool lastBtn = 0, state = 0;
  bool reading = digitalRead(btn);
  
  if (reading && (lastBtn == 0)) state = !state;
  
  lastBtn = reading;
  return state;
}