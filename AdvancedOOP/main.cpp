#include <iostream>
#include "BasicInheritance.h"
#include <string>
#include "Account.h"
#include "Checking.h"
#include "Savings.h"
#include "Transaction.h"
#include <memory>
#include "MultipeInheritanceDemo.h"
using namespace std;
// test account class

void TestAccount() {
	Account acc("anderson Phiri", 3400);
	std::cout << "Initial Balance: " << acc.GetBalance() << " Acount Number: " << acc.GetAccountNo() << std::endl;
	acc.Deposit(5000);
	acc.Withdraw(280);
	std::cout << "Initial Balance: " << acc.GetBalance() << " Acount Number: " << acc.GetAccountNo() << std::endl;
}

void TestCheckingAccount() {
	Checking acc("andy chikuse", 980, 200);
	std::cout << "Initial Balance: " << acc.GetBalance() << " Acount Number: " << acc.GetAccountNo() << std::endl;

	acc.Withdraw(950);
	Transact(&acc);
}

void TestSavings() {
	Savings acc("David Gomani", 56000, .10);
	Transact(&acc);
}

// Note: the base class object must be a pointer or a reference 
// for you to be able to cast up
void TestCasting() {
	Checking ch("Bob", 200, 50);
	// up casting
	std::shared_ptr<Account> pAccount{ &ch };
	//or
	Account* pAccount2 = &ch;
	// Downcasting
	auto pChecking = static_pointer_cast<Checking>(pAccount);
	Checking* pChecking2 = static_cast<Checking*>(pAccount2);
}

void ObjectSlicingDemo() {
	Account a;
	Checking ch("Bob", 200, 30);
	a = ch;
}

void TestTypeInformation() {
	int a{ 45 };
	float b{ 52.03f };
	const std::type_info& ti = typeid(a);
	const std::type_info& tib = typeid(b);
	cout << "The type of a is: " << ti.name() << " and raw name is: " << ti.raw_name() << endl;
	cout << "The type of b is: " << tib.name() << " and raw name is: " << tib.raw_name() << endl;
	Checking ch("Bob", 200, 50);
	// up casting
//	std::shared_ptr<Account> pAccount{ &ch };
	Account* pAccount = &ch; 
	//const std::type_info& tiAcc = typeid(a);
	if (typeid(*pAccount) == typeid(Checking))
	{
		cout << "Pointing to checking account " << endl;
	}
	else {
		cout << "Not pointing to checkig account" << endl;
	}
}

int main() {
	try
	{
		//DemoBasicInheritance();
	// TestAccount();
	//	TestCheckingAccount();
		//TestSavings();
		//TestTypeInformation();
		TestMultipleInheritance();
	}
	catch (const std::exception& ex)
	{
		cout << "Error: " << ex.what() << endl;
	}
	return 0;
}