#pragma once
#include "Stream.h"
class OutputStream : virtual public Stream {
	std::ostream& out;
public:
	OutputStream(std::ostream& out, const std::string& fileName);
	std::ostream& operator << (const std::string& data);
	~OutputStream();

};

