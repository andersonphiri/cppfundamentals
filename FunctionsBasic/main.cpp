#include <iostream>
#include "math.h"
#include "Functions.h"
int main() {
	int x, y;
	std::cin >> x >> y;
	int result = Add(x, y);
	std::string s1("initial value"); // direct initialization
	char d4[8] = { "andrson" }; // copy initializtio
	char d1[8] = { '\0' };
	char d2[8] = { 'a', 'b', 'c', 'd' }; // aggregate initialization

	// efficient initializatioon
	int b{};
	int b3{ 5 };
	char arr[8]{};
	// to avoid:
	int b4 = 6;
	// pointers
	int* p1 = new int{};
	char* p2 = new char[8]{};
	char* p3 = new char[8]{ 'a', 'b' };

	/*
	types of initialization
	1. Value initialization => T obj{}
	2. Direct initialization => T obj{v}
	3. copy initialization => T obj = v
	*/ 
	TestFunctions();

	return 0;
}

