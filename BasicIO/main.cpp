#include <iostream>
int main() {
	using namespace std;
	cout << "Hello word \t" << 45.6f << endl;

	// input output
	int age;
	cout << "How old are you ? : ";
	cin >> age;
	cout << endl;
	char fullname[512];
	cout << "Please enter your full name: " << endl;
	//cin >> fullname;
	cin.getline(fullname, 512, '\n');
	cout << "you are " << 20 << " years old and FullName: " << fullname << endl;

	return 0;
}