#pragma once
#include <iostream>
#include <vector>
#include <list>
typedef const char* (*PFN)(int);
// using aliases
using PFN_F = const char* (*)(int);
const char* GetErrorMessage(int errorNo);

void ShowErrorUnsimplified(const char* (*pfn)(int));
// generic aliases super
typedef std::vector<std::list<std::string>> Names;
// a list of anything using alias templattes
template<typename T> 
using NamesList = std::vector<std::list<T>>;

template<typename T> T Divide(T a, T b) {
	if (std::is_floating_point<T>::value == false)
	{
		std::cout << "Use floating points only" << std::endl;
		return 0;
	}
	return a / b;
}

// using statec_assert. used for evaluating expressions

//bool CheckIfCodeIsBeingCompiledIn32BitMode2() {
//	const auto res =  sizeof(void*) == 4;
//	//static_assert(res, "Compile in 32 bit mode  only");
//	if (sizeof(void*) == 4)
//	{
//		std::cout << "in 32 bit mode" << std::endl;
//	}
//	else {
//		std::cout << "Not in 32 bit mode" << std::endl;
//	}
//
//	return res;
//}

/// <summary>
/// this function accepts both lvalues and rvalues
/// </summary>
/// <param name=""></param>
template<typename T>
void Check(T&&) {
	std::cout << std::boolalpha;
	std::cout << "Is Reference ? " << std::is_reference<T>::value << std::endl;
	std::cout << "After removing reference : " <<
		std::is_reference<typename std::remove_reference<T>::type>::value << std::endl;
}
