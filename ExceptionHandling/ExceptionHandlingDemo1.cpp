#include <iostream>
#include "ExceptionHandlingDemo1.h"
#include <vector>
#include <random>
using namespace std;

class Test{
public:
	Test() {
		std::cout << "Test()" << std::endl;
	}
	~Test() {
		std::cout << "~Test()" << std::endl;
	}
};

void ProcessRecords(int count) {
	int* pArray = (int*) malloc(count * sizeof(int)); // new throw exception when failed to allocate memory but mallow return null
	// use smar pointer to avoid leaks in case of an exception
	std::unique_ptr<Test> t{ new Test };
	// create bad alloc exception
	int* p = new int[count]; // if new fails will a bad alloc exception
	if (pArray == nullptr)
	{
		throw runtime_error("Failed to allocate memory");
	}
	for (int i = 0; i < count; i++)
	{
		pArray[i] = i*3;
	}
	free(pArray);
}

void ProcessRescordWithSmartPointersAndContainers(int count) {
	if (count < 10)
	{
		throw out_of_range("Count should be greater than 10");
	}
	std::vector<int> p;
	p.reserve(count);
	std::vector<int> pArray;
	pArray.reserve(count);
	for (int i = 0; i < count; i++)
	{
		pArray.push_back( i * 3);
	}
	// randomisation
	std::default_random_engine eng;
	std::bernoulli_distribution dist;
	int countError = 0;
	for (size_t i = 0; i < count; i++)
	{
		std::cout << "Processing record: " << i << std::endl;
		try
		{
			if (!dist(eng))
			{
				++countError;
				throw std::runtime_error("could not process record");
			}
		}
		catch ( std::exception& ex)
		{
			std::cout << ex.what() << std::endl;
			if (countError > 4)
			{
				// modifiy and rethrow
				std::runtime_error customEx("We could not process allrecords");
				ex = customEx;
				throw;

			}
		}
	}
}

void Test1() {
	ProcessRecords(numeric_limits<int>::max()); // simulate failure
}