/*
Programm	:	Uebung05
Zweck		:	verwaltet ein Array von Noten (Hier: Ein Array von float Werten)
*/
#pragma warning (disable: 4996)
#include "stdio.h"

#define MAXNOTEN 10
#define MAXCHARS 5
int anzahlNoten = 0;
/*
* liest Notenwerte zw. 1 und 6 
* von der Konsole ein und schreibt
* sie in das Array notenliste
*/
void notenEingeben(float notenliste[]) {
	float note = 0.0f;
	char input[MAXCHARS] = { 0 };
	while (note != -1) {
		printf("Bitte Noten zwischen 1 und 6 eingeben - mit -1 beenden\n");
		int r = scanf("%s", input);
		if (sscanf(input, "%f", &note) != 1) {
			printf("Bitte nur Zahlen eingeben\n");
		} else {
			if (note >= 1 && note <= 6) {
				// kopiere die note in das Array notenliste
				notenliste[anzahlNoten] = note;
				printf("Note %.1f erfasst\n", note);
				anzahlNoten++;
			} else {
				// Note liegt nicht zw. 1 und 6
				if (note != -1) {
					printf("Bitte nur Noten zw. 1 und 6 eingeben\n");
				}
			}
		}
	}
}
void notenAusgeben(float notenliste[]) {
	for (int stelle = 0; stelle < anzahlNoten; stelle++) {
		printf("Note an der Stelle %d : %.1f\n", stelle, notenliste[stelle]);
	}
}
float ermittleDurchschnitt(float notenliste[]) {
	float summe = 0.0f;
	// 1. Summieren
	for (int stelle = 0; stelle < anzahlNoten; stelle++) {
		summe = summe + notenliste[stelle];
	}
	// 2. Teilen
	return summe / anzahlNoten;
}
float ermittleBesteNote(float notenliste[]) {
	// setze den besteNote auf die erste Stelle im Array
	float besteNote = notenliste[0];
	// vergleiche alle weiteren Stellen im Array mit dem besteNote
	for (int stelle = 1; stelle < anzahlNoten; stelle++) {
		// vergleiche die aktuelle Stelle mit dem besteNote,
		// und ueberschreibe den besteNote wenn die aktuelle Stelle kleiner ist als der besteNote
		if (notenliste[stelle] < besteNote) {
			besteNote = notenliste[stelle];
		}
	}
	return besteNote;
}
float ermittleSchlechtesteNote(float notenliste[]) {
	float besteNote = notenliste[0];
	for (int stelle = 1; stelle < anzahlNoten; stelle++) {
		if (notenliste[stelle] > besteNote) {
			besteNote = notenliste[stelle];
		}
	}
	return besteNote;
}
void handleInput(int eingabe, float notenliste[]) {
	switch (eingabe) {
	case 1:
		notenEingeben(notenliste);
		break;
	case 2:
		if (anzahlNoten > 0) {
			notenAusgeben(notenliste);
		} else {
			printf("Noch keine Noten vorhanden\n");
		}
		break;
	case 3:
		if (anzahlNoten > 0) {
			printf("Durchschnitt: %.2f\n", ermittleDurchschnitt(notenliste));
		} else {
			printf("Noch keine Noten vorhanden\n");
		}
		break;
	case 4:
		if (anzahlNoten > 0) {
			printf("Beste Note: %.2f\n", ermittleBesteNote(notenliste));
		} else {
			printf("Noch keine Noten vorhanden\n");
		}
		break;
	case 5:
		if (anzahlNoten > 0) {
			printf("Schlechteste Note: %.2f\n", ermittleSchlechtesteNote(notenliste));
		} else {
			printf("Noch keine Noten vorhanden\n");
		}
		break;
	case 6:
		printf("Auf Wiedersehen\n");
		break;
	default:
		printf("Falsche Eingabe\n");
		break;
	}

}
void printMenu() {
	printf("Was wollen Sie tun ?\n");
	printf("=====================\n");
	printf("1 - Noten eingeben\n");
	printf("2 - Notenliste ausgeben\n");
	printf("3 - Notendurchschnitt ausgeben\n");
	printf("4 - Beste Note ausgeben\n");
	printf("5 - Schlechteste Note ausgeben\n");
	printf("6 - Programm beenden\n");
}
void displayUserInterface(float notenliste[]) {
	int eingabe = 0;
	char input[MAXCHARS] = { 0 };
	while (eingabe != 6) {
		printMenu();
		int notUsed = scanf("%s", input);
		if (sscanf(input, "%d", &eingabe) != 1) {
			printf("Bitte nur ganze Zahlen eingeben!\n");
		} else {
			handleInput(eingabe, notenliste);
		}
	}

}
void main() {
	float notenliste[MAXNOTEN];
	printf("enter main\n ");
	displayUserInterface(notenliste);
	printf("exit main\n ");
}