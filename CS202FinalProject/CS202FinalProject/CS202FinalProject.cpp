#include <iostream>

#include "MainProgram.h"

int randomIntegers(int l, int r) {
	int h = r - l + 1;
	long long result = 0;
	for (int i = 0; i < 3; ++i)
		result = (result * (RAND_MAX + 1) + rand()) % h;
	result += l;
	return result;
}

int main() {

	MainProgram mainProgram;

	mainProgram.test();
	//mainProgram.run();

	return 0;
}
