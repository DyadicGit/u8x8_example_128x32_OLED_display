void handleLCDInterrupt();
void setup() {
  pinMode(buttonLCDPin, INPUT);  //LCD on/off momentary button
  attachInterrupt(digitalPinToInterrupt(buttonLCDPin), handleLCDInterrupt, CHANGE);
}
void loop() {
	if (LCDState) {
		... do your thing
	} 
}

void toggleStateLCD() {
  LCDState = !LCDState;
}
void handleLCDInterrupt() {
  static unsigned long last_interrupt_time = 0;
  unsigned long interrupt_time = millis();
  // If button press come faster than 50ms, assume it's a bounce and ignore
  if (interrupt_time - last_interrupt_time > 50)
    {
      toggleStateLCD(); //... do your interrupt thing
    }
  last_interrupt_time = interrupt_time;
}