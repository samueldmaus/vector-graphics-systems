#pragma once

#include "IBitmapIterator.h"
#include "ICanvas.h"

namespace BitmapGraphics
{
	class BasicCanvasBitmapIterator : public IBitmapIterator
	{
	public:
		explicit BasicCanvasBitmapIterator(const ICanvas& canvas);

		BasicCanvasBitmapIterator(const BasicCanvasBitmapIterator& other) = default;
		BasicCanvasBitmapIterator(BasicCanvasBitmapIterator&& other) noexcept = default;
		~BasicCanvasBitmapIterator() override = default;

		BasicCanvasBitmapIterator& operator=(const BasicCanvasBitmapIterator&) = delete;
		BasicCanvasBitmapIterator& operator=(BasicCanvasBitmapIterator&&) = delete;

		void nextScanLine() override;
		[[nodiscard]] bool isEndOfImage() const override;
		void nextPixel() override;
		[[nodiscard]] bool isEndOfScanLine() const override;

		[[nodiscard]] Color getColor() const override;

		[[nodiscard]] int getBitmapWidth() const override;
		[[nodiscard]] int getBitmapHeight() const override;

	private:
		const ICanvas& myCanvas;
		VG::Point currentPoint;

	};
}
