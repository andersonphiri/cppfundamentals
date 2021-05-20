#include <iostream>
#include <vector>
#include <list>
#include "IntroToLambdas.h"
#include <fstream>

void TestSorting() {
	int arr[]{ 8,2,5,7,30,44,-10 };
	for (auto x : arr) {
		std::cout << x << " ";
	}
	std::cout << std::endl;
	Sort(arr);
	for (auto x : arr) {
		std::cout << x << " ";
	}
	std::cout << std::endl;
}
bool Descend(int x, int y) {
	return x < y;
}

bool Ascend(int x, int y) {
	return x > y;
}

void TestSortingWithComparator() {
	int arr[]{ 8,2,5,7,30,44,-10 };
	for (auto x : arr) {
		std::cout << x << " ";
	}
	std::cout << std::endl;
	Sort(arr, Descend);
	for (auto x : arr) {
		std::cout << x << " ";
	}
	std::cout << std::endl;
}

void TestSortingWithFunctionObjects() {
	CompStruct cs;
	// invoke
	auto val = cs(5, -9);
	int arr[]{ 8,2,5,7,30,44,-10 };
	for (auto x : arr) {
		std::cout << x << " ";
	}
	std::cout << std::endl;
	// apply comp struct in sorting
	Sort(arr, cs);
	for (auto x : arr) {
		std::cout << x << " ";
	}
	std::cout << std::endl;
}

void LambdaExpressions() {
	[]() {
		std::cout << "Welcome to the lambdas";
	}
	// to invoke
		()
	;
	auto fn = []() {
		std::cout << "Welcome to the lambdas variable";
	};
	// to invoke fn
	fn();

	auto sum = [](int x, int y) -> double {
		return x + y;
	};
	std::cout << sum(45, 60) << std::endl;

	auto sumGeneric = [](auto x, auto y) noexcept(false) {
		return x + y;
	};
}

void TestCustomForEachWithCallback() {

	int arr[]{ 1,23,4,5,6 };
	ForEach(arr, [](auto x) {
		std::cout << x << " ";
		});
}

void TestCustomForEachWithCallbackAndMutableData() {

	int arr[]{ 1,23,4,5,6 };
	std::cout << "before add offset of 5 to eacdh item" << std::endl;
	ForEach(arr, [](auto x) {
		std::cout << x << " ";
		});
	int offset = 5;
	std::cout << "add offset of 5 to eacdh item" << std::endl;
	ForEach(arr, [offset](auto &x) {
		x += offset;
		});
	ForEach(arr, [](auto x) {
		std::cout << x << " ";
		});
	std::cout << "After add increasing offset of 5 to eacdh item" << std::endl;
	int  offset2 = 5;
	ForEach(arr, [offset2](auto& x) mutable {
		x += offset2;
		++offset2;
		});
	ForEach(arr, [](auto x) {
		std::cout << x << " ";
		});

}

void GeneralizedCapture() {
	int x{ 5 };
	auto f = [y = x](int arg) -> int {
		return arg + y;
	};
	std::ofstream out{ "file.txt" };
	auto write = [out = std::move(out)](int x) mutable {
		out << x;
	};
	write(8900);
}


int main() {
	//TestSorting();
	// TestSortingWithComparator();
	// TestSortingWithFunctionObjects();
	// TestCustomForEachWithCallback();
	// TestCustomForEachWithCallbackAndMutableData();
	GeneralizedCapture();
	return 0;
}
//  https://subscription.packtpub.com/video/programming/9781800566668/p13/video13_5/lambda-expressions-capture-list-part-i