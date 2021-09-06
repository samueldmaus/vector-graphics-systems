#include "WindowsBitmapDecoder.h"

namespace BitmapGraphics
{
	HBitmapDecoder WindowsBitmapDecoder::clone(std::istream& sourceStream)
	{
		return HBitmapDecoder();
	}
	
	HBitmapDecoder WindowsBitmapDecoder::createIterator()
	{
		return HBitmapDecoder();
	}
	
	std::string WindowsBitmapDecoder::getMimeType()
	{
		return std::string();
	}
	
	bool WindowsBitmapDecoder::isSupported()
	{
		return false;
	}
	
}
