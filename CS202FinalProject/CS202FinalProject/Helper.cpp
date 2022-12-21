#include <cassert>
#include <sstream>

#include "Helper.h"

Helper::Helper() {};

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

int Helper::convertStringToInt(const std::string &s) {
	std::stringstream ss(s);
	int result;
	ss >> result;
	return result;
};

int Helper::getRandomIntegerFromList(const std::vector<int>& numbers) {
	return numbers[rand() % numbers.size()];
};

std::string Helper::getLowercaseString(std::string s) {
	for (char& c : s)
		c = tolower(c);
	return s;
};

bool Helper::readInteger(const std::string& s, int& i, int& result) {
	const int length = s.size();
	if (i >= length)
		return false;
	bool negative;
	if (s[i] == '-') {
		negative = true;
		++i;
	}
	else
		negative = false;
	if (!isdigit(s[i]))
		return false;
	result = 0;
	while (i < length && isdigit(s[i]))
		(result *= 10) += s[i++] - '0';
	if (negative)
		result *= -1;
	return true;
}

bool Helper::checkEqual(const double x, const double y) {
	return std::fabs(x - y) <= 1E-9;
};

bool Helper::checkGreaterOrEqual(const double x, const double y) {
	const double EPS = 1E-9;
	return x > y + EPS || std::fabs(x - y) <= 1E-9;
};