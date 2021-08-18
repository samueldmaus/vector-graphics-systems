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

	DoubleWord DoubleWord::readBigEndian(std::istream& sourceStream)
	{
		const uint16_t tmp1 = Word::readBigEndian(sourceStream);
		const uint16_t tmp2 = Word::readBigEndian(sourceStream);
		const uint32_t start = (static_cast<uint32_t>(tmp1) << 16) | tmp2;
		return DoubleWord(start);
	}
	
}
