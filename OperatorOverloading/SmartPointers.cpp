#include <iostream>
#include "Integer.h"
#include <memory>
using namespace std;

// RAII: Resource Aqcuisition As Initialization
class IntPtr
{
public:
	~IntPtr();
	IntPtr(Integer* p) : m_p(p) {}
	Integer* operator -> () {
		return m_p;
	}
	Integer& operator *() {
		return *m_p;
	}

private:
	Integer* m_p;
};

IntPtr::~IntPtr()
{
	delete m_p;
}

void TestSmartPointer() {
	IntPtr p = new Integer;
	p->SetValue(67);
}

void TestSmartPointer2() {
	IntPtr p = new Integer;
	p->SetValue(67);
	(*p).SetValue(78);
}


void CreateInteger() {
	//Integer* p = new Integer;
	//p->SetValue(5);
	/*IntPtr p = new Integer;
	p->SetValue(8);
	cout << p->GetValue() << endl;*/
	//delete p;
	TestSmartPointer2();
}
void Process(std::unique_ptr<Integer> ptr) {
	std::cout << ptr->GetValue() << std::endl;
}

void ProcessSharedResource(std::shared_ptr<Integer> ptr) {
	std::cout << ptr->GetValue() << std::endl;
}

void CastingBetweenBasicTypes() {
	int a{ 7 }, b{ 4 };
	float discouraged_c_type_casting = (float)a / b;
	float c = static_cast<float>(a) / b;
	// to cast a char from and to int use reinterpret_cast
	char* p = reinterpret_cast<char*>(&a);
	// const cast
	int x = 5;
	int* q = const_cast<int*>(&x);

}

void Print(const Integer & a) {}
void CastingBetweenCustomTypesAndPrimitiveTypes() {
	Integer a1{ 4 };
	// initialization
	Integer a2 = 8;
	Print(a2);
	//Assignment
	a1 = 9;
	// now we can cast back and forth
    //int j = a2;
	// or use static cast
	int k = static_cast<int>(a2); // 

}

void CreateSmartPointer() {
	std::unique_ptr<Integer> p(new Integer);
	//auto p2(p);
	(*p).SetValue(45);
	Process(std::move(p)); // we have take a resource from this ptr
	// however ptr is no longer usable
	// to share data use a shared pointer
	std::shared_ptr<Integer> sp(new Integer);
	sp->SetValue(88);
	ProcessSharedResource(sp);


}