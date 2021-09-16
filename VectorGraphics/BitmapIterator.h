#pragma once

#include "Bitmap.h"
#include "IBitmapIterator.h"

namespace BitmapGraphics
{
	class BitmapIterator : public IBitmapIterator
	{
	public:
		explicit BitmapIterator(Bitmap& bitmap);

		BitmapIterator(const BitmapIterator& other) = default;
		BitmapIterator(BitmapIterator&& other) noexcept = default;
		~BitmapIterator() override = default;

		BitmapIterator& operator=(const BitmapIterator&) = delete;
		BitmapIterator& operator=(BitmapIterator&&) = delete;

		void nextScanLine() override;
		[[nodiscard]] bool isEndOfImage() const override;
		void nextPixel() override;
		[[nodiscard]] bool isEndOfScanLine() const override;

		[[nodiscard]] Color getColor() const override;

		[[nodiscard]] int getBitmapWidth() const override;
		[[nodiscard]] int getBitmapHeight() const override;

	private:
		Bitmap& myBitmap;
		Bitmap::ScanLineIterator scanLineCollectionIterator;
		Bitmap::PixelIterator pixelIterator;
		
	};
}
