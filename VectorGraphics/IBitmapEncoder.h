#pragma once

#include <memory>
#include <string>

namespace BitmapGraphics
{
	class IBitmapEncoder
	{
	public:
		using HBitmapEncoder = std::unique_ptr<IBitmapEncoder>;
		using HBitmapIterator = std::unique_ptr<IBitmapIterator>;

		explicit IBitmapEncoder() = default;
		
		IBitmapEncoder(const IBitmapEncoder& other) = default;
		IBitmapEncoder(IBitmapEncoder&& other) noexcept = default;
		virtual ~IBitmapEncoder() = default;

		IBitmapEncoder& operator=(const IBitmapEncoder&) = default;
		IBitmapEncoder& operator=(IBitmapEncoder&&) = default;

		[[nodiscard]] virtual HBitmapEncoder clone(HBitmapIterator i) = 0;
		virtual void encodeToStream(std::ostream& destinationStream) = 0;
		[[nodiscard]] virtual std::string getMimeType() = 0;
	};
}
