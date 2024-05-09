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

/* Struktur low pass filter */
typedef struct lpf_config_t {
	float value;
	float valueNew;
	float valueOld;
	float factor;
}lpf_config_t;

lpf_config_t filterLDR;


int nilai = 0;	// variable ini menyimpan nilai sebelum low-pass-filter
int nilaiTerfilter = 0;	// variable ini menyimpan nilai setelah low-pass-filter

void setup() {
	Serial.begin(9600);
	// Lakukan inisialisasi filter.
	lpf_init(&filterLDR, .02);
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
	nilaiTerfilter = (int)lpf_get_filter(&filterLDR, nilai);
  	Serial.print("Sensor:");
  	Serial.print(nilai);
  	Serial.print(",");
  	Serial.print("Filter:");
  	Serial.print(nilaiTerfilter);
  	Serial.print("\n");

  	delay(100);
}

/* @fn: lpf_init
 * @brief: Inisialisasi low pass filter. 
 * @param: lpf 				: pointer ke struct lpf_config_t
 * @param: filter_factor 	: faktor filterisasi (sesuaikan faktor dengan perubahan nilai setelah difilter.) 
 * @return: None
 * @note:
 */
void lpf_init(lpf_config_t *lpf, float filter_factor) {
	lpf->value = lpf->valueNew = lpf->valueOld = 0.0;
	lpf->factor = filter_factor;
}

/* @fn: lpf_get_filter
 * @brief: Filter sinyal input dan dapatkan sinyal terfilter dari return. 
 * @param: lpf 		: pointer ke struct lpf_config_t
 * @param: input 	: sinyal yang akan di filter
 * @return: nilai setelah di filter
 * @note:
 */
float lpf_get_filter(lpf_config_t *lpf, float input) {
	lpf->value = input;
	lpf->valueNew = ((1.0 - lpf->factor) * lpf->valueOld) + (lpf->factor * lpf->value);
	lpf->valueOld = lpf->valueNew;

	return (lpf->valueNew);
}