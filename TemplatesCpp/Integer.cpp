#include "Integer.h"
#include <iostream>
using namespace std;
Integer::Integer()
{
	cout << "Integer()" << endl;
	m_pInt = new int(0);
}

int Integer::GetValue() const
{
	return *m_pInt;
}

Integer::Integer(int value)
{
	cout << "Integer(int value)" << endl;
	m_pInt = new int(value);
}

void Integer::SetValue(int value)
{
	if (m_pInt == nullptr)
		m_pInt = new int{};
	*m_pInt = value;
}

Integer::~Integer()
{
	cout << "~Integer()" << endl;
	delete m_pInt;
}

Integer::Integer(const Integer& source)
{
	cout << "Integer(const Integer& source)" << endl;
	// create a deep copy
	m_pInt = new int(*source.m_pInt);
}

Integer::Integer(Integer&& source)
{
	cout << "Integer(Integer&& source)" << endl;
	m_pInt = source.m_pInt;
	source.m_pInt = nullptr;
}

Integer Integer::operator+(const Integer& a) const
{
	Integer temp;
	*temp.m_pInt = *m_pInt + *a.m_pInt;
	return temp;
}

Integer Integer::operator++()
{
	++(*m_pInt);
	return *this;
}

Integer& Integer::operator++(int)
{
	Integer temp(*this); // store current of this
	++(*m_pInt); // the increment
	return temp;

}

bool Integer::operator==(const Integer& source) const
{
	return *m_pInt == *source.m_pInt;
}

Integer& Integer::operator=(const Integer& a)
{
	cout << "operator=(const Integer& a)" << endl;
	if (this != &a)
	{
		delete m_pInt;
		m_pInt = new int(*a.m_pInt);
	}
	return *this;
}

Integer& Integer::operator=(Integer&& a)
{
	cout << "operator=(const Integer&& a)" << endl;
	if (this != &a)
	{
		delete m_pInt;
		m_pInt = a.m_pInt;
		a.m_pInt = nullptr;
	}
	return *this;
}

void Integer::operator()()
{
	std::cout << *m_pInt << std::endl;
}

Integer::operator int()
{
	return *m_pInt;
}
