#pragma warning(disable: 4996)
#include <stdio.h>
#include <stdlib.h> // f�r malloc und free

#define MAXELEMENTS 10
void initArray(int* numbers, int noOfElements) {
	int counter = 0;
	while (counter < noOfElements) {
		*numbers = 0;
		numbers++;
		counter++;
	}
}
void printArray(int* numbers, int noOfElements) {
	int counter = 0;
	while (counter < noOfElements) {
		printf("Number at position %d : %d\n", counter, *numbers);
		numbers++;
		counter++;
	}
}
int main() {
	// Herk�mmliche Art und Weise, Speicher f�r ein 
	// Array anzulegen -> die Anzahl der Arrayelemente 
	// liegt zur Compilezeit fest
	int numbers[MAXELEMENTS];
	// Angenommen, die Anzahl der Arrayelemente wird
	// erst zur Laufzeit angegeben:
	int noOfElements = 0;
	int* dynamicArray = NULL;
	printf("Wieviele Zahlen sollen verarbeitet werden?\n");
	if (scanf("%d", &noOfElements) != 1) {
		printf("Bitte nur ganze Zahlen eingeben\n");
	} else {
		// Lege Speicherplatz f�r noOfElements Arrayelemente an:
		// geht nicht:
		// int dynamicArray[noOfElements];
		// also verwende die Funktion malloc
		dynamicArray = malloc(noOfElements*sizeof(int));
		if (dynamicArray == NULL) {
			printf("Speicheranforderung fehlgeschlagen\n");
			return 1;
		} else {
			printf("Speicher f�r %d Elemente erhalten\n",noOfElements);
			// Speicher wurde erfolgreich alloziert:
			initArray(dynamicArray, noOfElements);
			printArray(dynamicArray, noOfElements);
			// Speicher wieder freigeben
			// -> um ein sog. "memory leak" zu vermeiden
			free(dynamicArray);
		}
	}
	return 0;
}