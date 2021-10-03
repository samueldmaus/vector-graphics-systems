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
		using PixelIterator = ScanLine::iterator;

	private:
		using ScanLineCollection = std::list<ScanLine>;

	public:
		using ScanLineIterator = ScanLineCollection::iterator;

		Bitmap(int w, int h, std::istream& sourceStream);
		Bitmap(int w, int h);
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

		void addScanLine(ScanLine& scanLine)
		{
			scanLineCollection.push_back(std::move(scanLine));
		}

		[[nodiscard]] int getWidth() const;
		[[nodiscard]] int getHeight() const;

		HBitmapIterator createIterator();

	private:
		int width{ 0 };
		int height{ 0 };

		ScanLineCollection scanLineCollection;

	};
}
