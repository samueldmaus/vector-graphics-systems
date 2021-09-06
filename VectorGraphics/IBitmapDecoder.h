#pragma once
#include <memory>
#include <string>

namespace BitmapGraphics
{
	class IBitmapDecoder
	{
	public:
		using HBitmapDecoder = std::unique_ptr<IBitmapDecoder>;

		explicit IBitmapDecoder() = default;

		IBitmapDecoder(const IBitmapDecoder& other) = default;
		IBitmapDecoder(IBitmapDecoder&& other) noexcept = default;
		virtual ~IBitmapDecoder() = default;

		IBitmapDecoder& operator=(const IBitmapDecoder&) = default;
		IBitmapDecoder& operator=(IBitmapDecoder&&) = default;

		virtual HBitmapDecoder clone(std::istream& sourceStream) = 0;
		virtual HBitmapDecoder createIterator() = 0;
		virtual std::string getMimeType() = 0;
		virtual bool isSupported() = 0;
	};
}
