#pragma once
#include "Integer.h"
class Number
{
	Integer m_Value{};
public:
	Number(int value) : m_Value{value} {}
	// if you provide a custom move then there won't be any auto move from compiler / some codes won't compile
	//Number(Number && n):m_Value{std::move(n.m_Value)}{}
	// to fix it. use default
	Number (Number&&n) = default; // this will provide support for move and not for copy
	Number(const Number& n) = default;
	Number& operator = (Number&& n) = default;
	Number& operator = (const Number&) = default;
};

