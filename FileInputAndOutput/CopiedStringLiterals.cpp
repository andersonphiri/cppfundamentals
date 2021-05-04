#include <iostream>
#include "StringLiterals.h"
//#include <filesystem>
#include <experimental/filesystem>
#include <fstream>
int PrintFilePath() {

	std::string filename{ R"(C:\windows\system32\numbers)" };
	std::cout << filename << std::endl;
	std::string message {R"MSG(C++ introduced filesystem API"(In C++ 11)")MSG"};
	std::cout << message << std::endl;
	return 0;
}

int ExperimentalFileSystemLibrary() {
	//using namespace std::filesystem;
	using namespace std::experimental::filesystem;
	path p{ R"(D:/SoftwareEmgineering/distributeddotnetcore.txt)" };
	if (p.has_filename())
	{
		std::cout << "File path is: " << p.filename() << std::endl;
	}
	for (const auto& x : p) {
		std::cout << x << std::endl;
	}

	path pDir{ R"(D:/SoftwareEmgineering)" };
	std::cout << "Iterating path " << R"(D:\SoftwareEmgineering)" << std::endl;
	// directory iterator
	directory_iterator begin{ pDir };
	/*for (auto& iterator : begin) {
		std::cout << iterator.path().filename() << std::endl;
	}*/
	directory_iterator end{ pDir };
	std::cout << *begin << std::endl;
	while (begin != end)
	{
		std::cout << *begin << std:: endl;
		++begin;
	}

	return 0;

}

void Write() {
	std::ofstream out{ R"(textCpp.txt)" };
	out << "Hello Mr file" << std::endl; 
	out << "I trust you are doing well" << std::endl;
	out << 1234 << std::endl;
	out.flush();
	out.close();
}

void Read() {
	std::ifstream input{ R"(textCpp.txt)" }; // D:\SoftwareEmgineering\CplusPlus
	std::string message;
	std::getline(input, message);
	std::cout << "Read from file , the message is: " << message << std::endl;
	input.close();
}

int CopyFileUtility() {
	//using namespace std::filesystem;
	using namespace std::experimental::filesystem;
	path source(current_path());// current execution directory
	source /= "StringLiterals.cpp";
	path dest(current_path());
	dest /= "CopiedStringLiterals.cpp";
	std::ifstream input{ source };
	if (!input)
	{
		std::cout << "Source file not found" << std::endl;
		return -1;
	}
	std::ofstream output{ dest };
	std::string line;
	while (!std::getline(input,line).eof())
	{
		output << line << std::endl;
	}
	input.close();
	output.close();
	std::cout << "copy file completed successfully" << std::endl;
	return 0;
