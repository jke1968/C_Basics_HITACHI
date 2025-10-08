#include <stdio.h>

#define MAXCHARS 10

// Erinnerung: Arrays werden an Funktionen 
// als Adresse übergeben, genauer als Adresse
// des ersten Elements
void printArray_V1(char name[]) {
	for (int i = 0; i < MAXCHARS; i++) {
		printf("%c\n",name[i]);
	}
}
// "selbstgebaute printf Funktion"
// diese Funktion akzeptiert einen Pointer
// und garantiert, dass das Original-Array nicht
// geändert wird
void printArray_V2(const char* const name) {
	char* localPointer = name;
	// Gib alle Zeichen bis zum Null-Terminator aus
	// Geht nichtm denn name ist char* const ("const - Pointer")
	// name = 1234567;
	while (*localPointer != 0) {
		// geht nicht, denn name ist const char* ("pointer to const")
		// *name = 'X';
		// *name -> dereferenziert den Pointer name
		printf("%c\n", *name);
		localPointer++; // ++ für pointer: 
		// -> setze den Pointer auf die nächste Stelle in einem Array
	}
}
// Gibt den Speicherinhalt ab einer bestimmten Adresse
// in folgender Form aus:
// Adresse Wert Wert interpretiert gemäss ASCII-Tabelle 
void printMemoryBlock(char* pointer) {
	while (*pointer != 0) {
		printf("%p %03d %c\n", pointer, *pointer, *pointer);
		pointer++;
	}
}
int main() {
	// Dieses Array steht als 10 aufeinanderfolgende bytes
	// im Speicher
	char name[MAXCHARS] = { "Ayoub" };
	printArray_V1(name);
	printArray_V2(name);
	printMemoryBlock(name);
	return 0;
}