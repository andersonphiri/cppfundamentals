#include "Stream.h"

Stream::Stream(const std::string& filename) : m_FileName(filename)
{
	std::cout << "Stream(const std::string& filename)" << std:: endl;
}

std::string  Stream::GetFileName() const
{
	return m_FileName;
}

Stream::~Stream()
{
	std::cout << "~Stream()" << std::endl;
}
