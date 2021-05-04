#pragma once

int PrintFilePath();

struct Record {
	int id;
	char name[100];
};
int ExperimentalFileSystemLibrary();

void Write();

void Read();

int CopyFileUtility();

void WriteCharByChar();

void ReadCharByChar();

void UsingFStream();

int WriteBinaryDataToBinaryFiles();

void WriteRecord(Record* p);

Record ReadRecord();
