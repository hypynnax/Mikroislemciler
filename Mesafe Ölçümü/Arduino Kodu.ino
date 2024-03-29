#include<LiquidCrystal.h>
LiquidCrystal lcd(12, 11,5,4,3,2);
const int pingPin=7;


void setup(){
	Serial.begin(9600);
	lcd.begin(16,2);
	lcd.print("Cisim Uzaklık");
}

void loop(){
	lcd.setCursor(0, 1);
    lcd.print(millis()/10000);
  	long duration, inches, cm;
	pinMode(pingPin, OUTPUT);
	digitalWrite(pingPin, LOW);
	delayMicroseconds(2);
    digitalWrite(pingPin, HIGH);
  	delayMicroseconds(5);
  	digitalWrite(pingPin, LOW);
  	pinMode(pingPin, INPUT);
  	duration = pulseIn(pingPin, HIGH);
  	inches = microsecondsToInches(duration);
  	cm = microsecondsToCentimeters(duration);
  	lcd.print(cm);
  	lcd.print("cm");
  	lcd.println();
	delay(10);
}

long microsecondsToInches(long microseconds) {
	return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
	return microseconds / 29 / 2;
}
