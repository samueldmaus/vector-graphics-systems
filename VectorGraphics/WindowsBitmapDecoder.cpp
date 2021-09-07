#include "WindowsBitmapDecoder.h"

#include <iostream>
#include <sstream>

namespace BitmapGraphics
{
	std::istringstream blank;

	WindowsBitmapDecoder::WindowsBitmapDecoder() : stream(blank)
	{
	}

	WindowsBitmapDecoder::WindowsBitmapDecoder(std::istream& sourceStream) : stream(sourceStream)
	{
	}

	HBitmapDecoder WindowsBitmapDecoder::clone(std::istream& sourceStream)
	{
		return std::make_unique<WindowsBitmapDecoder>(sourceStream);
	}

	HBitmapIterator WindowsBitmapDecoder::createIterator()
	{
		if (myBitmap.get() == nullptr && stream.gcount() == 0)
		{
			throw std::invalid_argument("No bitmap available");
		}
		return myBitmap->createIterator();
	}

	std::string WindowsBitmapDecoder::getMimeType()
	{
		return "image/x-ms-bmp";
	}

	bool WindowsBitmapDecoder::isSupported(const std::string& chunk)
	{
		if (chunk[0] == 'B' && chunk[1] == 'M')
		{
			return true;
		}
		return false;
	}

}
