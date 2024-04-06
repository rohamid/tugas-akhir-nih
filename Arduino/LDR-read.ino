#define LDR_1	A0
#define LDR_2	A1
#define LDR_3	A2
#define LDR_4	A3
#define LDR_5	A4

// Arduino			  Modul sensor
// ---------        ---------
//		  A0	| <---- | LDR_1	|
//		  A1	| <---- | LDR_2	|
//		  A2	| <---- | LDR_3	|
//		  A3	| <---- | LDR_4	|
//		  A4	| <---- | LDR_5	|
//	  		  |		    |		    |
//	  	5V	| <---- | VCC	  |
//		  GND	| <---- | GND	  |
//			    |		    ---------
// ---------

int nilai = 0;

void setup() {
	Serial.begin(9600);
}

void loop() {
	nilai = 0;
	// Baca nilai dari LDR 1 per 1
	nilai += analogRead(LDR_1);
	nilai += analogRead(LDR_2);
	nilai += analogRead(LDR_3);
	nilai += analogRead(LDR_4);
	nilai += analogRead(LDR_5);

	// Hitung rerata dari pembacaan 5 LDR
	nilai = nilai / 5;
	Serial.print("Nilai Sensor: ");
	Serial.print(nilai);
	Serial.print("\n");
	delay(500);
}