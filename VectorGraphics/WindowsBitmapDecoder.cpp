#include "WindowsBitmapDecoder.h"
#include "WindowsBitmapHeader.h"

#include <iostream>
#include <sstream>

#include "WindowsCommon.h"

namespace BitmapGraphics
{
	std::istringstream blank{};

	WindowsBitmapDecoder::WindowsBitmapDecoder() : stream(blank)
	{
		stream.setstate(std::ios::badbit);
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
		if (stream.bad())
		{
			throw std::invalid_argument("No bitmap available");
		}
		const WindowsBitmapHeader header(stream);

		myBitmap = std::make_unique<Bitmap>(header.getBitmapWidth(), header.getBitmapHeight());
		for (auto row = 0; row < myBitmap->getHeight(); ++row)
		{
			Bitmap::ScanLine scanLine;

			// Read row of pixels
			for (auto column = 0; column < myBitmap->getWidth(); ++column)
			{
				scanLine.push_back(Color::read(stream));
			}

			// Read and ignore pad bytes (if any)
			for (auto pad = 0; pad < numberOfPadBytes(myBitmap->getWidth()); ++pad)
			{
				Binary::Byte::read(stream);
			}

			myBitmap->addScanLine(scanLine);
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
