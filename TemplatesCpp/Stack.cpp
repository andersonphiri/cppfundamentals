#include "Stack.h"
#include <vector>
#include <iostream>
//template<typename T>
//class Stack
//{
//private:
//	std::vector<T> m_Buffer{};
//	int m_top{ -1 };
//public:
//	void Push(const T& data) {
//		m_Buffer[++m_top] = data;
//	};
//	const T& Peek() {
//		return m_Buffer[m_top];
//	}
//	bool IsEmpty() const {
//		return m_top == -1;
//	}
//	const T& Pop() {
//		// TODO: insert return statement here
//		T res = m_Buffer[m_top--];
//		return res;
//	}
//};

template<typename T, int size> const T& Stack<T, size>::Peek()
{
	// TODO: insert return statement here
	return m_Buffer[m_top];
}

template<typename T, int size>
bool Stack<T, size>::IsEmpty() const
{
	return m_top == -1;
}

template<typename T, int size>
const T& Stack<T, size>::Pop()
{
	T res = m_Buffer[m_top--];
	return res;
}

template<typename T, int size>
void Stack<T, size>::Push(const T & data)
{
	m_Buffer[++m_top] = data;
}
