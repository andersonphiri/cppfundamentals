#include "IOStream.h"

IOStream::IOStream(const std::string& filename) : OutputStream(std::cout, filename)
, InputStream(std::cin, filename), Stream(filename)
{
	std::cout << "IOStream(const std::string& filename)" << std::endl;
}

IOStream::~IOStream()
{
	std::cout << "~IOSTream()" << std::endl;
}
