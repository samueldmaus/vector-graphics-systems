#include "WindowsBitmapHeader.h"

namespace BitmapGraphics
{
	void WindowsBitmapHeader::readFileHeader(std::istream& sourceStream)
	{
		//verifyEquality(firstIdentifier, Binary::Byte::read(sourceStream), "firstIdentifier");
		//verifyEquality(secondIdentifier, Binary::Byte::read(sourceStream), "secondIdentifier");
		//this->fileSize = Binary::DoubleWord::readLittleEndian(sourceStream);
		//verifyEquality(reserved, Binary::DoubleWord::readLittleEndian(sourceStream), "reserved");
		//verifyEquality(rawImageByteOffset, Binary::DoubleWord::readLittleEndian(sourceStream), "rawImageByteOffset");
	}

	void WindowsBitmapHeader::writeFileHeader(std::ostream& destinationStream) const
	{
		firstIdentifier.write(destinationStream);
		secondIdentifier.write(destinationStream);
		fileSize.writeLittleEndian(destinationStream);
		reserved.writeLittleEndian(destinationStream);
		rawImageByteOffset.writeLittleEndian(destinationStream);
	}

}
