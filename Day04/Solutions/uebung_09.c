#pragma warning(disable: 4996)
#include <stdio.h>
#include <string.h>
#include <Windows.h>
#define MAXCHARS 10
int main(int argc, char** argv) {
	float zahl1 = 0;
	float zahl2 = 0;
	int falscheEingabe = 0;
	float ergebnis = 0;
	do {
		if (argc != 4) {
			printf("Falsche Anzahl Parameter: %d\n", argc);
			break;
		}
		if (sscanf(argv[1], "%f", &zahl1) != 1) {
			printf("zahl1 %s konnte nicht in eine Zahl konvertiert werden\n", argv[1]);
			break;
		}
		if (sscanf(argv[3], "%f", &zahl2) != 1) {
			printf("zahl2 %s konnte nicht in eine Zahl konvertiert werden\n", argv[3]);
			break;
		}
		switch (argv[2][0]) {
		case '+':
			ergebnis = zahl1 + zahl2;
			break;
		case '-':
			ergebnis = zahl1 - zahl2;
			break;
		case '*':
			ergebnis = zahl1 * zahl2;
			break;
		case '/':
			if (zahl2 != 0) {
				ergebnis = zahl1 / zahl2;
			} else {
				printf("Teilen durch 0 nicht moeglich\n");
				return 0;
			}
			break;
		default:
			printf("Unbekanntes Rechenzeichen: %c\n", argv[2][0]);
			falscheEingabe = 1;
			break;
		}
		if (!falscheEingabe) {
			printf("Ergebnis: %f\n", ergebnis);
			break;
		}
	} while (1);
	return 0;
}