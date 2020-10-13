#include "gepch.h"
#include "GEException.h"

namespace GE
{

	GEException::GEException(int line, const char* file) noexcept
		:
		line(line),
		file(file)
	{
	}
	const char* GEException::what() const noexcept
	{
		std::ostringstream oss;
		oss << GetType() << std::endl
			<< GetOriginString();
		whatBuffer = oss.str();
		return whatBuffer.c_str();
	}

	const char* GEException::GetType() const noexcept
	{
		return "JF Exception";
	}

	int GEException::GetLine() const noexcept
	{
		return line;
	}

	const std::string& GEException::GetFile() const noexcept
	{
		return file;
	}

	std::string GEException::GetOriginString() const noexcept
	{
		std::ostringstream oss;
		oss << "[File] " << file << std::endl
			<< "[Line] " << line;
		return oss.str();
	}

}
