#include <stdio.h>
#include <stdlib.h> // f. srand und rand
#include <time.h>   // f. time

int main() {
	// "seed random number"
	// Startwert für die rand()-Funktion generieren
	// verwende die "aktuelle Uhrzeit" als Startwert für die Zufallszahlen
	srand(time(NULL));
	int zufall = 0;
	for (int i = 0; i < 10; i++) {
		// Erzeuge Zufallszahlen zwischen 1 und 6
		zufall = rand() % 6 + 1;
		printf("%d ", zufall);
	}
	printf("\n");
	return 0;
}