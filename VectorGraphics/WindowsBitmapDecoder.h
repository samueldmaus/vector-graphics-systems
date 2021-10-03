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
		
		explicit WindowsBitmapDecoder();
		explicit WindowsBitmapDecoder(std::istream& sourceStream);

		WindowsBitmapDecoder(const WindowsBitmapDecoder& other) = delete;
		WindowsBitmapDecoder(WindowsBitmapDecoder&& other) noexcept = default;
		~WindowsBitmapDecoder() override = default;

		WindowsBitmapDecoder& operator=(const WindowsBitmapDecoder&) = delete;
		WindowsBitmapDecoder& operator=(WindowsBitmapDecoder&&) = delete;

		HBitmapDecoder clone(std::istream& sourceStream) override;
		HBitmapIterator createIterator() override;
		std::string getMimeType() override;
		bool isSupported(const std::string& chunk) override;

	private:
		HBitmap myBitmap;
		std::istream& stream;

	};
}