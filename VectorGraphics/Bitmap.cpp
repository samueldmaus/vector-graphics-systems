#include "Bitmap.h"
#include "binary_ostream_iterator.h"

namespace BitmapGraphics
{

	Bitmap::Bitmap(int w, int h, std::istream& sourceStream) : width(w), height(h)
	{
		read(sourceStream);
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

	void Bitmap::write(std::ostream& destinationSource)
	{
		for (const auto& line : scanLineCollection)
		{
			std::copy(line.begin(), line.end(), binary_ostream_iterator<Color>(destinationSource));
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

}
