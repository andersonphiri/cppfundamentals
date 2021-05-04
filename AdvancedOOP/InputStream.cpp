#include "InputStream.h"

InputStream::InputStream(std::istream& i, const std::string& filename) : in(i), Stream(filename)
{
	std::cout << "InputStream(std::istream& i, const std::string& filename)" << std::endl;
}

InputStream::~InputStream()
{
	std::cout << "~InputStream()" << std::endl;
}

std::istream& InputStream::operator>>(std::string& data)
{
	// TODO: insert return statement here
	in >> data;
	return in;
}
