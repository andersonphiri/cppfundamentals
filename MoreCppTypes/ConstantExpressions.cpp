#include <iostream>

constexpr int GetNumber() {
	return 45;
}

constexpr int Max(int x, int y) {
	if (x >=y)
	{
		return x;
	}
	return y;
}

int GetNumberRuntime() {
	return 35;
}
void TestConstantExpression() {
	constexpr int i = 10;
	int arr[i];
	// will not work because the function will not be evaluated at compile time
	 int j = GetNumberRuntime();
	// wow works. some const are not evaluated at compile time
	const int jb = GetNumberRuntime();

	// but this will work with const expre
	constexpr int k = GetNumber(); // evaluated at compile time

	int l = GetNumber(); // no loger a constexpr and func is evaluated at runtime
}