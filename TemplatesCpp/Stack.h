#pragma once
#include <vector>
#include <iostream>
template<typename T, int size>
class Stack
{
private:
	std::vector<T> m_Buffer{};
	int m_top{ -1 };
public:
	void Push(const T& data);
	const T& Peek();
	bool IsEmpty() const;
	const T& Pop();
	static Stack Create() {
		return Stack<T, size>();
	}
};


