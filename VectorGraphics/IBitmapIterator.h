#pragma once
#include "Color.h"

namespace BitmapGraphics
{
	class IBitmapIterator {
	public:
		explicit IBitmapIterator() = default;

		IBitmapIterator(const IBitmapIterator& other) = default;
		IBitmapIterator(IBitmapIterator&& other) noexcept = default;
		virtual ~IBitmapIterator() = default;

		IBitmapIterator& operator=(const IBitmapIterator&) = default;
		IBitmapIterator& operator=(IBitmapIterator&&) = default;

		virtual void nextScanLine() = 0;
		[[nodiscard]] virtual bool isEndOfImage() const = 0;
		virtual void nextPixel() = 0;
		[[nodiscard]] virtual bool isEndOfScanLine() const = 0;

		[[nodiscard]] virtual Color getColor() const = 0;

		[[nodiscard]] virtual int getBitmapWidth() const = 0;
		[[nodiscard]] virtual int getBitmapHeight() const = 0;
	};
}
