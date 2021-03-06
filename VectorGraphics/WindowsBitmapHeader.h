#pragma once

#include "DoubleWord.h"
#include "Word.h"
#include "Byte.h"

namespace BitmapGraphics
{
	class WindowsBitmapHeader
	{
	public:
		explicit WindowsBitmapHeader() = default;
		explicit WindowsBitmapHeader(std::istream& sourceStream);

		WindowsBitmapHeader(const WindowsBitmapHeader&) = default;
		WindowsBitmapHeader(WindowsBitmapHeader&&) = default;
		~WindowsBitmapHeader() = default;

		WindowsBitmapHeader& operator=(const WindowsBitmapHeader&) = default;
		WindowsBitmapHeader& operator=(WindowsBitmapHeader&&) noexcept = default;

		void writeFileHeader(std::ostream& destinationStream) const;
		void readFileHeader(std::istream& sourceStream);
		void readInfoHeader(std::istream& sourceStream);

		[[nodiscard]] Binary::DoubleWord getFileSize() const;
		[[nodiscard]] int getBitmapHeight() const;
		[[nodiscard]] int getBitmapWidth() const;
		[[nodiscard]] Binary::DoubleWord getCompressedImageSize() const;
		[[nodiscard]] Binary::DoubleWord getHorizontalPixelsPerMeter() const;
		[[nodiscard]] Binary::DoubleWord getVerticalPixelsPerMeter() const;

		void write(std::ostream& destinationStream) const;

		void setBitmapHeight(uint32_t height);
		void setBitmapWidth(uint32_t width);
		void setBitmapFileSize(uint32_t size);
	
	private:
		// file header
		inline const static Binary::Byte firstIdentifier{ 'B' };
		inline const static Binary::Byte secondIdentifier{ 'M' };
		Binary::DoubleWord fileSize;
		inline const static Binary::DoubleWord reserved{ 0 };
		inline const static Binary::DoubleWord rawImageByteOffset{ 0x36 };

		// info header
		inline const static Binary::DoubleWord infoHeaderBytes{ 40 };
		Binary::DoubleWord bitmapWidth;
		Binary::DoubleWord bitmapHeight;
		inline const static Binary::Word numberOfPlanes{ 1 };
		inline const static Binary::Word bitsPerPixel{ 24 };
		inline const static Binary::DoubleWord compressionType{ 0 };
		Binary::DoubleWord compressedImageSize{0};
		Binary::DoubleWord horizontalPixelsPerMeter{0};
		Binary::DoubleWord verticalPixelsPerMeter{0};
		inline const static Binary::DoubleWord numberOfColors{ 0 };
		inline const static Binary::DoubleWord numberOfImportantColors{ 0 };
	};
}
