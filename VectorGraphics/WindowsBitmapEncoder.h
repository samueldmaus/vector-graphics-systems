#pragma once

#include "IBitmapEncoder.h"
#include "CodecLibrary.h"

namespace BitmapGraphics
{
	class WindowsBitmapEncoder : public IBitmapEncoder
	{
	public:
		explicit WindowsBitmapEncoder() = default;
		explicit WindowsBitmapEncoder(HBitmapIterator i);

		WindowsBitmapEncoder(const WindowsBitmapEncoder& other) = delete;
		WindowsBitmapEncoder(WindowsBitmapEncoder&& other) noexcept = default;
		~WindowsBitmapEncoder() override = default;

		WindowsBitmapEncoder& operator=(const WindowsBitmapEncoder&) = delete;
		WindowsBitmapEncoder& operator=(WindowsBitmapEncoder&&) = default;

		[[nodiscard]] HBitmapEncoder clone(HBitmapIterator i) override;
		void encodeToStream(std::ostream& destinationStream) override;
		[[nodiscard]] std::string getMimeType() override;

	private:
		HBitmapIterator myBitmapIterator;
	};
}