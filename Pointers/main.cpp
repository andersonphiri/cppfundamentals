#include <iostream>

/*
types of initialization
1. Value initialization => T obj{}
2. Direct initialization => T obj{v}
3. copy initialization => T obj = v
*/
void universal_pointer();
void reference_types_demo();
void TestSwaps();
void ConstQualifier();
int main() {
	using namespace std;
	//universal_pointer();
	//reference_types_demo();
	// TestSwaps();
	ConstQualifier();
	
	return 0;
}
void PointersBasic() {
	using namespace std;
	int x{ 50 };
	cout << "The address of  is: " << &x << endl;
	cout << "The value x of  is: " << x << endl;
	// create pointer to x
	int* y = &x;
	cout << "The value x of  from the pointer is: " << *y << endl;
	// change value via pointer
	*y = 55;
	int z = *y;
	cout << "The value x of  from the pointer after pointer change is: " << *y << endl;
}
void universal_pointer() {
	void* ptr = nullptr;
	int* ptrInt = nullptr;
	std::cout << "pointer value: " << ptr << std::endl;
	std::cout << "Never attempt to read from an nulllptr: " << ptrInt << std::endl;
}

void reference_types_demo() {
	/**
	* A reference type:
	* Defines an alternative name for a variable (an alias)
	* it is created with the & operator
	* always needs an initializer - called a referent
	* the referent should be a variable
	* it can be used to modify a variable indirectly, just a pointer
	* a reference is not a new variable, its just another name ie no memory is allocated for reference
	**/

	// example
	int x = 10;
	int& refX = x; // x is the referent and refX is the reference
	std::cout << "X: " << x << std::endl;
	std::cout << "Ref: " << refX << std::endl;
	std::cout << "Address of X: " << &x << std::endl;
	std::cout << "Address of Ref: " << &refX << std::endl;
	// set new value through ref
	refX = 25;
	std::cout << "Setting value to 25 through Ref: " << &refX << std::endl;
	std::cout << "X: " << x << std::endl;
	std::cout << "Ref: " << refX << std::endl;
	x = 26; 
	std::cout << "Setting value to 26 through x: " << &refX << std::endl;
	std::cout << "X: " << x << std::endl;
	std::cout << "Ref: " << refX << std::endl;
}

// when to use reference
void SwapByAddress(int* x, int* y) {
	if (x == nullptr || y == nullptr)
	{
		return;
	}
	int temp = *x;
	*x = *y;
	*y = temp;
}

void SwapByReference(int& x, int& y) {
	int temp = x;
	x = y;
	y = temp;
}

void TestSwaps() {
	using namespace std;
	cout << "########### Testing swaps ##########" << endl;
	int x = 35;
	int y = 53;
	// referents
	int z = 46, w = 77;
	int* ptrX = &x;
	int* ptrY = &y;
	// references
	int& refZ = z;
	int& refW = w;
	cout << "(address types ) Before swap by address" << endl;
	cout << "x = " << *ptrX << " y = " << *ptrY << endl;
	SwapByAddress(ptrX, ptrY);
	cout << "(address types ) AFter swap by address" << endl;
	cout << "x = " << *ptrX << " y = " << *ptrY << endl;
	cout << "(reference types ) Before swap by reference" << endl;
	cout << "z = " << refZ << " w = " << refW << endl;
	SwapByReference(refZ, refW);
	cout << "(reference types ) After swap by reference" << endl;
	cout << "z = " << refZ << " w = " << refW << endl;

}

using namespace std;
void PrintFixed(const int* ptr) {
	cout << "The value is: " << *ptr << "and the value is: " << endl;
	//ptr = 20; // won't work
}

void PrintChangeable(int* ptr) {
	cout << "The value is: " << &ptr << "and the value is: " << endl;
	*ptr = 20; // will work
}

void PrintFixedWithRefs(const int& ref) {
	cout << "The value is: " << ref << "and the address value is: " << endl;
}
void ConstQualifier() {
	using namespace std;
	float radius = 0;
	cout << "#### const qualifier demo ###" << endl;
	cout << "Please enter your radius: ";
	cin >> radius;
	const float PI = 3.141f;
	float area = PI * radius * radius;
	float circumference = PI * radius * 2;
	cout << "Area: " << area << endl;
	cout << "Circumference: " << circumference << endl;
	cout << "Cons and reference types..." << endl;
	const int CHUNK_SIZE = 1024;
	const int* ptr = &CHUNK_SIZE;
	cout << "The value from const ptr is: " << *ptr << endl;
	cout << "The address from const ptr is: " << *ptr << endl;
	int x = 27;
	ptr = &x;
	cout << "The value of ptr is now: " << ptr << endl;
	// the uncangeable const ptr
	const int* const ptrFixed = &CHUNK_SIZE;
	// 
	//ptrFixed = &x; // won't work

	PrintFixed(ptrFixed); 
	PrintFixedWithRefs(20);// PrintFixed(20) won't work with address but with refs
	const int  & const ptrFixed2 = 55;
}