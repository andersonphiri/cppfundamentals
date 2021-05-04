#include "IOStream.h"
#include "MultipeInheritanceDemo.h"

void TestMultipleInheritance() {
	IOStream stream("dic.log");
	std::string data;
	stream >> data; // read data fromuser
	stream << data << std::endl;
	stream << stream.GetFileName() << std::endl;
}