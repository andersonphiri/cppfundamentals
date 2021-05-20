#pragma once
#include <string>
#include "Integer.h"
#include <iostream>
class EmployeeForHash
{
private:
	std::string m_Name;
	Integer m_Id;
public: // perefect type forwarding
	template<typename T1, typename T2> EmployeeForHash(T1&& name, T2&& id) 
		: m_Name{std::forward<T1>(name)}
	, m_Id{ std::forward<T2>(id) }{
		std::cout << "Employee(T1&& name, T2&& id) " << std::endl;
	};

};

