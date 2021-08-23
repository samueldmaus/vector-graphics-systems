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

		Bitmap(uint32_t w, uint32_t h, std::istream& sourceStream);

		ScanLineIterator begin()
		{
			return scanLineCollection.begin();
		}
		ScanLineIterator end()
		{
			return scanLineCollection.end();
		}

		void write(std::ostream& destinationSource);

		[[nodiscard]] int getWidth() const;
		[[nodiscard]] int getHeight() const;

	private:
		uint32_t width;
		uint32_t height;

		ScanLineCollection scanLineCollection;
		
	};
}
