#include <iostream>

union Test {
	int x;
	char ch;
	Test() : ch{ 'a' } {
		std::cout << __FUNCSIG__ << std::endl;
	}
	~Test() {
		std::cout << __FUNCSIG__ << std::endl;
	}
};

void UnionDemo() {

}