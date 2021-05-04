#include<memory>
#include <iostream>
#include "WeakPontersProblem.h"

class PrinterP
{
public:
	PrinterP();
	~PrinterP();
	void SetValue(int* p) {
		m_pValue = p;
	}
	void Print() {
		std::cout << "Value is: " << *m_pValue << std::endl;
	}

private:
	int* m_pValue{};
};

PrinterP::PrinterP()
{
}

PrinterP::~PrinterP()
{
}



void WeakPointerProblemDemo() {
	PrinterP prn;
	int num{};
	std::cin >> num; // set a value more than 10 and see that the two are not in sync
	int* p = new int{ num };
	prn.SetValue(p);
	if (*p > 10)
	{
		delete p;
		p = nullptr;
	}
	prn.Print();
	delete p;
}