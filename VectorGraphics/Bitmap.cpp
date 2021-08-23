#include "Bitmap.h"

namespace BitmapGraphics
{
	
	Bitmap::Bitmap(int w, int h, std::istream& sourceStream) : width(w), height(h)
	{
		read(sourceStream);
	}
	
	void Bitmap::read(std::istream& sourceStream)
	{
		for(auto i = 0; i < width; ++i)
		{
			scanLineCollection.emplace_back(Color::read(sourceStream));
		}
	}

	//void Bitmap::write(std::ostream& destinationSource)
	//{
	//	for(const auto& line : scanLineCollection)
	//	{
	//		std::copy(scanLineCollection.begin(), scanLineCollection.end(), std::ostream_iterator<Color>(destinationSource));
	//	}

	//}

	int Bitmap::getWidth() const
	{
		return width;
	}
	
	int Bitmap::getHeight() const
	{
		return height;
	}
	
}
