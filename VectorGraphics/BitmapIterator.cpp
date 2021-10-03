#include "BitmapIterator.h"

namespace BitmapGraphics
{
	BitmapIterator::BitmapIterator(Bitmap& bitmap) : myBitmap(bitmap), scanLineCollectionIterator(myBitmap.begin())
	{
		if (!BitmapIterator::isEndOfImage())
		{
			pixelIterator = scanLineCollectionIterator->begin();
		}
	}

	void BitmapIterator::nextScanLine()
	{
		++scanLineCollectionIterator;
		if (!isEndOfImage())
		{
			pixelIterator = scanLineCollectionIterator->begin();
		}
	}

	bool BitmapIterator::isEndOfImage() const
	{
		return scanLineCollectionIterator == myBitmap.end();
	}

	void BitmapIterator::nextPixel()
	{
		++pixelIterator;
	}

	bool BitmapIterator::isEndOfScanLine() const
	{
		return pixelIterator == scanLineCollectionIterator->end();
	}

	Color BitmapIterator::getColor() const
	{
		return *pixelIterator;
	}

	int BitmapIterator::getBitmapWidth() const
	{
		return myBitmap.getWidth();
	}

	int BitmapIterator::getBitmapHeight() const
	{
		return myBitmap.getHeight();
	}

}
