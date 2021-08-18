#include "Word.h"
#include "Byte.h"

namespace Binary
{
	Word::Word(uint16_t initialValue) : value(initialValue)
	{
	}

	Word::operator uint16_t() const
	{
		return value;
	}
	
	Word& Word::operator=(uint16_t newValue)
	{
		this->value = newValue;
		return *this;
	}
	
	Word Word::readLittleEndian(std::istream& sourceStream)
	{
		const uint8_t tmp1 = Byte::read(sourceStream);
		const uint8_t tmp2 = Byte::read(sourceStream);
		const uint16_t start = (static_cast<uint16_t>(tmp2) << 8) | tmp1;
		return Word(start);
	}

	void Word::writeLittleEndian(std::ostream& destinationStream) const
	{
#ifdef Little_Endian_
		writeNativeOrder(destinationStream);
#else
		writeSwappedOrder(destinationStream);
#endif
	}

	Word Word::readBigEndian(std::istream& sourceStream)
	{
		const uint8_t tmp1 = Byte::read(sourceStream);
		const uint8_t tmp2 = Byte::read(sourceStream);
		const uint16_t start = (static_cast<uint16_t>(tmp1) << 8) | tmp2;
		return Word(start);
	}

	void Word::writeBigEndian(std::ostream& destinationStream) const
	{
#ifdef Big_Endian_
		writeSwappedOrder(destinationStream);
#else
		writeNativeOrder(destinationStream);
#endif
	}

	Word Word::writeSwappedOrder(std::ostream& destinationStream) const
	{
		return Word();
	}

	Word Word::writeNativeOrder(std::ostream& destinationStream) const
	{
		return Word();
	}

}
