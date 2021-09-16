#include "BasicCanvas.h"

#include "BasicCanvasBitmapIterator.h"

namespace BitmapGraphics
{
	BasicCanvas::BasicCanvas(int w, int h, const Color& bg) : width(w), height(h), backgroundColor(bg)
	{
	}
	
	void BasicCanvas::setPixelColor(VG::Point const& location, Color const& color)
	{
		if(outsideDimensions(location))
		{
			throw std::invalid_argument("The pixel is outside of the dimensions of the canvas");
		}

		const auto iterator = pixelMap.find(location);
		if(iterator != pixelMap.end())
		{
			iterator->second = color;
		}
	}

	Color BasicCanvas::getPixelColor(VG::Point const& location) const
	{
		if(outsideDimensions(location))
		{
			throw std::invalid_argument("The pixel is outside of the dimensions of the canvas");
		}

		const auto iterator = pixelMap.find(location);

		if(iterator == pixelMap.end())
		{
			return backgroundColor;
		}
		return iterator->second;
	}

	int BasicCanvas::getWidth() const
	{
		return width;
	}

	int BasicCanvas::getHeight() const
	{
		return height;
	}

	HBitmapIterator BasicCanvas::createBitmapIterator() const
	{
		return std::make_unique<BasicCanvasBitmapIterator>(*this);
	}

	bool BasicCanvas::outsideDimensions(const VG::Point& point) const
	{
		if(point.getX() > width || point.getY() > height)
		{
			return true;
		}
		return false;
	}
	
}
