#include "BitmapIterator.h"

namespace BitmapGraphics
{
	BitmapIterator::BitmapIterator(Bitmap& bitmap) : myBitmap(bitmap), scanLineCollectionIterator(myBitmap.begin())
	{
		if(!BitmapIterator::isEndOfImage())
		{
			scanLineIterator = scanLineCollectionIterator->begin();
		}
	}
	
	void BitmapIterator::nextScanLine()
	{
	}

	bool BitmapIterator::isEndOfImage() const
	{
		return scanLineCollectionIterator == myBitmap.end();
	}

	void BitmapIterator::nextPixel()
	{
		++scanLineIterator;
	}

	bool BitmapIterator::isEndOfScanLine() const
	{
		return false;
	}

	Color BitmapIterator::getColor() const
	{
		return *scanLineIterator;
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
