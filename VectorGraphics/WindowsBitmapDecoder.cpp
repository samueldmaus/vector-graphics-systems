#include "WindowsBitmapDecoder.h"
#include "WindowsBitmapHeader.h"

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
		if (&stream == nullptr)
		{
			throw std::invalid_argument("No bitmap available");
		}
		const WindowsBitmapHeader header(stream);
		
		myBitmap = std::make_unique<Bitmap>(header.getBitmapWidth(), header.getBitmapHeight());
		myBitmap->read(stream);
		
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
