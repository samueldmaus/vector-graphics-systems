#pragma once
#include <list>

#include "CodecLibrary.h"
#include "Color.h"

namespace BitmapGraphics
{
	class Bitmap
	{
	public:
		using ScanLine = std::list<Color>;

	private:
		using ScanLineCollection = std::list<ScanLine>;

	public:
		using ScanLineIterator = ScanLineCollection::iterator;

		Bitmap(int w, int h, std::istream& sourceStream);
		Bitmap() = default;

		ScanLineIterator begin()
		{
			return scanLineCollection.begin();
		}
		ScanLineIterator end()
		{
			return scanLineCollection.end();
		}

		void read(std::istream& sourceStream);
		void write(std::ostream& destinationStream);

		[[nodiscard]] int getWidth() const;
		[[nodiscard]] int getHeight() const;
		[[nodiscard]] int getNumberOfPadBytes() const;

		HBitmapIterator createIterator();

	private:
		int width{0};
		int height{0};

		ScanLineCollection scanLineCollection;
		
	};
}
