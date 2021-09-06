#include "WindowsBitmapEncoder.h"

namespace BitmapGraphics
{
	WindowsBitmapEncoder::WindowsBitmapEncoder(HBitmapIterator i) : myBitmapIterator(std::move(i))
	{
	}
	
	HBitmapEncoder WindowsBitmapEncoder::clone(HBitmapIterator i)
	{
		return std::make_unique<WindowsBitmapEncoder>(std::move(i));
	}
	
	void WindowsBitmapEncoder::encodeToStream(std::ostream& destinationStream)
	{
	}
	
	std::string WindowsBitmapEncoder::getMimeType()
	{
		return "image/x-ms-bmp";
	}
	
}
