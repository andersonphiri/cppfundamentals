#include <iostream>
#include <initializer_list>
#include <cassert>
#include "InitializerList.h"
class Bag
{
public:
	Bag(std::initializer_list<int> values) {
		assert(values.size() < 10);
		auto iterator = values.begin();
		while (iterator != values.end())
		{
			Add(*iterator);
			++iterator;
		}
	}
	~Bag() {

	}
	void Add(int value) {
		assert(m_Size < 10);
		arr[m_Size++] = value;
	}
	int operator [](int index) {
		return arr[index];
	}

	int GetSize() const {
		return m_Size;
	}
	void Remove() {
		--m_Size;
	}
private:
	int arr[10];
	int m_Size{};
};

void Print(std::initializer_list<int> values) {
	auto iterator = values.begin();
	while (iterator != values.end())
	{
		std::cout << *iterator << " ";
		++iterator;
	}

	// alternatively use ranebased forloop

	for (auto num : { 10, 20, 30, 40 })
	{
		std::cout << num << " ";
	}
	//
	for (auto num : values)
	{
		std::cout << num << " ";
	}
}

void TestInitializerLists() {
	std::initializer_list<int> data = { 1,2,3,4,5 };
	auto values = { 1,2,3,4,5 };
	Bag bag{ 1,2,3,4,5,6,7,8, 9, 10, 11 };
	// print bag
	for (size_t i = 0; i < bag.GetSize(); i++)
	{
		std::cout << bag[i] << " ";
	}
	Print({ 1,23,4,5 });

	
}
