#include <iostream>
#include <vector>
template<typename T> class PrettyPrinter
{
	T* m_pData;

public:
	PrettyPrinter(T* data);
	void Print() {
		std::cout << "{" << *m_pData << "}" << std::endl;
	}
	~PrettyPrinter();
	T* GetData();

private:

};

template<typename T> PrettyPrinter<T>::PrettyPrinter(T* data) : m_pData{ data }
{
}

template<typename T> PrettyPrinter<T>::~PrettyPrinter()
{
	delete m_pData;
}

template<typename T>
T* PrettyPrinter<T>::GetData()
{
	return m_pData;
}
// specialization for char type

template<> class PrettyPrinter<char*> {
	char* m_pData;
public:
	PrettyPrinter(char * data) : m_pData{data} {}
	void Print() { std::cout << "{" << *m_pData << "}" << std::endl; }
	char* GetData() {
		return m_pData;
	}
};
// specialization for Vector type
template<> class PrettyPrinter<std::vector<int>> {
	std::vector<int> * m_pData;
public:
	PrettyPrinter(std::vector<int>* data) : m_pData{ data } {}
	void Print() { 
		std::cout << "{";
		for (const auto& num : *m_pData)
			std::cout << num;
		std::cout << "}" << std::endl; }
	std::vector<int>* GetData() {
		return m_pData;
	}
};

// partial specialization
template<typename T, int x>
class PrettyPrinterPartial {
private:
	T* m_pData;
public :
	PrettyPrinterPartial(T* data) : m_pData(data) {}
	void Print() {
		std::cout << "{" << *m_pData << "}" << std::endl;
		std::cout << "{" << x << "}" << std::endl;
	}
	~PrettyPrinterPartial() {
		delete m_pData;
	}
	T* GetData() {
		return m_pData;
	}
};

template<typename T>
class PrettyPrinterPartial<T, 80> {
private:
	T* m_pData;
public:
	PrettyPrinterPartial(T* data) : m_pData(data) {}
	void Print() {
		std::cout << "{" << *m_pData << "}" << std::endl;
		std::cout << "Using x = 80 columns" << std::endl;
	}
	~PrettyPrinterPartial() {
		delete m_pData;
	}
	T* GetData() {
		return m_pData;
	}
};

template<typename T>
class SmartPointer {
	T* m_ptr;
public:
	SmartPointer(T * data) :  m_ptr(data) {}
	T operator ->() {
		return m_ptr;
	}
	T & operator *() {
		return *m_ptr;
	}
	~SmartPointer() { delete m_ptr; }
};

// overloading / specialize for arrays
template<typename T>
class SmartPointer<T[]> {
	T* m_ptr;
public:
	SmartPointer(T* data) : m_ptr(data) {}
	T operator ->() {
		return m_ptr;
	}
	T& operator [](int index) {
		return m_ptr[index];
	}
	~SmartPointer() { delete[] m_ptr; }
};

