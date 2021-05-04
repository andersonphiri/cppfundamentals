#include "OutputStream.h"

OutputStream::OutputStream(std::ostream& o, const std::string& fileName) : out(o), Stream(fileName)
{
	std::cout << "OutputStream(std::ostream& o, std::string& fileName)" << std::endl;
}

std::ostream& OutputStream::operator<<(const std::string& data)
{
	// TODO: insert return statement here
	out << data;
	return out;
}

OutputStream::~OutputStream()
{
	std::cout << "~OutputStream()" << std:: endl;
}
