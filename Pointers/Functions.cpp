#include <iostream>
#include "math.h"
int Add(int a, int b) {
	return a + b;
}
double Add(double a, double b) {
	return a + b;
}
extern "C" void Print(int* x) {

}
void Print(const int* x) {

}
int SquareInline(int x) {
	return x * x;
}

// function with defult args
//NOTE: default parameters are passed from right to left
void CreateWindow(const char * title, int x = -1, int y = -1, int width = -1, int height = -1) {

}

#define Square(x) x*x;
// to improve execution time, function calls are not that efficient
// first option is to use Macro As define above -  Square

// FUNCTION POINTERS

void EndMessage() {
	using namespace std;
	cout << "After all has beedn said and done. this will invoke last." << endl;
}


// NAMESPACES

namespace Avg {
	/// <summary>
	/// calculates average
	/// </summary>
	/// <param name="a"></param>
	/// <param name="b"></param>
	/// <returns></returns>
	double Calculate(double a, double b) {
		return a + b / 2;
	}
}

namespace Addition {
	/// <summary>
	/// Adds two numbers
	/// </summary>
	/// <param name="a"></param>
	/// <param name="b"></param>
	/// <returns></returns>
	double Calculate(double a, double b) {
		return a + b ;
	}
}


int TestFunctions() {
	using namespace std;
	int result = Add((double)50, 4.6);
	auto resultD = Add(5.6, 7.2);
	int x = 50;
	auto squareIncorrect = Square(x + 3); // this will print incorect result. the result will be equal to 53^2 as intended. this is the problem with macros
	// macros have bugs
	auto squareCorrecAnEfficient = SquareInline(x); // this is better
	const int y = 34;
	Print(&x); // will invoke Print(int* x)
	Print(&y);  // will invoke Print(const int* x)
	CreateWindow("My Window title");

	// function pointer to Add(double,double)
	double(*pfn) (double, double) = &Add;
	// invoking it
	auto resultFromPointer = (*pfn)(50.6, 55.9);

	// pointer to void print. take note the & operator is optional
	void(*pfn2)(int*) = Print;
	// invoking
	(*pfn2)(&x);
	atexit(EndMessage);
	
	// namespace calling
	double added = Addition::Calculate(45.7, 99.4);
	using namespace Addition;
	added = Calculate(398.45, 67.45);
	using Avg::Calculate;
	double avg = Calculate(20.05, 20.05);

	return 0;
}