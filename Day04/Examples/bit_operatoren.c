#include <stdio.h>
#include <inttypes.h>

int main() {
	uint8_t byte1 = 1;        // 0000 0001
	uint8_t byte2 = 128;      // 1000 0000
	uint8_t byte3 = 129;      // 1000 0001
	uint8_t result = 0;       // 0000 0000

	// bit operator #1 bitwise AND &
	result = byte1 & byte2;   // 0000 0000
	 
	printf("result = %d\n", result);

	// bit operator #2 bitwise OR |
	result = byte1 | byte2;   // 1000 0001
	printf("result = %d\n", result);

	// bit operator #3 bitwise XOR ^
	result = byte1 ^ byte3;   // 1000 0000
	printf("result = %d\n", result);

	// bitwise shift operators:
	// #1 bitiwse shift-left << 
	// shift byte1 to the left by 1
	result = byte1 << 1;     //  0000 0010
	printf("result = %d\n", result);

	result = byte2 << 1;     //  0000 0000
	printf("result = %d\n", result);

	// #2 bitiwse shift-right >>
	result = byte2 >> 1;     //  0100 0000
	printf("result = %d\n", result);

    // shift byte2 to the right 3-times
	result = byte2 >> 3;    //   0001 0000
	printf("result = %d\n", result);


	// bitwise complement ~
	// -> macht 1 aus 0 und 0 aus 1
	result = ~byte2;
	printf("result = %d\n", result);


	return 0;
}