#pragma once
class Integer
{
	int* m_pInt;
public:
	Integer() ;
	int GetValue() const;

	Integer(int value);

	void SetValue(int value);
	~Integer();
	// copy ctor
	Integer(const Integer& source);
	// move ctor
	Integer(Integer&& source) ;
	// operator overloading

	// + sign
	Integer operator +(const Integer& a) const;
	// ++ prefix sign
	Integer operator ++();
	// ++ postfix
	Integer & operator ++(int);
	// equality operator
	bool operator ==(const Integer& source) const;
	// copy ctor operator
	Integer& operator = (const Integer& a);

	// move operator
	Integer& operator = (Integer&& a) ;
	// function call operator
	void operator ()();

	/// friend function
	// friend std::istream& operator >> (std::istream& in, Integer& a);

	// to enable to cast this to primitive int
	explicit operator int();
};

