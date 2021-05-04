#pragma once
#include <iostream>
#include <string>

class Stream {
	std::string m_FileName;
public:
	Stream(const std::string& filename);
	std::string  GetFileName() const;
	~Stream();

};

