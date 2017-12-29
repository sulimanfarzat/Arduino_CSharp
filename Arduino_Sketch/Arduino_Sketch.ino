/*
 Name:		Arduino_Sketch.ino
 Created:	29.12.2017 3:51:05 PM
 Author:	s_farzat
*/

int LED1 = 13;
int LED2 = 12;
int LED3 = 11;
int motor = 2;

// the setup function runs once when you press reset or power the board
void setup() {
	// LEDs
	pinMode(LED1, OUTPUT);
	pinMode(LED2, OUTPUT);
	pinMode(LED3, OUTPUT);

	// motor
	Serial.begin(9600);
	pinMode(motor, OUTPUT);

}

// the loop function runs over and over again until power down or reset
void loop() {

	if (Serial.available() > 0)
	{
		int b = Serial.read();
		if (b == 1)
		{
			digitalWrite(motor, HIGH);
			digitalWrite(LED1, HIGH);
			delay(50);
			digitalWrite(LED2, HIGH);
			delay(100);
			digitalWrite(LED3, HIGH);
			delay(150);
		}
		else if (b == 0)
		{
			digitalWrite(motor, LOW);
			digitalWrite(LED1, LOW);
			delay(50);
			digitalWrite(LED2, LOW);
			delay(100);
			digitalWrite(LED3, LOW);
			delay(150);
		}
		else if (b == 2)
		{
			digitalWrite(LED1, HIGH);
			delay(50);
			digitalWrite(LED2, HIGH);
			delay(100);
			digitalWrite(LED3, HIGH);
			delay(150);
			digitalWrite(LED1, LOW);
			delay(50);
			digitalWrite(LED2, LOW);
			delay(100);
			digitalWrite(LED3, LOW);

			delay(150);
			digitalWrite(motor, HIGH);
			delay(50);
			digitalWrite(motor, LOW);
			delay(100);

		}

		Serial.flush();
	}


}
