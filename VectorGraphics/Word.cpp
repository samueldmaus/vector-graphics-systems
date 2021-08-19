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

	void Word::writeSwappedOrder(std::ostream& destinationStream) const
	{
		const auto tmp1 = static_cast<uint8_t>(value >> 8);
		const auto tmp2 = static_cast<uint8_t>(value);
		destinationStream.put(tmp2);
		destinationStream.put(tmp1);
	}

	void Word::writeNativeOrder(std::ostream& destinationStream) const
	{
		const auto tmp1 = static_cast<uint8_t>(value >> 8);
		const auto tmp2 = static_cast<uint8_t>(value);
		destinationStream.put(tmp1);
		destinationStream.put(tmp2);
	}

}
