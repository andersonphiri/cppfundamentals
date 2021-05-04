#include <iostream>
#include <vector>
using namespace std;
int RangeBasedForLoop() {
	int arr[]{ 1, 2,3,4,5 };
	// this way you can mutate values
	for(auto & var : arr)
	{
		var = 3;
		cout << "Printing: " << var << endl;
	}
	// to non immutable , use const
	for (const auto& var : arr)
	{
		cout << "Printing: " << var << endl;
	}

	// inside range initializer

	for (const auto& var : {2, 4, 6, 8, 10})
	{
		cout << "Printing: " << var << endl;
	}

	return 0;
}

int IterateUsingPointers(int arr[]) {
	int* begin = &arr[0];
	int* begin2 = arr;
	int* end = &arr[size_t(arr)];
	while (begin != end)
	{
		cout << "The value is: "<< *begin << endl;
		++begin;
	}

	return 0;
}
// continue : https://subscription.packtpub.com/video/programming/9781800566668/p2/video2_18/function-overloading
int IterateUsingPointersWithBuiltInFunctions(int arrSource[]) {
	int arr[] = { 1,2,3,4,5 };
	auto &&range = arr;
	auto beg = begin(arr);
	auto last = end(arr);
	for( ; beg != last; ++beg )
	{
		auto value = *beg;
	}

	return 0;
}