#include "Word.h"

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
	
//	Word Word::readLittleEndian(std::istream& sourceStream)
//	{
//		return Word();
//	}
//
//	void Word::writeLittleEndian(std::ostream& destinationStream) const
//	{
//#ifdef Little_Endian_
//		writeNativeOrder(destinationStream);
//#else
//		writeSwappedOrder(destinationStream);
//#endif
//	}
//
//	Word Word::readBigEndian(std::istream& sourceStream)
//	{
//		return Word();
//	}
//
//	void Word::writeBigEndian(std::ostream& destinationStream) const
//	{
//#ifdef Big_Endian_
//		writeSwappedOrder(destinationStream)
//#else
//		writeNativeOrder(destinationStream)
//#endif
//	}

}
