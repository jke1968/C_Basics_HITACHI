// import der Bibliothek stdio.h
// alles was mit einem Hashtag # beginnt
// ist eine sog. Präprozessor-Direktive
// #include sucht nach der Datei zwischen < und >
// und kopiert deren Inhalt in diese Datei
#include <stdio.h>

// Definition der Funktio namens "main"
// -> Einstiegspunkt für das Programm
// Rückgabetyp:    int
// Name:           main
// Parameterliste  () -> leer
int main() { // Beginn der Funktion main (Beginn des scopes)
	// Aufruf der Funktion printf aus der Bibliothek stdio.h
	// Argument ist eine Stringkonstante, hier "Hello \\n World!\n"
	printf("Hello \\n World!\n"); 
	return 0;
} // Ende der Funktion main (Ende des scopes)