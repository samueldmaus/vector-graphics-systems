#include "BasicCanvasBitmapIterator.h"

namespace BitmapGraphics
{
	BasicCanvasBitmapIterator::BasicCanvasBitmapIterator(const ICanvas& canvas) : myCanvas(canvas), currentPoint(VG::Point(0, 0))
	{
	}

	
	void BasicCanvasBitmapIterator::nextScanLine()
	{
		currentPoint.setX(0);
		currentPoint.setY(currentPoint.getY() + 1);
	}

	bool BasicCanvasBitmapIterator::isEndOfImage() const
	{
		return currentPoint.getY() >= getBitmapHeight();
	}

	void BasicCanvasBitmapIterator::nextPixel()
	{
		currentPoint.setY(0);
		currentPoint.setX(currentPoint.getX() + 1);
	}

	bool BasicCanvasBitmapIterator::isEndOfScanLine() const
	{
		return currentPoint.getX() >= getBitmapWidth();
	}

	Color BasicCanvasBitmapIterator::getColor() const
	{
		return myCanvas.getPixelColor(currentPoint);
	}

	int BasicCanvasBitmapIterator::getBitmapWidth() const
	{
		return myCanvas.getWidth();
	}

	int BasicCanvasBitmapIterator::getBitmapHeight() const
	{
		return myCanvas.getHeight();
	}

}