#include<memory>
#include <iostream>
#include "WeakPointersFix.h"
class Printer
{
public:
	Printer();
	~Printer();
	void SetValue(std::weak_ptr<int> p) {
		m_pValue = p;
	}
	void Print() {
		std::cout << "The count is : " << m_pValue.use_count() << std::endl;
		if (m_pValue.expired())
		{
			std::cout << "Resource is no longer available " << std::endl;
			return;
		}
		auto sp = m_pValue.lock();
		std::cout << "Value is: " << *sp << std::endl;
		std::cout << "The count is : " << sp.use_count() << std::endl;
	}

private:
	std::weak_ptr<int> m_pValue{};
};

Printer::Printer()
{
}

Printer::~Printer()
{
}




void TestWeakPointerFix() {
	Printer prn;
	int num{};
	std::cin >> num; // set a value more than 10 and see that the two are not in sync
	std::shared_ptr<int> p{ new int{ num } };
	prn.SetValue(p);
	if (*p > 10)
	{
		p = nullptr;
	}
	prn.Print();
}

// circular reference problem
class Employeee;
class Projects {
public:
	std::shared_ptr<Employeee> m_emp;
	Projects() {
		std::cout << "Project()" << std::endl;
	}
	~Projects() {
		std::cout << "~Project()" << std::endl;
	}
};
class Employeee {
public:
	std::weak_ptr<Projects> m_prj;
	Employeee() {
		std::cout << "Employeee()" << std::endl;
	}
	~Employeee() {
		std::cout << "~Employeee()" << std::endl;
	}
};


void SimulateMemoryLeakFromCircularReferences() {
	std::shared_ptr<Employeee>emp{ new Employeee{} };
	std::shared_ptr<Projects>prj{ new Projects{} };
	emp->m_prj = prj;
	prj->m_emp = emp;
}