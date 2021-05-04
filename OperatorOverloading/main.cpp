#include <iostream>
#include "Integer.h"
#include "Number.h"
#include "SmartPointers.h"
using namespace std;
// this return by value. is a temporary hence a copy is created
Integer Add(const Integer& a, const Integer& b) {
	Integer temp;
	temp.SetValue(a.GetValue() + b.GetValue()); // a compy ctor will be called
	return temp;
}

// subtraction as a global overloaded operator
Integer operator -(const Integer& a, const Integer& b) {
	return Integer(a.GetValue() - b.GetValue());
}

// global override
Integer operator +(int a, const Integer& b) {
	return Integer(a + b.GetValue());
}

int OperatorOverloading() {
	Integer a(1), b(2);
	Integer sum = 5 + 9; // syntacting sugar
	cout << "The value os sum is: " << sum.GetValue() << endl;
	++sum;
	cout << "The value of sum after increment  is: " << sum.GetValue() << endl;

	return 0;
}

int CopyConstructorSynthesize() {

	// copy and mov demo
	Number n1{ 30 };
	auto n2{ n1 }; // a copy ctor of Integer is invoked
	n2 = n1; // a copy ctor of Integer is invoked
	return 0;
}

// to show move ctor
Number CreateNumber(int num) {
	Number res{ num };
	return res;
}

int MoveConstructorSynthesize() {
	auto n3{ CreateNumber(6) };
	n3 = CreateNumber(55);
	return 0;
}

Integer Add(int a, int b) {
	Integer temp (a  + b);
	return temp;
}

Integer AddMoreEfficient(int a, int b) {
	return Integer(a + b);
}

// std move demo

int Print(Integer n) {
	return 0;
}

// std:: move
int StdMoveFunction() {
	Integer a(2);
	//auto b{ a }; // this will use a copy ctor because a is an lvalue
	// to make the compile use move, we may need to cast a as follows
	//auto b{ static_cast<Integer&&>(a) }; //
	// alternatively, use the more readable std::move fn as follows
	auto b{ std::move(a) }; // a is no longer usable. to use a re initialize by setting new value
	a.SetValue(45);
	return 0;
}

// subtraction as a global overloaded operator
//Integer operator -(const Integer& a, const Integer& b) {
//	return Integer(a.GetValue() - b.GetValue());
//}
//
//// global override
//Integer operator +(int a, const Integer& b) {
//	return Integer(a + b.GetValue());
//}

// iostrem overload
ostream& operator << (ostream& out, const Integer& a) {
	out << a.GetValue();
	return out;
}
std::istream& operator >> (std::istream& in, Integer& a) {
	int x;
	in >> x;
	// sinc e this fn is now a friend. no need to use SetValue
	//a.SetValue(x);
	//*a.m_pInt = x; // friend variable 
	return in;
}

void TestCinAndCoutOverloading() {
	Integer a = Add(4, 9);
	//	Integer aMoreEfficient = AddMoreEfficient(4, 9);
	//	StdMoveFunction();

	Integer d = 5 - 7;
	//Integer e = 6 + a;
	//Integer f = a + 6;
	cout << "The value os 5 - 7 is: " << d << endl;
	std::cin >> d;
	// invoke funtion call operator
	d();
}






int main() {
	// using the overloaded + operator
	// CopyConstructorSynthesize();
//	MoveConstructorSynthesize();
	//TestSmartPointer();

	CreateInteger();
	return 0;
}
