#include <iostream>
#include <vector>
#include <list>
#include "TypeAliases.h"

const char* GetErrorMessage(int errorNo) {
	return "Empty";
}

// a method that accepts a function pointer
void ShowErrorUnsimplified(const char* (*pfn)(int)) {

}




void TypeTraits() {
	std::cout
		<< std::boolalpha
		<< "Is Integer?" << std::is_integral<int>::value << std::endl;
}

// https://subscription.packtpub.com/video/programming/9781800566668/p13/video13_1/callbacks-revisited-function-pointers
