#include "Bitmap.h"

namespace BitmapGraphics
{
	
	Bitmap::Bitmap(uint32_t w, uint32_t h, std::istream& sourceStream) : width(w), height(h)
	{
	}
	
	void Bitmap::write(std::ostream& destinationSource)
	{

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
