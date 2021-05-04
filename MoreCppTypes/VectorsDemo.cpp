#include <iostream>

#include "VectorsDemo.h"
#include <vector>
void VectorDemo1() {
	// intialize vector
	std::vector<int> ints{ 1,2,3,4,5,5,6,7,8,9 };

	// access
	ints[0] = 99;
	auto iterator = ints.begin();// points to the first element ie at index 0

	// delete
	ints.erase(iterator); // erase the current element pointed by the iterator

	for (auto& i : ints)
	{
		std::cout << i << std::endl;
	}

	// insert
	 iterator = ints.begin() + 5;
	ints.insert(iterator, 5555);
	for (auto& i : ints)
	{
		std::cout << i << std::endl;
	}
}