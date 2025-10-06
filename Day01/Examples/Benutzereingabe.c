// -> Anweisung für den MS-C-Compiler
// erlaube die Standard Funktion scanf
#pragma warning (disable: 4996)
#include <stdio.h>
// Definiere die Präprozessorkonstante namens MAXCHARS
#define MAXCHARS 10

int main() {

	int number = 0;
	// definiere ein Array namens input für 10 Elemente 
	// vom Typ char -> ein char-Array heisst in C "string"
	char input[MAXCHARS] = {"0"};

	while (1) {
		printf("Bitte geben Sie eine ganze Zahl ein: ");
		// rufe die Funktion scanf auf, um Benutzereingaben zu lesen
		// hier: lies einen int Wert in die Variable "number" ein:
		// & ist der sog. "address-operator", der die Speicheradresse einer
		// Variablen ermittelt
		// Funktioniert nicht, denn eine falsche Eingabeb bleibt im Tastatur-
		// puffer stehen und sorgt dafür, dass scanf das Programm nicht mehr
		// anhält.
		//if (scanf("%d", &number) == 1) {
		//	printf("Ihre Eingabe war: %d\n", number);
		//}
		// 2ter Versuch: lese die Benutzereingabe als C-String
		// (also als char-Array) ein
		// hier kann auf den & Operator verzichtet werden,
		// denn Arrays werden immer als Adresse an Funktionen übergeben
		// %10s bedeutet: lies maximal 10 Zeichen ein
		if (scanf("%10s", input) == 1) {
			printf("Ihre Eingabe war %s\n", input);
			// konvertiere den String in einen int-Wert
			// (vgl. Integer.parseInt in Java)
			if (sscanf(input, "%d", &number) != 1) {
				printf("Bitte nur ganze Zahlen eingeben\n");
			} else {
				// prüfe, ob die Eingabe gerade ist:
				if (number % 2 == 0) {
					printf("%d ist gerade\n",number);
				} else {
					printf("%d ist ungerade\n",number);
				}
			}
		}
	}

}