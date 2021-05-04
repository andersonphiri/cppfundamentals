#include "Account.h"
#include <iostream>
int Account::s_ANGenerator = 1000;
float Account::GetInterestRate() const
{
    return 0.0f;
}

Account::Account(const std::string& name, float balance) : m_Name(name), m_Balance(balance)
{
    m_AccNo = ++s_ANGenerator;
}

Account::Account()
{
}

Account::~Account()
{
}

const std::string Account::GetName() const
{
    return m_Name;
}

float Account::GetBalance() const
{
    return m_Balance;
}

int Account::GetAccountNo() const
{
    return m_AccNo;
}

void Account::AccumulateInterest()
{
}

void Account::Withdraw(float amount)
{
    if (m_Balance > amount)
    {
        m_Balance -= amount;
        return;
    }
    std::cout << "Insufficient balance" << std::endl;
}

void Account::Deposit(float amount)
{
    m_Balance += amount;
}
