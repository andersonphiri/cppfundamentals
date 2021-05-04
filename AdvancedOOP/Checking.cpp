#include "Checking.h"
#include <iostream>

Checking::Checking(const std::string& name, float balance, float minbalance) 
	: m_MinimuBalance(minbalance), Account(name, balance){ }

Checking::~Checking()
{
}

void Checking::Withdraw(float amount)
{
	if (m_Balance - amount > m_MinimuBalance)
	{
		Account::Withdraw(amount);
		return;
	}
	std::cout << "Invalid amount" << std::endl;
}

float Checking::GetMinimumBalance() const
{
	return m_MinimuBalance;
}
