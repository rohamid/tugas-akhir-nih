#define LDR_1	A0
#define LDR_2	A1
#define LDR_3	A2
#define LDR_4	A3
#define LDR_5	A4

// Arduino			Modul sensor
// ---------        --------
//		A0	| <---- | LDR_1	|
//		A1	| <---- | LDR_2	|
//		A2	| <---- | LDR_3	|
//		A3	| <---- | LDR_4	|
//		A4	| <---- | LDR_5	|
//			|		|		|
//		5V	| <---- | VCC	|
//		GND	| <---- | GND	|
//			|		---------
// ---------

int nilai = 0;

void setup() {
	serial.begin(9600);
}

void loop() {
	nilai = 0;
	// Baca nilai dari LDR 1 per 1
	nilai += analogRead(LDR1);
	nilai += analogRead(LDR2);
	nilai += analogRead(LDR3);
	nilai += analogRead(LDR4);
	nilai += analogRead(LDR5);

	// Hitung rerata dari pembacaan 5 LDR
	nilai = nilai / 5;
	serial.print("Nilai Sensor: ");
	serial.print(nilai);
	serial.print("\n");
	delay_ms(500);
}
