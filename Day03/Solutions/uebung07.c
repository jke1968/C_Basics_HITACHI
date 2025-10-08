#include <stdio.h>

char* my_strcpy(char* dest, const char* source) {
	char* copy = dest;
	while (*dest++ = *source++)
		;
	return copy;
}

int main() {
	char str1[] = "Hello ";
	char str2[] = "Tim";
	printf("str1 = %s\n", str1);
	printf("str2 = %s\n", str2);
	my_strcpy(str1, str2);
	printf("str1 = %s\n", str1);
	printf("str2 = %s\n", str2);
	return 0;
}