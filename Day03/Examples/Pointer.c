#include <stdio.h>

// teile teilt zaehler durch nenner
// Rückabegwert = 1 -> Ergebnis liegt vor
// Rückabegwert = 0 -> kein Ergebnis
// int* bedeutet : Adresse einer int-Variablen
//               : pointer to int / "int star"
// Es existieren 3 Schreibweisen für "pointer to int"
// int* ergebnis
// int * ergebnis
// int *ergebnis

int teile(int zaehler, int nenner, int* ergebnis) {
	if (nenner != 0) {
		// *ergebnis liefert den Wert an der Speicherstelle,
		// die im Parameter "ergebnis" steht
		*ergebnis = zaehler / nenner;
		return 1;
	} else {
		// ?
		return 0;
	}
}
void pointerDemo() {
	int n1 = 111; // der Wert dieser Variablen ist die Zahl 111
	int n2 = 222;
	int* pointerToInt = 0; // der Wert dieser Variablen ist die Speicheradresse 0
	int* otherPointerToInt = 0;
	// lasse pointerToInt auf die Adresse der Variablen "number" zeigen:
	pointerToInt = &n1;
	otherPointerToInt = &n2;
	printf("&n1 = %p *pointerToInt = %d pointerToInt= %p\n",&n1, *pointerToInt, pointerToInt);
	printf("&n2 = %p *otherPointerToInt = %d otherPointerToInt= %p\n",&n2, *otherPointerToInt, otherPointerToInt);
}
int main() {
	int zaehler = 4;
	int nenner = 2;
	int ergebnis = 0;
	int ergebnisLiegtVor = 0;
	// Übergebe die lokale Variable "ergebnis" als Adresse
	ergebnisLiegtVor = teile(zaehler, nenner, &ergebnis);
	if (ergebnisLiegtVor) {
		printf("ergebnis = %d\n", ergebnis);
	} else {
		printf("Kein Ergebnis vorhanden\n");
	}
	pointerDemo();
	return 0;
}