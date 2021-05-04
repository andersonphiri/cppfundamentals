#pragma once
class CustomInteger
{
	int * m_pInt;

public:
	CustomInteger();
	CustomInteger(int value);
	int GetValue() const;
	void SetValue(int value);
	void SetValue(float unwantedValue) = delete; // bars people from passing float values to SetValue method but only allow integers
	// add destructor to free memory
	~CustomInteger();
	// custom copy constructors to enable deep copies. Note: use pass by reference and not by value. if you pass by value it will go into infinity loop
	// make it const so as to immuate changes by source
	CustomInteger(const CustomInteger &obj); //copy ctor
//	CustomInteger(const CustomInteger& obj) = default; // synthesises the copy ctor
	// default
	//CustomInteger(const CustomInteger& obj) = delete; // instructs the compiler not to synthesis the copy ctor
	CustomInteger(CustomInteger&& obj); // a move ctor. more efficient that the deep copy
	// OPERATOR OVERlOADING +
	CustomInteger operator +(const CustomInteger& a) const; // make it const since it does not affects the state of the object
	CustomInteger  operator ++();
	CustomInteger & operator ++(int);
	bool operator ==(const CustomInteger& obj) const;
	CustomInteger& operator = (const CustomInteger& a);
	// the move ctor comparison

	CustomInteger& operator = (CustomInteger&& a); // move
};

