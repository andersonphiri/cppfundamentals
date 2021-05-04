#include <iostream>
#include "Car.h"
using namespace std;

void Move(Point from, Point to) {

}

void TestCarClass() {
	Car car;
	Car ca1(44.6);
	Car* car2 = new Car(37.45f);
	const Car car4(55); // can invoke only const member functions
	car2->Accelerate();
	car.Dashboard();
	car.FillFuel(30);
	car.AddPassenger(2);
	car.Accelerate();
	car.Brake();
	car4.Dashboard();
	Point* start = new Point();
	start->x = 33;
	start->y = -23;
	Point end;
	end.x = 540;
	end.y = 5140;
}


int main() {
	//
	//CustomInteger a(1), b(2);
	//a.SetValue(Add(a, b).GetValue());
	//auto c(std::move(a)); // after this line a is no longer usable
	return 0;

}