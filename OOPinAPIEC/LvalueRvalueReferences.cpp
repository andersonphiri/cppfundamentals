#include <iostream>

// return r value since it returns by value
int AddR(int x, int y) {
	return x + y;
}

// return L-value since it returns by refference
int & Transofrm(int& x) {
	x = x * x;
	return x;
}

int RvaluReference() {
	int&& r1 = 20; // 20 is a temporary  r1 is R value reference to 20
	// R value reference cannot bind to Lvalues
	int x = 50;
	//we cannot bind x to rvalue refe as below
	//int&& r2 = x; // won't work

	// but we can assign r value to Addr since it return an R
	int&& r2 = AddR(5, 6);

	// an L value reference may bind toTransform because it returns by ref
	int& Lref = Transofrm(x);
	// an L value can also bind to temporary or lvalue if its const
	const int& Lref2 = 5;

	return 0;
}

// accepts a Lvalue ref
void Print(int& x) {
	std::cout << "Print(int& x)" << std::endl;
}

// accepts a temporary / a constant L value const
void Print(const int& x) {
	std::cout << "Print(const int& x)" << std::endl;
}

void Print(int&& x) {
	std::cout << "Print(int&& x)" << std::endl;
}

int LvRvDemo() {
	return 0;
}