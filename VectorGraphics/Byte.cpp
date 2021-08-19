#include "Byte.h"

#include <iostream>

namespace Binary
{
	Byte::Byte(uint8_t initialValue) : value(initialValue)
	{
	}

	Byte::operator char() const
	{
		return static_cast<char>(value);
	}

	Byte::operator unsigned char()
	{
		return static_cast<unsigned char>(value);
	}

	Byte::operator uint8_t() const
	{
		return value;
	}

	Byte Byte::read(std::istream& sourceStream)
	{
		return Byte(sourceStream.get());
	}

	void Byte::write(std::ostream& destinationStream) const
	{
		destinationStream.put(value);
	}
}
