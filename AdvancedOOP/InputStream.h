#pragma once
#include "Stream.h"
class InputStream : virtual public Stream {
	std::istream& in;
public :
	InputStream(std::istream& i, const std::string& filename);
	~InputStream();
	std::istream& operator >> (std::string& data);

};

