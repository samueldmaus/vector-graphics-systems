#pragma once
#include <list>

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

		ScanLineIterator begin()
		{
			return scanLineCollection.begin();
		}
		ScanLineIterator end()
		{
			return scanLineCollection.end();
		}

		void read(std::istream& sourceStream);
		void write(std::ostream& destinationSource);

		[[nodiscard]] int getWidth() const;
		[[nodiscard]] int getHeight() const;

	private:
		int width;
		int height;

		ScanLineCollection scanLineCollection;
		
	};
}
