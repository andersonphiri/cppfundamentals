#pragma once
#include "Account.h"

/// <summary>
/// The checking account mandates that no withdrawal is allowed if the new balance will be less
/// or equal to 50
/// </summary>
class Checking :
    public Account
{
private:
    float m_MinimuBalance;
public:
   // using Account::Account;
    Checking(const std::string& name, float balance, float minbalance);
    ~Checking();
    void Withdraw(float amount) override final;
    float GetMinimumBalance() const;
};

