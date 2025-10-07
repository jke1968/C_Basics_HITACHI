#include <stdio.h>

#define MAXNUMBERS 5

// sichtbar für alle Funktionen
int globalScalar = 100;

void printArray(int numbers[]) {
	for (int i = 0; i < MAXNUMBERS; i++) {
		// lese die Array-Elemente
		printf("%d\n", numbers[i]);
	}
}
void modifyArray(int numbers[]) {
	// im Gegensatz zu skalaren Variablen,
	// werden Arrays bei der Übergabe an eine Funktion
	// nicht kopiert, sondern es wird die Speicheradresse
	// des Originals übergeben.
	for (int i = 0; i < MAXNUMBERS; i++) {
		// schreibe in die Array-Elemente
		numbers[i] = i + 100;
	}
}
void modifyScalar(int scalar) {
	// der Parameter scalar ist eine Kopie
	// der lokalen Variablen scalar in main
	scalar++;
	printf("in function modifyScalar: %d\n", scalar);
}
void modifyGlobalScalar() {
	globalScalar++;
	printf("in function modifyGlobalScalar: %d\n", globalScalar);
}
int main() {
	int scalar = 100;
	// Definiere ein Array namens "numbers"
	// für 5 Elemente vom Typ int
	int numbers[MAXNUMBERS] = {0,0,0,0,0};
	printArray(numbers);
	modifyArray(numbers);
	printArray(numbers);
	modifyScalar(scalar);
	printf("in function main, after call of function modifyScalar: %d\n", scalar);
	modifyGlobalScalar();
	printf("in function main, after call of function modifyGlobalScalar: %d\n", globalScalar);
	return 0;
}