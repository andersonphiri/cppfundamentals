#pragma once

class Animal {
public :
	void Eat() {
		std::cout << "Animal is Eating" << std::endl;
	}

	void Run() {
		std::cout << "Animal is Running" << std::endl;
	}

	
};
// child class Dog

class Dog : public Animal{
public:
	void Speak() {
		std::cout << "Die hond is raserig" << std::endl;
	}
	void Eat() {
		std::cout << "Dog is Eating beef" << std::endl;
	}
};

void DemoBasicInheritance();
