#include "Integer.h"
#include "SmartPointers.h"
#include <iostream>
void Display(Integer* p) {
	if (!p)
	{
		return;
	}
	std::cout << p->GetValue() << std::endl;
}

Integer* GetPointer(int value) {
	Integer* p = new Integer{ value };
	return p;
}

void Operate(int value) {
	Integer* p = GetPointer(value);
	if (p == nullptr)
	{
		p = new Integer{};
	}
	p->SetValue(230);
	Display(p);
	delete p;
	p = nullptr;
	p = new Integer;
	*p = __LINE__;
	Display(p);
	delete p;
}

void Store(std::unique_ptr<Integer> &p) {
	std::cout << "Storing data to the file..." << std::endl;
}

void OperateUsingUniquePointer(int value) {
	std::unique_ptr<Integer> p{ GetPointer(value) };
	if (p == nullptr)
	{
		p.reset(new Integer{ value });
	}
	p->SetValue(230);
	Display(p.get()); // gets the underlying pointer to the unique pointer
	//delete p;
	p = nullptr;
	//p = new Integer;
	p.reset(new Integer{ });
	*p = __LINE__;
	Display(p.get());
	Store(p);
	*p = 200;
	//delete p;
}