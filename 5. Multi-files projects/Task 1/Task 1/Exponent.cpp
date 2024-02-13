#include "Exponent.h"

int exponention(int num1, int num2) {
	int tmp = num1;

	for (int i = 1; i < num2; i++) {
		num1 *= tmp;
	}

	return num1;
}