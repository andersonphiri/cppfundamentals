#include <iostream>
#include "Enums.h"
using namespace std;

void FillColor(Color color) {
	if (color == Color::BLACK)
	{
		std::cout << "The color is black" << std::endl;
	}
}