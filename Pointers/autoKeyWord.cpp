#include <iostream>

int sum(int x, int y) {
	return x + y;
}

int Auto_Example() {
	auto i = 45;
	auto j = 34;
	auto k{ 30 };
	auto m = 1 + i + j;
	auto z{ m + k + 45 };
	auto sums{ sum(j,j) };
	static auto autos = 44;
	auto list = {1, 2, 3, 4, 5 };
	// avooid using auto with rreference types
	return 0;
}