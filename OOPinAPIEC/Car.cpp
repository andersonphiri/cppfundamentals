#include "Car.h"
#include <iostream>
int Car::totalCount = 0;
void Car::FillFuel(float amount) {
	fuel = amount;
}
void Car::Accelerate() {
	speed += 20;
}
void Car::Brake() {
	speed = 0;
}

void Car::AddPassenger(int count) {
	passengers += count;
	Car::totalCount += count;
	//void(*fooPointer)(const Car &) = Foo;
	Foo(*this);
	//(*fooPointer)(*this);
}

void Car::Dashboard() const
{

}

void Car::ShowCount()
{
	using namespace std;
	cout << "The count is: " << totalCount << endl;
}

Car::Car() : Car(0, 1)
{
}
/// <summary>
/// Delegating constructor
/// </summary>
/// <param name="amount"></param>
Car::Car(float amount) : Car(amount,1)
{
}
Car::Car(float amount, int pass)
{
	++totalCount;
	fuel = amount;
	passengers = pass;
	speed = 0;
}
Car::~Car()
{
}

void Car::Foo(const Car& car) {

}
