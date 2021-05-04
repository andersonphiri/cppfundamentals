#include <iostream>

void NewDemo() {
	int* p = new int(50);
	*p = 23;
	std::cout << "The value of P is: " << *p << std::endl;
	// free up memory
	delete p;
	// null it as always
	p = NULL;
}
void NewForArrays() {
	int* arr = new int[5];
	for (size_t i = 0; i < size_t(arr); i++)
	{
		arr[i] = i;
	}
	//alternatively
	int* arr2 = new int[] {1, 2, 3, 4, 5};
	// then delete 
	delete[] arr;
	arr = NULL;
	delete[] arr2;
	arr2 = NULL;
	using namespace std;
	// atring arra
	char* p = new char[5];
	strcpy_s(p, 5, "Andy");
	cout << p << endl;
}

void NewFor2DArrays() {
	// simple approach
	int data[][3] = { 1,2,3,4,5,6 };
	// using pointer of pointers
	int* arr1 = new int[] {1, 2, 3, 4, 5};
	int* arr2 = new int[] {1, 2, 3, 4, 5};
	int** twoD = new int* [2];
	twoD[0] = arr1;
	twoD[1] = arr2;
	// accessing data is as normal
	twoD[0][1] = 5;
	// don't forget to delete in order
	delete[]arr1;
	delete[] arr2;
	delete[] twoD;
}

int main() {
	NewDemo();
	return 0;
}