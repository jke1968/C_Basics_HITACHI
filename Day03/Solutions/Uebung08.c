#pragma warning (disable: 4996)
#include <stdio.h>
#include <string.h>

typedef struct {
	unsigned int tag;
	unsigned int monat;
	unsigned int jahr;
} DATUM;

void printDate(const DATUM* date) {
	printf("Tag: %d Monat: %d Jahr: %d\n", date->tag, date->monat, date->jahr);
}

int isDateValid(unsigned int jahr, unsigned int monat, unsigned int tag) {
	if (!(monat >= 1 && monat <= 12)) {
		return 0;
	}
	if (!(tag >= 1 && tag <= 31)) {
		return 0;
	}
	return 1;
}
int createDateFromString(const char* string, DATUM* date) {
	int jahr = 0;
	int monat = 0;
	int tag = 0;
	int success = 0;
	if (sscanf(string, "%d-%d-%d", &jahr, &monat, &tag) != 3) {
		success = 0;
	} else {
		if (!isDateValid(jahr, monat, tag)) {
			success = 0;
		} else {
			date->jahr = jahr;
			date->monat = monat;
			date->tag = tag;
			success = 1;
		}
	}
	return success;
}

int main() {
	DATUM date = { 0,0,0 };
	char string[20];
	strcpy(string, "2023-10-06");
	printDate(&date);
	if (createDateFromString(string, &date)) {
		printDate(&date);
	} else {
		printf("Could not convert string to DATE\n");
	}
}