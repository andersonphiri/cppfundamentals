#include <iostream>
#include <vector>
#include <random>
#include "StringLiterals.h"

void TestReadWriteRecord() {
	Record record;
	record.id = 10234;
	strcpy_s(record.name, 10, "Anderson");
	WriteRecord(&record);
	Record r2 = ReadRecord();
	std::cout << "ID: " << r2.id << "Name: " << r2.name << std::endl;
}

int main() {

	//PrintFilePath();
	//ExperimentalFileSystemLibrary();
	//Write();
	//Read();
	// CopyFileUtility();
	// WriteCharByChar();
	// ReadCharByChar();
	//UsingFStream();
	//WriteBinaryDataToBinaryFiles();
	TestReadWriteRecord();
	return 0;
}

// https://subscription.packtpub.com/video/programming/9781800566668/p12/video12_1/introduction-to-templates