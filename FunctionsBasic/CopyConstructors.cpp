#include "CustomInteger.h"

// return value
CustomInteger AddWhichCreatesACopy1(int x, int y) {
	return  CustomInteger(x + y);
}
// pass by value
int Print(CustomInteger x) {
	return 0; // x.GetValue() + y.GetValue();
}
void VoidWhichCreatesACopy3() {
	CustomInteger x(50);
	CustomInteger y(x); // dangerous. this will cause a constructor to synthesize a copy constructor even though we don't have one in our clss definition
}

void TestCopyConstructors() {
	//the 3 methods are very dangerous as they are creating copies of the object
	// what will happen when the copy of this object is created ? DISASTER

	//shallow copy with pointers
	int* p1 = new int(40);
	int* p2 = p1; // this is shallow copy. this is only a copy of address.
	// any change made will reflect in all shallow copies

	// DEEP should be the way to achieve uniqueness
	int* deepCopy = new int(*p1);
	// https://subscription.packtpub.com/video/programming/9781800566668/p4/video4_11/delegating-constructors-c-11

}