#include "WindowsBitmapEncoder.h"

#include "WindowsBitmapHeader.h"

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
		if(myBitmapIterator.get() == nullptr)
		{
			throw std::invalid_argument("No bitmap iterator");
		}
		
		WindowsBitmapHeader header;
		header.setBitmapHeight(myBitmapIterator->getBitmapHeight());
		header.setBitmapWidth(myBitmapIterator->getBitmapWidth());
		header.setBitmapFileSize(((myBitmapIterator->getBitmapWidth() * 3) + 31) / 32 * 4);
		header.write(destinationStream);
	}
	
	std::string WindowsBitmapEncoder::getMimeType()
	{
		return "image/x-ms-bmp";
	}
	
}
