#include <stdio.h>

void tausche(int* i1, int* i2) {
	int tmp = *i1;
	*i1 = *i2;
	*i2 = tmp;
}

int main() {
	int i1 = 111;
	int i2 = 222;
	printf("Vor tausche:  %d %d\n", i1, i2);
	tausche(&i1, &i2);
	printf("Nach tausche: %d %d\n", i1, i2);
	return 0;
}