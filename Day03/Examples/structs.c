#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>
#define MAXCHARS 15


// Definiere einen Datentyp namens "KUNDE"
typedef struct {
	char name[MAXCHARS];
	char adresse[MAXCHARS];
} KUNDE;


// Definiere einen Datentyp namens "KONTO"
// Ein Konto hat eine Nummer (int) und einen Saldo (float)
typedef struct {
	// die fields der struct
	// -> die fields einer C-struct sind public
	int nr;
	float saldo;
	// Ein Konto gehört einem Kunden
	KUNDE kunde;
	// in einer C-struct können keine Funktionen definiert werden
} KONTO;

void printKonto(const KONTO* const konto) {
	// %.2f -> gib nur 2 Nachkommastellen aus
	// Verwende den -> Operator für einen "pointer to struct"
	printf("Nr: %d Saldo %.2f\n", konto->nr, konto->saldo);
	printf("Kunde Name: %s Adresse: %s\n", konto->kunde.name, konto->kunde.adresse);
}

void einzahlen(KONTO* const konto, float betrag) {
	konto->saldo += betrag;
}

void changeName(KONTO* konto) {
	strcpy(konto->kunde.name,"Caspar David Nottebaum");
}

int main() {
	printf("sizeof(KONTO) : %llu\n", sizeof(KONTO));
	// Definiere eine Variable vom Typ KONTO
	KONTO konto1 = { 100,9.99f, {"Hitachi","Ditzingen"}};
	printKonto(&konto1);
	einzahlen(&konto1, 1000);
	printKonto(&konto1);
	changeName(&konto1);
	printKonto(&konto1);
	return 0;
}