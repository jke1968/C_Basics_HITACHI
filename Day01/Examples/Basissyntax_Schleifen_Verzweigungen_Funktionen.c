/*
Demonstriert Datentypen, Variablen, Schleifen, Verzweigungen 
und Funktionen in C
*/
#include <stdio.h>
#include <Windows.h> // für die Funktion Sleep

// Definiere eine Funktion namens demoDatentypen
// diese Funktion gibt nichts zurück (void)
// und hat keine Parameter ()
void demoDatentypen() {
	// Ein char in C ist genau ein byte breit
// unsigned bedeutet: es gibt kein Vorzeichenbit, also nur positive Zahlen
	unsigned char anotherCounter = 0;
	while (1) {
		// interpretiere die char-Variable als Zahl:
		printf("anotherCounter = %d\n", anotherCounter);
		anotherCounter++;
		// Warte 50 Millisekunden
		Sleep(50);
	}
}

// Definition der Funktion  namens "add"
// Rückgabetyp: int
// Parameter 1 : Typ int
// Parameter 2 : Typ int
int add(int number1, int number2) {
	int result = 0;
	result = number1 + number2;
	return result;
	// kürzer:
	// return number1 + number2;
}

void printEvenNumbers(int from, int to) {
	for (int i = from; i <= to; i++) {
		// prüfe, ob i gerade ist
		if (i % 2 == 0) {
			printf("%d\n", i);
		} else {
			printf("odd\n");
		}
	}
}

void checkIfVowel(char c) {
	switch (c) {
	case 'a':
	case 'e':
	case 'i':
	case 'o':
	case 'u':
		printf("lowercase vowel\n");
		break;
	case 'A':
	case 'E':
	case 'I':
	case 'O':
	case 'U':
		printf("uppercase vowel\n");
		break;
	default:
		printf("consonant\n");
		break;
	}
}
int checkRange(int number, int lowerBound, int upperBound) {
	// Beispiel für ein logisches UND/AND
	//if (number >= lowerBound && number <= upperBound) {
	//	// "return true" in C:
	//	return 1;
	//} else {
	//	// "return false" in C:
	//	return 0;
	//}
	// Beispiel für ein logisches OR/ODER
	if (number < lowerBound || number > upperBound) {
		return 0;
	} else {
		return 1;
	}
}
int main() {
	// Definiere eine lokale Variable namens "counter" vom Typ int
	// diese Variable ist nur innerhalb des scopes von main sichtbar
	// Wichtig: im Gegensatz zu Java ist der initiale Wert für int-Variablen
	// nicht definiert, also immer initialisieren
	// int ist der Datentyp für ganze Zahlen
	// int ist ein sog. primitiver Datentyp, genau wie
	// char   -> für ein Zeichen
	// float  -> für Zahlen mit Nachkommastellen
	// double -> wie float, aber mit doppelter Genauigkeit
	// Vorsicht: in C exisitiert kein Datentyp boolean
	// Ein Datentyp legt 2 Dinge fest:
	// 1. Wieviele byte eine Variable im Speicher belegt
	// 2. Wie der Inhalt interpretiert wird (also als ganze Zahl, Kommazahl oder Zeichen)
	int counter = 0;
	char letter = 'A';
	float price = 1.7f;
	// Wiederholungen I : while Schleife
	while (counter < 10) {
		printf("counter = %d letter=%c price=%f\n", counter,letter,price);
		// counter = counter + 1;
		// oder kürzer:
		counter++;
		letter++;
		price++;
	}
	int addend1 = 1;
	int addend2 = 2;
	int sum = 0;
	// Aufruf der Funktion add mit den Argumenten 
	// "addend1" und "addend2"
	// Zuweisung des Rückgabewerts an die Variable sum
	sum = add(addend1, addend2);
	printf("sum = %d\n", sum);
	// rufe die Funktion "printEvenNumbers"
	// mit den Argumenten 1 und 10
	printEvenNumbers(1, 10);
	// Aufruf der Funktin checkIfVowel
	char c = 'A';
	checkIfVowel(c);
	c = 'i';
	checkIfVowel(c);
	c = 'x';
	checkIfVowel(c);
	counter = 17;
	if (checkRange(counter, 0, 10) == 1) {
		printf("counter is in range\n");
	} else {
		printf("counter is not in range\n");
	}
	return 0;
}