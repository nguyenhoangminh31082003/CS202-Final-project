#pragma once

#include <random>
#include <string>
#include <vector>
#include <cstring>

class Helper final {
private:

	Helper();

public:

	Helper(const Helper& helper) = delete;
	Helper& operator = (const Helper &helper) = delete;

	static long long getRandomInteger(const long long l, const long long r);
	static std::string convertIntToString(const int number);
	static int convertStringToInt(const std::string &s);
	/*
	static std::vector<std::string> splitString(const std::string& text, const std::string& seperate);
	static std::vector<std::string> splitString(const std::string& text, const std::string& seperate, int maximum);
	static std::string replaceString(const std::string& text, const std::string& oldSubstring, const std::string& newSubstring);
	static std::string replaceString(const std::string& text, const std::string& oldSubstring, const std::string& newSubstring, int maximum);
	*/
	static int getRandomIntegerFromList(const std::vector<int>& numbers);
	static std::string getLowercaseString(std::string s);
	static bool readInteger(const std::string& s, int& i, int& result);

	static bool checkEqual(const double x, const double y);

};