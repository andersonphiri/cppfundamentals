#include <iostream>
#include "StringsDemo.h"
#include <string>
#include <sstream>
const char* Combine(const char* first, const char* last) {
	char * fullname = new char[strlen(first) + strlen(last) + 1];
	strcpy(fullname, first);
	strcat(fullname, last);
	return fullname;
}
void ReadFromUserInput() {
	char first[10];
	char last[10];
	std::cin.getline(first, 10);
	std::cin.getline(last, 10);
	auto fn = Combine(first, last);
	std::cout << "Printing the fullname is: " << fn << std::endl;
	delete[] fn;
}

void UsingStdStrings() {
	// Initialize
	std::string s = "Hello";
	std::string s2{ "Anderson" };
	std::string s3;
	s3 = "Bye for lunch";

	// access
	s[0] = 'W';
	char ch = s[2];
	std::cout << s << std::endl;
	std::cin >> s;
	std::getline(std::cin, s);

	// size
	//s.length();

	// insert and concatenate and insert
	std::string s1{ "hello motto" }, s4{ "whats up" };
	std::string s5 = s1 + s4;
	s5.insert(4, "inserted at 4");

	// comparison
	if (s1 != s5 || s1 > s4) {}

	// removal
	s5.erase(); // erases the entire string
	s4.clear(); // clears the entire string
	s1.erase(0, 5); // erases first five chars

	// search
	s4 = "my name is anderson";
	auto pos = s.find("is", 0);
	if (pos != std::string::npos)
	{
		// found
		std::cout << "\"is\" Found at position :" << pos << std::endl;
	}
}

std::string TestUsingStatndardStrings() {
	//declare empty strings
	std::string first;
	std::string last;

	// fill them from user input
	std::getline(std::cin, first);
	std::getline(std::cin, last);
	std::string fullname{ first + " " + last };
	return fullname; // return by value, a copy is created
}

// return a c_type string from standard strings
const char* ReturCstyleStringFromStandardString() {
	std::string s1{"first"};
	std::string s2{"second"};
	const char* res{ (s1 + s2).c_str() };
	return res ;
}

// string streams
// string streams maintain a string buffer
void StringStreamsDemo() {
	int a{ 5 }, b{ 39 };
	int sum{ a + b };
	// string formatting
	std::stringstream ss;
	// insert into buffer
	ss << "The sum of " << a << " & " << b << " is " << sum << std::endl;
	std::string formattedString = ss.str();
	std::cout << formattedString << std::endl;
	// to insert into buffer
	ss.str("new string into buffer");
	// clear buffer before inserting new record
	ss.str("");
	ss << sum; // insert sum into buffer
	// convert to string
	auto ssum = std::to_string(sum);
	std::cout << "ssum value is: " << ssum << std::endl;
}

void ParsingStringsIntoNumbers() {

	// parse string into numbers
	std::string data = "13 27 99";
	int a1;
	std::stringstream ss2;
	ss2 << data; // insert into stream;
	//while (!ss2.fail())
	//{
	//	// read number from stream into int
	//	ss2 >> a1;
	//	std::cout << "The read value is : " << a1 << std::endl;
	//}
	//invoke the bool operator

	while (ss2 >> a1)
	{
		// read number from stream into int
		std::cout << "The read value is : " << a1 << std::endl;
	}

	// modern ways to convert string to intger
	std::string::size_type sz;   // alias of size_t
	int num20 = std::stoi("AD", nullptr, 16);
	auto numAutoHex = std::stoi("0x7F", nullptr, 0);
	int ia = std::stoi("23456", &sz);
}