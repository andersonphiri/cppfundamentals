#include <iostream>
#include "Employee.h"
#include "Stack.h"
#include "PrettyPrinterDemo.cpp"
#include "TypeAliases.h"


// primary template
template<typename T> T Max(T x, T y) {
	return x > y ? x : y;
}

// Note: Expliciting must be done inside cpp file and not header file
// to compare chars we need to explicit specialize the max function as follows
//Explicit instantiation
template char Max(char x, char y);

// explicit specialization
template<> const char* Max<const char*>(const char* x, const char* y) {
	return strcmp(x, y) > 0 ? x: y;
}

// non type template arguments should be const expressions ie cannot be edited
template<int size>
void PrintNonType() {
	std::cout << "Non Type value is: " << size << std::endl;
}
// sum of numbers in an array
template<typename T> T Sum(T* pArr, int size) {
	T sum{};
	for (size_t i = 0; i < size; i++)
	{
		sum += pArr[i];
	}
		
	return sum;

}

template<typename T, int size> T SumWithoutArraySizeParam(T (&pArr)[size]) {
	T sum{};
	for (size_t i = 0; i < size; i++)
	{
		sum += pArr[i];
	}

	return sum;

}

void TestMaxVariations() {
	int max = Max(55, 76);

	std::cout << "The max is: " << max << std::endl;
	const char* a{ "A" };
	const char* b{ "B" };

	std::cout << "The max of A and B is: " << Max(a, b) << std::endl;
	PrintNonType<54>();
	int arr[]{ 12,8,40, 30 };
	std::cout << Sum(arr, 4) << std::endl;
	// reference to an array
	// int(&ref)[4] = arr;
	std::cout << SumWithoutArraySizeParam(arr) << std::endl;
}


template<typename T1, typename T2> EmployeeForHash* Create(T1&& a, T2&& b) {
	return new EmployeeForHash(a, std::forward<T2>(b));
}
void TestPerfectTypeForwarding() {
	//Employee emp1{ "Umar", Integer{340} };
	//Integer va{ 30 };
	//Employee emp2{ std::string{"andy"} , va };

	auto v = Create("Andy", Integer{ 120 });
}

// base case for template parameter pack
void Print() {
	std::cout << std::endl;
}

// Template parameter pack
template<typename T, typename...Params> 
// function paramter pack. uses recursion
void Print(const T&& a, const Params &&... kwargs) {
	std::cout  << a;
	if (sizeof...(kwargs) != 0)
	{
		std::cout << " , ";
	}
	Print(std::forward<Params>(kwargs)...);
}

void TestPrintRecursion() {
	//Print(const int{ 10 }, const int{ 230 });
}

void TestStack() {

	//Stack<int, 20> stack;
	//int a{ 23 };
	//int b{ 23 };
	//int c{ 21 };
	///*stack.Push();
	//stack.Push(9);
	//stack.Push(3);*/
	//while (!stack.IsEmpty())
	//{
	//	std::cout << stack.Pop() << std::endl;
	//}
}

void TestClasTemplateExSpecialization() {
	// const char* p0 (std::string{ "hello anderson" }.c_str());
	  char  *p3 = new char[20];
	  strcpy_s(p3, 20, "hello anderson");
	PrettyPrinter<char*> p(p3); // before creating a specialized template for char: PrettyPrinter<char*> p(&p3);
	//PrettyPrinter<char*> p4(&p0);
	p.Print();
	//
	std::vector<int> ints{ 1,2,3,4,5 };
	PrettyPrinter<std::vector<int>> pp(&ints);
	pp.Print();
	std::string str{ "testing 123" };
	PrettyPrinterPartial<std::string, 80>p6{ &str };
	p6.Print();
}

void TestSmartPointer() {
	SmartPointer<int> sp1{ new int(9) };
	std::cout << *sp1 << std::endl;
	SmartPointer<int[]> sp2{ new int[5] };
	sp2[0] = 89;
	std::cout << sp2[0] << std::endl;
}

void TestALiasesAndTypeDef() {
	PFN pfn = GetErrorMessage;
	ShowErrorUnsimplified(pfn);
	std::cout << Divide(5, 3) << std::endl;
}

void TestTraits() {
	Check(50);
	int value{ 50 };
	Check(value);
}

int main() {

	//TestMaxVariations();
	//TestPerfectTypeForwarding();
	// TestPrintRecursion();
	//TestStack();
	//TestClasTemplateExSpecialization(); todo: please check, its throwing an error
	// TestSmartPointer();
	//TestALiasesAndTypeDef();
	TestTraits();
	return EXIT_SUCCESS;
}