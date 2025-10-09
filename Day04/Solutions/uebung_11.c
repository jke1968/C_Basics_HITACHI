#pragma warning(disable: 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	int nummer;
	char name[20];
} PERSON;

void initArray(PERSON* persons, int noOfPersons) {
	for (int i = 0; i < noOfPersons; i++) {
		persons[i].nummer = i + 100;
		strcpy(persons[i].name, "N.A.");
	}
}
void printPersons(const PERSON* const p) {
	printf("%d %s\n", p->nummer, p->name);
}
void printArray(const PERSON*  persons, int noOfPersons) {
	for (int i = 0; i < noOfPersons; i++) {
		printPersons(persons);
		persons++;
	}
}
int main() {
	int noOfPersons = 0;
	PERSON* persons = NULL;
	printf("Wieviele Personen sollen angelegt werden?\n");
	if (scanf("%d", &noOfPersons) != 1) {
	} else {
		persons = malloc(noOfPersons * sizeof(PERSON));
		if (persons == NULL) {
			printf("Kein Speícherplatz mehr vorhanden - Programm wird beendet");
			return 1;
		} else {
			initArray(persons, noOfPersons);
			printArray(persons, noOfPersons);
			free(persons);
		}
	}
	return 0;
}