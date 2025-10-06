#pragma warning (disable: 4996)
#include <stdio.h>
#define MAXCHARS 10
int main() {
	int number1 = 0;
	int number2 = 0;
	char input[MAXCHARS] = { "" };
	char operation = '1';
	while (1) {
		printf("Bitte die erste ganze Zahl eingeben: ");
		if (scanf("%s", input) == 1) {
			if (sscanf(input, "%d", &number1) != 1) {
				printf("Bitte nur ganze Zahlen eingeben\n");
				continue;
			}
		}
		printf("Bitte die zweite ganze Zahl eingeben: ");
		if (scanf("%s", input) == 1) {
			if (sscanf(input, "%d", &number2) != 1) {
				printf("Bitte nur ganze Zahlen eingeben\n");
				continue;
			}
		}
		printf("Addieren(1) oder Subtrahieren(2) ?\n");
		scanf("%s", input);
		switch (input[0]) {
		case '1':
			printf("Summe = %d\n", number1 + number2);
			break;
		case '2':
			printf("Differenz = %d\n", number1 - number2);
			break;
		default:
			printf("Ungueltige Operation\n");
			break;
		}
	}

	return 0;
}