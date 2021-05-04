// single line comment
/*
multiple lines
*/
#include <iostream>
int main() {
	using namespace std;
	//types
	char ch = '0';
	bool flag = 0;
	bool flag2 = 20;
	bool flag3{ (bool)-4 };
	if (flag)
	{
		cout << "Flag is " << flag << endl;
	}
	if (flag2)
	{
		cout << "Flag2 is " <<  flag2 << endl;
	}
	if (flag3)
	{
		cout << "Flag3 is "  << flag2 << endl;
	}
	// Vector types
	int arr[5];
	int arr2[5]{ 1,2,3,4,5 };

	cout << "Hello C++" << endl << "what you going to do" << endl;
	return 0;
}