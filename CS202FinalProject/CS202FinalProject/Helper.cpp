#include <cassert>
#include <sstream>

#include "Helper.h"

long long Helper::getRandomInteger(const long long l, const long long r) {
	/*
	
		Get a random integer in range [l, r)

	*/
	assert(l < r);
	const long long length = r - l;
	long long result = 0;
	for (int i = 0; i < 3; ++i)
		result =  (result * (RAND_MAX + 1) % length + rand()) % length;
	result += l;
	return result;
};

std::string Helper::convertIntToString(const int number) {
	std::stringstream ss;
	std::string result;
	ss << number;
	ss >> result;
	return result;
};