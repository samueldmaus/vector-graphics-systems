#include "WindowsBitmapDecoder.h"

namespace BitmapGraphics
{

	HBitmapDecoder WindowsBitmapDecoder::clone(std::istream& sourceStream)
	{
		return HBitmapDecoder();
	}
	
	HBitmapIterator WindowsBitmapDecoder::createIterator()
	{
		if(myBitmap.get() == nullptr)
		{
			throw std::invalid_argument("No bitmap available");
		}
		return myBitmap->createIterator();
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
