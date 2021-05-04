#include "Transaction.h"
#include <iostream>
using namespace std;
void Transact(Account* pAccount) {

	cout << "Transaction has started" << endl;
	cout << "initial balance: " << pAccount->GetBalance() << endl;
	pAccount->Deposit(450);
	pAccount->AccumulateInterest();
	if (typeid(*pAccount) == typeid(Checking))
	{
		Checking* pChecking = static_cast<Checking*>(pAccount);
		cout << "Minimum checking balance of checking: " << pChecking->GetMinimumBalance() << endl;
	}
	// alternatively
	Checking* pChecking2 = dynamic_cast<Checking*>(pAccount);
	if (pChecking2 != nullptr)
	{
		cout << "Minimum checking balance of checking 2 dynamic cast: " << pChecking2->GetMinimumBalance() << endl;
	}
	pAccount->Withdraw(300);
	cout << "Interest rate: " << pAccount->GetInterestRate() << endl;
	cout << "Final Balance: " << pAccount->GetBalance() << endl;

}