#pragma warning (disable: 4996)
#include <stdio.h>
#include <stdlib.h>
#define MAXCHARS 20
int main() {
	char input[MAXCHARS + 1] = {0};
	int number = 0;
	while (1) {
		printf("Bitte eine ganze Zahl eingeben: ");
		// um den input buffer immer vollständig zu leeren,
		// wird die Eingabe zunächst in einem String gespeichert
		if (scanf("%20s", input) != 1) {
			printf("Eingabe ist fehlgeschlagen\n");
		} else {
			printf("Ihre Eingabe war: %s\n", input);
			// Eingabe war fehlerfrei, konvertiere jetzt den string in eine Zahl
			if (sscanf(input, "%d", &number) != 1) {
				printf("Konvertierung von char[] nach int fehlgeschlagen\n");
			} else {
				printf("number = %d number + 1 = %d\n", number, number + 1);
			}
		}
	}
	return 0;
}