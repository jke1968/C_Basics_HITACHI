#include <stdio.h>
#include <inttypes.h>

uint8_t byte = 0;

void set_bit_on(int bitNr) {
	printf("set bit no %d to ON\n",bitNr);
	byte = byte | 1 << bitNr;
}
void set_bit_off(int bitNr) {
	printf("set bit no %d to OFF\n", bitNr);
	byte = byte & ~(1 << bitNr);
}
void printByte() {
	printf("byte = %d\n", byte);
}
int main() {
	printByte();
	set_bit_on(0);
	printByte();
	set_bit_off(0);
	printByte();
	set_bit_on(0);
	printByte();
	set_bit_on(7);
	printByte();
	set_bit_off(0);
	printByte();
	set_bit_off(7);
	printByte();
	return 0;
}