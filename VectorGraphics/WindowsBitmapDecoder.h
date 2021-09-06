#pragma once

#include "Bitmap.h"
#include "CodecLibrary.h"
#include "IBitmapDecoder.h"

namespace BitmapGraphics
{
	class WindowsBitmapDecoder : public IBitmapDecoder
	{
	public:
		using HBitmap = std::unique_ptr<Bitmap>;
		
		explicit WindowsBitmapDecoder() = default;

		WindowsBitmapDecoder(const WindowsBitmapDecoder& other) = delete;
		WindowsBitmapDecoder(WindowsBitmapDecoder&& other) noexcept = default;
		~WindowsBitmapDecoder() override = default;

		WindowsBitmapDecoder& operator=(const WindowsBitmapDecoder&) = delete;
		WindowsBitmapDecoder& operator=(WindowsBitmapDecoder&&) = default;

		HBitmapDecoder clone(std::istream& sourceStream) override;
		HBitmapIterator createIterator() override;
		std::string getMimeType() override;
		bool isSupported() override;

	private:
		HBitmap myBitmap;

	};
}