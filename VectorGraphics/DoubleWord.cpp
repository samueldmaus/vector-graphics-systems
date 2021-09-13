#include "DoubleWord.h"
#include "Word.h"

namespace Binary
{
	DoubleWord::DoubleWord(uint32_t initialValue) : value(initialValue)
	{
	}

	DoubleWord::operator uint32_t() const
	{
		return value;
	}

	DoubleWord& DoubleWord::operator=(uint32_t newValue)
	{
		this->value = newValue;
		return *this;
	}

	DoubleWord DoubleWord::readLittleEndian(std::istream& sourceStream)
	{
		const uint16_t tmp1 = Word::readLittleEndian(sourceStream);
		const uint16_t tmp2 = Word::readLittleEndian(sourceStream);
		const uint32_t start = (static_cast<uint32_t>(tmp2) << 16) | tmp1;
		return DoubleWord(start);
	}

	void DoubleWord::writeLittleEndian(std::ostream& destinationStream) const
	{
#ifdef Little_Endian_
		writeNativeOrder(destinationStream);
#else
		writeSwappedOrder(destinationStream);
#endif
	}

	DoubleWord DoubleWord::readBigEndian(std::istream& sourceStream)
	{
		const uint16_t tmp1 = Word::readBigEndian(sourceStream);
		const uint16_t tmp2 = Word::readBigEndian(sourceStream);
		const uint32_t start = (static_cast<uint32_t>(tmp1) << 16) | tmp2;
		return DoubleWord(start);
	}

	void DoubleWord::writeBigEndian(std::ostream& destinationStream) const
	{
#ifdef Big_Endian_
		writeSwappedOrder(destinationStream);
#else
		writeNativeOrder(destinationStream);
#endif
	}

	void DoubleWord::writeSwappedOrder(std::ostream& destinationStream) const
	{
		const auto tmp1 = static_cast<uint8_t>(value >> 24);
		const auto tmp2 = static_cast<uint8_t>(value >> 16);
		const auto tmp3 = static_cast<uint8_t>(value >> 8);
		const auto tmp4 = static_cast<uint8_t>(value);
		destinationStream.put(tmp4);
		destinationStream.put(tmp3);
		destinationStream.put(tmp2);
		destinationStream.put(tmp1);
	}

	void DoubleWord::writeNativeOrder(std::ostream& destinationStream) const
	{
		const auto tmp1 = static_cast<uint8_t>(value >> 24);
		const auto tmp2 = static_cast<uint8_t>(value >> 16);
		const auto tmp3 = static_cast<uint8_t>(value >> 8);
		const auto tmp4 = static_cast<uint8_t>(value);
		destinationStream.put(tmp1);
		destinationStream.put(tmp2);
		destinationStream.put(tmp3);
		destinationStream.put(tmp4);
	}

}
