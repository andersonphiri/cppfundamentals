#pragma once
#include <iostream>
#include <array>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
/// <summary>
/// it is thin wrapper over C-style static arrays
/// supports iterators
/// knows about its size
/// provides random access
/// can be used with C functions
/// cannot grow
/// #include <array>
/// </summary>
void StdArray() {
	std::array<int, 5> arr{ 1,2,3,4,5 };
	for (int i = 0; i < arr.size(); i++) {
		arr[i] = 2 * i;
	}

	// iterator
	auto itr = arr.begin();

	//pointer to the internal array. pass it to C functions
	arr.data();

	// to iterate all elements , use a range based for which internally uses iterators
}

/// <summary>
/// std::Vector behaves like a dynamic array
/// grows automatically
/// efficient for addition / removal at end
/// provides random access
/// not good for insertion and deletion
/// #include <vector>
/// </summary>
void StdVector() {
	std::vector<int> coll{ 1,2,3,4,5 };
	for (int i = 0; i < 5; i++) {
		coll.push_back(2 * i);
	}
	// print using iterator
	auto itr = coll.begin();
	while (itr != coll.end())
	{
		std::cout << *itr++ << " ";
	}
	// to remove elements
	auto position = coll.begin() + 3;
	coll.insert(position, 700); // this opearation has performance issues esp with user defined object
	// erase
	coll.erase(position - 1);
	// to remove at end end - more efficient
	coll.pop_back();
}

/// <summary>
/// Pronounced s Deck
/// short for double ended queue
/// commonly used for implementing queue
/// efficient for addition /  removal at both ends
/// grows automatically
/// provides random access
/// not good for insertion / deletion
/// similar to vector
/// #include <deque>
/// </summary>
void StdDeque() {
	std::deque<int> coll{ 1,2,3,4,5 };
	// insert at back
	for (int i = 0; i < 5; i++) {
		coll.push_back(2 * i);
	}

	// insert at front
	for (int i = 0; i < 5; i++) {
		coll.push_front(2 * i);
	}
	// using random access
	coll[3] = 45;
	// to remove elements
	auto position = coll.begin() + 3;
	coll.insert(position, 700); // this opearation has performance issues esp with user defined object
	// erase
	coll.erase(position - 1);
	// to remove at end end - more efficient
	coll.pop_back();
	// pop at front 
	coll.pop_front();
}

/// <summary>
/// implemented as a two way linked list - double linked list
/// efficient for insertion and deletion anywhere
/// allows iterations in both directions, both forwars and backward
/// insertions and deletions will take constant time
/// does not provide random access ie listvar[index] does not work
/// good for insertions and deletions
/// #include <list>
/// </summary>
void StdList() {
	std::deque<int> coll{ 1,2,3,4,5 };
	// insert at back
	for (int i = 0; i < 5; i++) {
		coll.push_back(2 * i);
	}

	// insert at front
	for (int i = 0; i < 5; i++) {
		coll.push_front(2 * i);
	}
	// to remove elements
	auto position = coll.begin() + 3;
	coll.insert(position, 700); // this opearation has performance issues esp with user defined object
	// erase
	coll.erase(position - 1);
	// to remove at end end - more efficient
	coll.pop_back();
	// pop at front 
	coll.pop_front();
}

/// <summary>
/// implemented as a one-way linkedlist - single single linked list
/// iteration is only forward and not backward
/// efficient for insertion and deletion
/// Small memory footprint
/// does not provide support for size
/// element are added at the front
/// access to elements is LIFO - ie has a stack behaviour
/// #include <forward_list>
/// </summary>
void StdForwardList() {
	std::forward_list<int> coll{ 1,2,3,4,5 };
	// insert at front
	for (int i = 0; i < 5; i++) {
		coll.push_front(2 * i);
	}
	// print using iterator
	auto itr = coll.begin();
	while (itr != coll.end())
	{
		std::cout << *itr++ << " ";
	}
	// erase and insert : as efficient as is the list
	coll.insert_after(coll.begin(), 33);
	coll.erase_after(coll.begin());

}
