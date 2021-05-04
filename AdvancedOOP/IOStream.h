#pragma once
#include "InputStream.h"
#include "OutputStream.h"
class IOStream : public OutputStream, public InputStream {
public:
	IOStream(const std::string& filename);
	~IOStream();

};

