#include <stdio.h>
// definiere einen neuen Datentyp namens AMPEL
// dieser Datentyp hat genau 3 Werte 
typedef enum { RED, YELLOW, GREEN } AMPEL;
// Array von Stringkonstanten (char*)
char* enum_names[3] = {"Rot","Gelb","Gruen"};
void schalteAmpel(AMPEL* ampel) {
	switch (*ampel) {
	case RED:
		*ampel = GREEN;
		break;
	case YELLOW:
		*ampel = RED;
		break;
	case GREEN:
		*ampel = YELLOW;
		break;
	}
}
void printAmpel(AMPEL ampel) {
	printf("%s", enum_names[ampel]);
}
int main() {
	// setze die Ampel auf rot
    // int ampel1 = 0; <- "magic number"
	// erzeuge eine Variable vom Typ AMPEL
	AMPEL ampel1 = RED;
	schalteAmpel(&ampel1);
	schalteAmpel(&ampel1);
	// printf("ampel1: %d \n", ampel1);
	printf("Size of int: %llu size of int* %llu \n", sizeof(int), sizeof(int*));
	printAmpel(ampel1);
	return 0;
}