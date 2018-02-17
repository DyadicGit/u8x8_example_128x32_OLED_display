const int action1_interval = 100;  //<-- set time to read the value every (in mili seconds)
unsigned long int action1_previousMillis = 0;
unsigned long int currentMillis = 0;
bool isActionNr1Tine(unsigned long int currentMillis);

void setup() {
}
void loop() {
  currentMillis = millis();
  
  otherFunctionsNotInDelay();
  if (isActionNr1Tine(currentMillis)) {
	  ... do your thing
  }
}

//time calculation functions
bool isActionNr1Tine(unsigned long int currentMillis) {
  bool result = currentMillis - action1_previousMillis >= action1_interval;
  if (result) {action1_previousMillis = currentMillis;}
  return result;
}

//////////////// or a universal delay method /////////////////////
unsigned long int currentMillis = 0;
unsigned long int delayByMillisPreviouse = 0;

void setup() {
}
void loop() {
	currentMillis = millis();
	  
	otherFunctionsNotInDelay();
	while ("some condition") {
	  if (isDelayTime(1000)) {
		  "do something every 1000ms"
	  }
	}
	delayByMillisPreviouse = 0;   //just reset it
	if (isDelayTime(5000)) {
	  "do something every 5000ms"
	}
}
bool isDelayTime(unsigned long int delayByMillis) {
  currentMillis = millis();
  bool result = (currentMillis - delayByMillisPreviouse >= delayByMillis) || (currentMillis < delayByMillis);
  if (result) {delayByMillisPreviouse = currentMillis;}
  return result;
}