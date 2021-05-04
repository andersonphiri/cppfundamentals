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
}

void WriteCharByChar() {
	std::ofstream out("test.log");
	if (!out) {
		std::cout << "could not open file for writting" << std::endl;
		return;
	}
	{
		std::string message{ "Through God's grace C++ was invented" };
		for (char ch : message)
			out.put(ch);
	}
	out.seekp(5);
	out.put('#');
	out.put('#');
}

void ReadCharByChar() {
	std::ifstream input("test.log");
	if (!input)
	{
		std::cout << "could not open file to read" << std::endl;
	}
	// seek position 10 from begining
	input.seekg(10, std::ios::beg);
	std::cout << "Current position is : " << input.tellg() << std::endl;

	char ch{};
	while (input.get(ch))
	{
		std::cout << ch;
	}
	std::cout << std::endl;
}

/// <summary>
/// fstream will not create the file is it does not exist you create it manually
/// </summary>
void UsingFStream() {
	std::fstream stream{ "fstream.txt" };
	if (!stream)
	{
		std::cout << "File does not exist. creating one..." << std::endl;
		std::ofstream out{ "fstream.txt" };
		out.close();
		stream.open("fstream.txt");
	}
	stream << "Writting to stream with " << std::endl;
	stream.seekg(0); // go back to start of file
	std::string line;
	std::getline(stream, line);
	std::cout << line << std::endl;


}

int WriteBinaryDataToBinaryFiles() {
	std::ofstream textstream{ "data.bin" };
	textstream << 12345678975783;
	std::ofstream binstream{ "binary.bin", std::ios::binary | std::ios::out };
	long num{ static_cast<long>(12345678975783l )};
	binstream.write((const char*)&num, sizeof(num));
	// read binary
	num = 0;
	binstream.close();
	std::ifstream input{ "binary.bin", std::ios::binary | std::ios::in };
	input.read((char*)(&num), sizeof(num));
	std::cout << num << std::endl;
	return 0;
}

// reading and writting Custom structs


void WriteRecord(Record* p) {
	std::ofstream binstream{ "Records", std::ios::binary | std::ios::out };
	binstream.write((const char*)p, sizeof(p));
}

Record ReadRecord() {
	std::ifstream input{ "Records", std::ios::binary | std::ios::in };
	Record r;
	input.read((char*)(&r), sizeof(Record));
	return r;
}