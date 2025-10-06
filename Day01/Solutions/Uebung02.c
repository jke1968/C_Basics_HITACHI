#include <stdio.h>

float berechneIdealgewicht(char geschlecht, int koerpergroesse) {
	int normalgewicht = koerpergroesse-100;
	float idealgewicht = 0;
	switch (geschlecht) {
	case 'm':
		idealgewicht = (float)normalgewicht;
		break;
	case 'f':
		idealgewicht = (float)normalgewicht * 0.8f;
		break;
	default:
		// eigentlich existiert kein Rückgabewert
		// hilfsweise: Rückgabe 0
		idealgewicht = 0;
		break;
	}
	return idealgewicht;
}

int main() {

	int koerpergroesse = 196;
	char geschlecht = 'm';
	float idealgewicht = berechneIdealgewicht(geschlecht, koerpergroesse);
	printf("Idealgewicht: %f\n", berechneIdealgewicht(geschlecht, koerpergroesse));

	return 0;
}