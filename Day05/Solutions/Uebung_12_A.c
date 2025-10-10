/*
Programm:	Uebung12 / 17 und 4
Zweck:		lässt den Spieler (Benutzer) eine oder mehrere Partien 17 und 4 gegen die Bank (Computer) spielen
Autor:		JKE
Datum:		10.10.2025
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#define risikoGrenzeBank 17 

int summeSpieler = 0;
int summeBank = 0;
int karte = 0;
char neueKarte = 'j';
char neuesSpiel = 'j';
int spielerHatVerloren = 0;
int bankHatVerloren = 0;
int karteZiehen() {
	/* 32 Blatt -> 7,8,9,10,As(11),Bube(12 -> 2 Augen),Dame(13 -> 3 Augen),König(14 -> 4 Augen) */
	int karte = rand() % 8 + 7;
	switch (karte) {
	case 12:
		/* Bube */
		karte = 2;
		break;
	case 13:
		/* Dame */
		karte = 3;
		break;
	case 14:
		/* König */
		karte = 4;
		break;
	}
	return karte;
}
void starteSpiel() {
	/* neues Spiel */
	summeSpieler = 0;
	summeBank = 0;
	spielerHatVerloren = 0;
	bankHatVerloren = 0;
	printf("\n --- Los geht's ... ---\n");
	printf("\n32 Blatt -> 7,8,9,10,As(11),Bube(12 -> 2 Augen),Dame(13 -> 3 Augen),Koenig(14 -> 4 Augen)\n ");
	printf("\nDie hoechste Augenzahl gewinnt, wer ueber 21 Augen hat, verliert\n");
	printf("\n");
	/* Spieler erhält 2 Karten */
	karte = karteZiehen();
	printf("Ihre Karte 1 : %i\n", karte);
	summeSpieler = summeSpieler + karte;
	karte = karteZiehen();
	printf("Ihre Karte 2 : %i\n", karte);
	summeSpieler = summeSpieler + karte;
	printf("Ihre Summe : %i\n", summeSpieler);
	if (summeSpieler > 21) {
		spielerHatVerloren = 1;
	}
}
void spielerZieht() {
	/* Spieler zieht nacheinander soviele Karten wie er möchte */
	printf("Noch eine Karte (j/n) ?\n");
	neueKarte = _getch();
	while (neueKarte != 'n') {
		printf("\n");
		karte = karteZiehen();
		printf("Ihre Karte : %i\n", karte);
		summeSpieler = summeSpieler + karte;
		printf("Ihre Summe : %i\n", summeSpieler);
		if (summeSpieler > 21) {
			spielerHatVerloren = 1;
			break;
		}
		printf("Noch eine Karte (j/n) ?\n");
		neueKarte = _getch();
	}
}
void bankZieht() {
	/* Bank zieht Karten nacheinander bis zur Risikogenze */
	printf("\nDie Karten fuer die Bank ");
	do {
		karte = karteZiehen();
		printf("* ");
		summeBank = summeBank + karte;
		if (summeBank > 21) {
			bankHatVerloren = 1;
			break;
		}
	} while (summeBank < risikoGrenzeBank);
	printf("\nSumme Bank: %i\n", summeBank);
}
void ermittleSieger() {
	/* höchste Punktzahl bestimmen  */
	printf("Ihre Summe : %i\n", summeSpieler);
	if (summeSpieler > summeBank) {
		printf("Sie gewinnen\n");
	} else {
		printf("Die Bank gewinnt\n");
	}
}
int main() {
	srand(time(NULL));
	do {
		starteSpiel();
		if (spielerHatVerloren) {
			printf("Sie verlieren\n");
		} else {
			spielerZieht();
			if (spielerHatVerloren) {
				printf("Sie verlieren\n");
			} else {
				bankZieht();
				if (bankHatVerloren) {
					printf("Die Bank verliert\n");
				} else {
					ermittleSieger();
				}
			}
		}
		printf("\nNoch ein Spiel (j/n) ? \n");
		neuesSpiel = _getch();
	} while (neuesSpiel != 'n');
	printf("ENDE\n");
	return 0;
}