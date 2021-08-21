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

		void writeFileHeader(std::ostream& destinationStream) const;
		void readFileHeader(std::istream& sourceStream);

		[[nodiscard]] Binary::DoubleWord getFileSize() const;

	private:
		// file header
		inline const static Binary::Byte firstIdentifier{'B'};
		inline const static Binary::Byte secondIdentifier{'M'};
		Binary::DoubleWord fileSize;
		inline const static Binary::DoubleWord reserved{0};
		inline const static Binary::DoubleWord rawImageByteOffset{0x36};

		// info header
		inline const static Binary::DoubleWord infoHeaderBytes{0};
		Binary::DoubleWord bitmapWidth;
		Binary::DoubleWord bitmapHeight;
		const static Binary::Word numberOfPlanes;
		const static Binary::Word bitsPerPixel;
		const static Binary::DoubleWord compressionType;
		const static Binary::DoubleWord compressedImageSize;
		const static Binary::DoubleWord horizontalPixelsPerMeter;
		const static Binary::DoubleWord verticalPixelsPerMeter;
		const static Binary::DoubleWord numberOfColors;
		const static Binary::DoubleWord numberOfImportantColors;
	};
}
