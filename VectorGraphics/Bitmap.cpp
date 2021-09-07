#include "Bitmap.h"
#include "binary_ostream_iterator.h"
#include "BitmapIterator.h"

namespace BitmapGraphics
{

	Bitmap::Bitmap(int w, int h, std::istream& sourceStream) : width(w), height(h)
	{
		read(sourceStream);
	}

	Bitmap::Bitmap(int w, int h) : width(w), height(h)
	{
	}

	void Bitmap::read(std::istream& sourceStream)
	{
		for (auto i = 0; i < height; ++i)
		{
			ScanLine line;

			for (auto h = 0; h < width; ++h)
			{
				line.push_back(Color::read(sourceStream));
			}

			scanLineCollection.push_back(line);
		}
	}

	void Bitmap::write(std::ostream& destinationStream)
	{
		for (const auto& scanLine : scanLineCollection)
		{
			// Write row of pixels
			std::copy(scanLine.begin(), scanLine.end(), binary_ostream_iterator<Color>(destinationStream));

			// Write pad bytes
			for (auto pad = 0; pad < getNumberOfPadBytes(); ++pad)
			{
				Binary::Byte(0).write(destinationStream);
			}
		}
	}

	int Bitmap::getWidth() const
	{
		return width;
	}

	int Bitmap::getHeight() const
	{
		return height;
	}

	int Bitmap::getNumberOfPadBytes() const
	{
		const auto remainder = (width * 3) % 4;
		return (remainder == 0) ? 0 : (4 - remainder);
	}

	HBitmapIterator Bitmap::createIterator()
	{
		return std::make_unique<BitmapIterator>(*this);
	}

}
