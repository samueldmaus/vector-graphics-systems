#include "WindowsBitmapHeader.h"

#include <iostream>

#include "VerifyEquality.h"

namespace BitmapGraphics
{
	WindowsBitmapHeader::WindowsBitmapHeader(std::istream& sourceStream)
	{
		readFileHeader(sourceStream);
		readInfoHeader(sourceStream);
	}

	void WindowsBitmapHeader::writeFileHeader(std::ostream& destinationStream) const
	{
		firstIdentifier.write(destinationStream);
		secondIdentifier.write(destinationStream);
		fileSize.writeLittleEndian(destinationStream);
		reserved.writeLittleEndian(destinationStream);
		rawImageByteOffset.writeLittleEndian(destinationStream);
	}

	void WindowsBitmapHeader::readFileHeader(std::istream& sourceStream)
	{
		verifyEquality(firstIdentifier, Binary::Byte::read(sourceStream), "firstIdentifier");
		verifyEquality(secondIdentifier, Binary::Byte::read(sourceStream), "secondIdentifier");
		this->fileSize = Binary::DoubleWord::readLittleEndian(sourceStream);
		verifyEquality(reserved, Binary::DoubleWord::readLittleEndian(sourceStream), "reserved");
		verifyEquality(rawImageByteOffset, Binary::DoubleWord::readLittleEndian(sourceStream), "rawImageByteOffset");
	}

	void WindowsBitmapHeader::readInfoHeader(std::istream& sourceStream)
	{
		verifyEquality(infoHeaderBytes, Binary::DoubleWord::readLittleEndian(sourceStream), "infoHeaderBytes");
		this->bitmapWidth = Binary::DoubleWord::readLittleEndian(sourceStream);
		this->bitmapHeight = Binary::DoubleWord::readLittleEndian(sourceStream);
		verifyEquality(numberOfPlanes, Binary::Word::readLittleEndian(sourceStream), "numberOfPlanes");
		verifyEquality(bitsPerPixel, Binary::Word::readLittleEndian(sourceStream), "bitPerPixel");
		verifyEquality(compressionType, Binary::DoubleWord::readLittleEndian(sourceStream), "compressionType");
		this->compressedImageSize = Binary::DoubleWord::readLittleEndian(sourceStream);
		this->horizontalPixelsPerMeter = Binary::DoubleWord::readLittleEndian(sourceStream);
		this->verticalPixelsPerMeter = Binary::DoubleWord::readLittleEndian(sourceStream);
		verifyEquality(numberOfColors, Binary::DoubleWord::readLittleEndian(sourceStream), "numberOfColors");
		verifyEquality(numberOfImportantColors, Binary::DoubleWord::readLittleEndian(sourceStream), "numberOfImportantColors");
	}

	Binary::DoubleWord WindowsBitmapHeader::getFileSize() const
	{
		return fileSize;
	}

	int WindowsBitmapHeader::getBitmapHeight() const
	{
		return bitmapHeight;
	}

	int WindowsBitmapHeader::getBitmapWidth() const
	{
		return bitmapWidth;
	}

	Binary::DoubleWord WindowsBitmapHeader::getCompressedImageSize() const
	{
		return compressedImageSize;
	}

	Binary::DoubleWord WindowsBitmapHeader::getHorizontalPixelsPerMeter() const
	{
		return horizontalPixelsPerMeter;
	}

	Binary::DoubleWord WindowsBitmapHeader::getVerticalPixelsPerMeter() const
	{
		return verticalPixelsPerMeter;
	}

	void WindowsBitmapHeader::write(std::ostream& destinationStream) const
	{
		firstIdentifier.write(destinationStream);
		secondIdentifier.write(destinationStream);
		fileSize.writeLittleEndian(destinationStream);
		reserved.writeLittleEndian(destinationStream);
		rawImageByteOffset.writeLittleEndian(destinationStream);

		infoHeaderBytes.writeLittleEndian(destinationStream);
		bitmapWidth.writeLittleEndian(destinationStream);
		bitmapHeight.writeLittleEndian(destinationStream);
		numberOfPlanes.writeLittleEndian(destinationStream);
		bitsPerPixel.writeLittleEndian(destinationStream);
		compressionType.writeLittleEndian(destinationStream);
		compressedImageSize.writeLittleEndian(destinationStream);
		horizontalPixelsPerMeter.writeLittleEndian(destinationStream);
		verticalPixelsPerMeter.writeLittleEndian(destinationStream);
		numberOfColors.writeLittleEndian(destinationStream);
		numberOfImportantColors.writeLittleEndian(destinationStream);
	}

	void WindowsBitmapHeader::setBitmapHeight(uint32_t height)
	{
		bitmapHeight = height;
	}

	void WindowsBitmapHeader::setBitmapWidth(uint32_t width)
	{
		bitmapWidth = width;
	}

	void WindowsBitmapHeader::setBitmapFileSize(uint32_t size)
	{
		fileSize = size;
	}

}
