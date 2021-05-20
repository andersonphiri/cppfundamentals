#pragma once
#include <iostream>
#include <set>
#include <functional>
#include <map>
/// <summary>
/// std::set / std::multi_set:
/// implemented as a binary tree
/// elements are stored in sorted order (< & >)
/// value acts as key
/// Fast search
/// no random access
/// Elements cannot be modified directly
/// set does not allow duplicates but multiset does
/// Set is not effieint for insertion and deletion as the list is but it is efficient for lookup values
/// #include <set>
/// </summary>
void StdSetAndMultiset() {
	// by default set will order elements in ascendig order
	std::set<int, std::greater<int>> s{2, 4, 7, 99, 1, 2};
	std::multiset<int, std::greater<int>> sm{ 2, 4, 7, 99, 1, 2,9,4,9,4,9,4 };
	// insert
	s.insert(55);
	s.erase(2);
	// print using iterator
	auto itr = s.begin();
	while (itr != s.end())
	{
		std::cout << *itr++ << " ";
	}
	// each element is the key
	itr = s.find(99);
	if (itr != s.end())
	{
		std::cout << "Element 99 found" << std::endl;
	}
	// sm.multiset
	sm.insert(34);
	sm.insert(34); // allows duplicates
	// search for all occurances
	auto found = sm.equal_range(4); // will return a pair vector from start pointer to pointer next to the last occurance of the searched key
	while (found.first != found.second)
	{
		std::cout << *found.first++ << " ";
	}
	

}

/// <summary>
/// implemented as binary tree
/// stores a pair that contains a key and a value
/// elements are stored in sorted order based on a key
/// Fast search and lookup
/// No random access
/// Keys cannot be modified directly, just like in the set
/// #include <map>
/// </summary>
void StdMapAndMultiMap() {
	std::map<int, std::string> m{
		{1, "Superman"},
		{2, "batman"},
	{3, "Green latern"}
	};
	// insert using std::pair
	m.insert(std::pair<int, std::string>(8, "Anderson"));
	// or using makepair helper
	m.insert(std::make_pair(9, "Wonderful"));
	// a key is the index
	m[9] = "key was 9";
	auto itr = m.begin();
	std::cout << itr->first << " : " << itr->second << std::endl;

	// print all elements

	for (const auto& x : m) { // &x is a K,V pair
		std::cout << x.first << " : " << x.second << std::endl;
	}
	// erasing
	m.erase(0);
	itr = m.find(9);
	auto indexOperator = m[1] ; // avoid this. if key aint exists, it sets to default
}

// 