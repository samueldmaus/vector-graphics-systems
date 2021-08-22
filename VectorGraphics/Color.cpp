#include "Color.h"
#include "DoubleWord.h"

namespace BitmapGraphics
{
	Color::Color(uint8_t initialRed, uint8_t initialGreen, uint8_t initialBlue) : red(initialRed), green(initialGreen), blue(initialBlue)
	{
	}

	Color Color::read(std::istream& sourceStream)
	{
		return Color(Binary::Byte::read(sourceStream), Binary::Byte::read(sourceStream), Binary::Byte::read(sourceStream));
	}

	Binary::Byte Color::getRed() const
	{
		return red;
	}
	
	Binary::Byte Color::getGreen() const
	{
		return green;
	}
	
	Binary::Byte Color::getBlue() const
	{
		return blue;
	}

	void Color::setRed(Binary::Byte newRed)
	{
		red = newRed;
	}

	void Color::setGreen(Binary::Byte newGreen)
	{
		green = newGreen;
	}

	void Color::setBlue(Binary::Byte newBlue)
	{
		blue = newBlue;
	}
	
}
