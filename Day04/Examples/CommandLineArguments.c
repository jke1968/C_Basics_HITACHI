#include <stdio.h>

// argc = "argument counter" 
// argv = "argument vector"
//      = ein Array von C-Strings (also von char*)
//        in diesem Array stehen alle Kommandozeilenargumente
// int main(int argc, char* argv[]) {
int main(int argc, char** argv) {
	if (argc == 0) {
		printf("Keine Kommandozeilenargumente übergeben\n");
	} else {
		printf("Alle Kommandozeilenargumente: \n");
		for (int i = 0; i < argc; i++) {
			printf("Stelle Inhalt: %s\n",argv[i]);
		}
	}
	return 0;
}