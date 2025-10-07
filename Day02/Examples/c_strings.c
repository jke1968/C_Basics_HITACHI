#pragma warning (disable: 4996) // um strcpy mit dem MS C-Compiler zu verwenden
#include <stdio.h>
#include <string.h> // für die Funktionen strlen, strcpy, strcmp etc...
#define MAXCHARS 10
int main() {
	// ein char belegt in C garantiert genau 1 byte 
	char name[MAXCHARS];
	// schreibe in die Array-Elemente
	name[0] = 'T';
	name[1] = 'i';
	name[2] = 'm';
	name[3] = 0; // binäre 0 oder auch null-Terminator
	             // -> kennzeichnet das Ende eines C-Strings
	// erste Besonderheit der char-Arrays
	// -> Ausgabe per printf ist möglich
	// -> keine Schleife nötig
	printf("%s\n", name);
	// weitere Besonderheiten der char-Arrrays:
	// Hilfsfunktionen der C-Standard-Bibliothek
	// #1 Bestimme die Länge eines Strings: strlen
	// size_t ist ein Alias-Name für den Datentyp "unsigned long long"
	size_t  laenge = strlen(name);
	printf("Der String %s hat die Laenge: %llu\n", name, laenge);
	// #2 Kopiere einen String in einen anderen String
	char otherName[MAXCHARS] = { "Dennis" }; // hier wird am Ende der 
	                                         // Null-Terminator eingefügt
	printf("vor srtcpy  -> otherName =  %s name = %s \n", otherName, name);
	strcpy(otherName, name);
	printf("nach strcpy -> otherName =  %s name = %s \n", otherName, name);
	// ACHTUNG: wenn das Zielarray kleiner ist als das Quellarray,
	// dann wird der Speicher nach dem Zielarray evtl. überschrieben
	strcpy(otherName, "Lara Sophie");
	printf("nach erneutem strcpy -> otherName =  %s\n", otherName);
	// #3 Vergleiche zwei Strings : strcmp
	strcpy(name, "Dennis");
	strcpy(otherName, "Dragos");
	int result = strcmp(name, otherName);
	if ( result == 0) {
		printf("%s und %s sind gleich\n", name, otherName);
	} else {
		if (result < 0) {
			printf("%s ist kleiner als %s \n", name, otherName);
		} else {
			printf("%s ist groesser als %s \n", name, otherName);
		}
	}


	return 0;
}