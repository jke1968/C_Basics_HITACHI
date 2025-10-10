#pragma warning(disable: 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <float.h>
#include <ctype.h>
#define MAXARTIKEL 10
#define MAXCHARS 40
#define MAXZEILE 100

int anzahlArtikel = 0;
char* categoryNames[] = { "FOOD","NONFOOD" };
typedef enum { FOOD, NONFOOD } ARTIKELKATEGORIE;
typedef struct {
	int nr;
	char name[MAXCHARS];
	float preis;
	ARTIKELKATEGORIE kategorie;
} ARTIKEL;

ARTIKELKATEGORIE leseKategorie() {
	ARTIKELKATEGORIE kategorie = 0;
	int inputOK;
	char input[MAXCHARS] = "";
	do {
		inputOK = 0;
		printf("Kategorie (0=FOOD/1=NONFOOD) ");
		scanf("%s", &input);
		if (sscanf(input, "%d", &kategorie) != 1) {
			printf("Bitte nur ganze Zahlen eingeben\n");
		} else {
			if (!(kategorie == 0 || kategorie == 1)) {
				printf("Bitte nur 0 oder 1 eingeben\n");
			} else {
				inputOK = 1;
			}
		}
	} while (!inputOK);
	return kategorie;
}
int leseArtikelNummer() {
	int value = 0;
	char input[MAXCHARS] = "";
	int inputOK = 0;
	do {
		printf("Nr: ");
		scanf("%s", &input);
		if (sscanf(input, "%d", &value) != 1) {
			printf("Bitte nur ganze Zahlen eingeben\n");
		} else {
			inputOK = 1;
		}
	} while (!inputOK);
	return value;
}
void leseArtikelName(char* name) {
	int inputOK;
	do {
		inputOK = 1;
		printf("Name: ");
		scanf("%s", name);
		for (int i = 0; i < strlen(name); i++) {
			if (!isalpha(name[i])) {
				printf("Artikelname darf nur aus Buchstaben bestehen\n");
				inputOK = 0;
				break;
			}
		}
	} while (!inputOK);
}
float leseArtikelPreis() {
	float value = 0;
	char input[MAXCHARS] = "";
	int inputOK = 0;
	do {
		printf("Preis: ");
		scanf("%s", &input);
		if (sscanf(input, "%f", &value) != 1) {
			printf("Bitte nur Zahlen eingeben\n");
		} else {
			inputOK = 1;
		}
	} while (!inputOK);
	return value;
}
/* liest beliebig viele Artikel ein und speichert sie in der Liste*/
void artikelErfassen(ARTIKEL artikelliste[]) {
	printf("Artikeldaten eingeben - beenden mit Artikelnr = 0\n");
	ARTIKEL artikel;
	do {
		artikel.nr = leseArtikelNummer();
		if (artikel.nr != 0) {
			leseArtikelName(artikel.name);
			artikel.preis = leseArtikelPreis();
			artikel.kategorie = leseKategorie();
			artikelliste[anzahlArtikel] = artikel;
			anzahlArtikel++;
		}
	} while (artikel.nr != 0);
}
/* gibt einen Artikel auf die Konsole aus */
void printArtikel(ARTIKEL a) {
	printf("%d %s %.2f %s\n", a.nr, a.name, a.preis, categoryNames[a.kategorie]);
}
/* gibt die komplette Artikelliste aus */
void alleArtikelAusgeben(ARTIKEL artikelliste[]) {
	printf("*************** ARTIKELLISTE ******************\n");
	int position;
	for (position = 0; position < anzahlArtikel; position++) {
		printArtikel(artikelliste[position]);
	}
	printf("***********************************************\n");

}
void alleArtikelEinerKategorieAusgeben(ARTIKEL artikelliste[], ARTIKELKATEGORIE kategorie) {
	printf("*************** ARTIKEL der Kategorie %s ******************\n", categoryNames[kategorie]);
	int position;
	for (position = 0; position < anzahlArtikel; position++) {
		ARTIKEL a = artikelliste[position];
		if (a.kategorie == kategorie) {
			printArtikel(artikelliste[position]);
		}
	}
	printf("***********************************************\n");

}
ARTIKEL findeTeuersten(ARTIKEL artikelliste[]) {
	ARTIKEL a = { 0,"N.A.",FLT_MIN ,NONFOOD };
	for (int i = 0; i < anzahlArtikel; i++) {
		if (artikelliste[i].preis > a.preis) {
			a = artikelliste[i];
		}
	}
	return a;
}
void erzeugeTestDaten(ARTIKEL artikelliste[]) {
	ARTIKEL a1 = { 100, "USB-Stick", 19.99f, NONFOOD };
	artikelliste[anzahlArtikel++] = a1;
	ARTIKEL a2 = { 101, "Banane", 0.50f, FOOD };
	artikelliste[anzahlArtikel++] = a2;
	ARTIKEL a3 = { 102, "Monitor", 200.00f, NONFOOD };
	artikelliste[anzahlArtikel++] = a3;
}

int compareByCategory(const void* a1, const void* a2) {
	const ARTIKEL* artikel1 = (const ARTIKEL*)a1;
	const ARTIKEL* artikel2 = (const ARTIKEL*)a1;
	return artikel1->kategorie - artikel2->kategorie;
}
void sortiereNachKategorie(ARTIKEL artikelliste[]) {
	qsort(artikelliste, anzahlArtikel, sizeof(ARTIKEL), compareByCategory);
}

void main() {
	char eingabe[MAXCHARS] = "";
	ARTIKEL artikelliste[MAXARTIKEL];
	ARTIKELKATEGORIE kategorie = 0;
	ARTIKEL artikel;
	erzeugeTestDaten(artikelliste);
	do {
		printf("Was wollen Sie tun ?\n");
		printf("====================\n");
		printf("1 - Artikel erfassen\n");
		printf("2 - Alle Artikel ausgeben\n");
		printf("3 - Alle Artikel einer Kategorie ausgeben\n");
		printf("4 - Den teuersten Artikel ausgeben\n");
		printf("5 - Artikel nach Kategorie sortieren\n");
		printf("6 - Programm beenden\n");
		scanf("%s", &eingabe);
		switch (eingabe[0]) {
		case '1':
			artikelErfassen(artikelliste);
			break;
		case '2':
			alleArtikelAusgeben(artikelliste);
			break;
		case '3':
			kategorie = leseKategorie();
			alleArtikelEinerKategorieAusgeben(artikelliste, kategorie);
			break;
		case '4':
			if (anzahlArtikel == 0) {
				printf("Noch keine Artikel erfasst\n");
			} else {
				artikel = findeTeuersten(artikelliste);
				printArtikel(artikel);
			}
			break;
		case '5':
			sortiereNachKategorie(artikelliste);
			break;
		case '6':
			printf("ENDE\n");
			break;
		default:
			printf("Falsche Eingabe %s\n", eingabe);
			break;
		}
	} while (eingabe[0] != '6');
}