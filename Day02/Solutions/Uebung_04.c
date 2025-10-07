#pragma warning (disable: 4996)
#include <stdio.h> 
#include <string.h>

#define MAXCHARS 20

int isPalindrome(char word[]) {
	int counterLeft = 0;
	int counterRight = strlen(word)-1;
	while (counterLeft < counterRight) {
		if (word[counterLeft] != word[counterRight]) {
			return 0;
		}
		counterLeft++;
		counterRight--;
	}
	return 1;
}

int main() {
	char word[MAXCHARS+1];
	while (1) {
		printf("Bitte Wort eingeben: ");
		scanf("%20s", word);
		if (isPalindrome(word) == 1) {
			printf("%s ist ein Palindrom\n",word);
		} else {
			printf("%s ist kein Palindrom\n",word);
		}
	}
	return 0;
}