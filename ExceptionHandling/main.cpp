#include <iostream>
#include "ExceptionHandlingDemo1.h"
using namespace std;
int main() {

	try
	{
		//ProcessRecords(numeric_limits<int>::max());
		ProcessRescordWithSmartPointersAndContainers(20);
	}
	catch (const std::runtime_error& rex) {
		cout << rex.what() << endl;
	}
	catch (const std::bad_alloc& bex) {
		cout << bex.what() << endl;
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}
	//catch all block
	catch (...) {

	}


	return 0;


}