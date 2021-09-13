#include "Color.h"
#include "DoubleWord.h"

namespace BitmapGraphics
{
	Color::Color(uint8_t initialRed, uint8_t initialGreen, uint8_t initialBlue) : red(initialRed), green(initialGreen), blue(initialBlue)
	{
	}
	
	bool Color::operator==(const Color& rhs)
	{
		return (red == static_cast<uint8_t>(rhs.red)) && (green == static_cast<uint8_t>(rhs.green)) && (blue ==
			static_cast<uint8_t>(rhs.blue));
	}

	bool Color::operator!=(const Color& rhs)
	{
		return !(*this == rhs);
	}

	Color Color::read(std::istream& sourceStream)
	{
		auto blue = Binary::Byte::read(sourceStream);
		auto green = Binary::Byte::read(sourceStream);
		auto red = Binary::Byte::read(sourceStream);
		return Color(red, green, blue);
	}

	void Color::write(std::ostream& destinationStream) const
	{
		blue.write(destinationStream);
		green.write(destinationStream);
		red.write(destinationStream);
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
	
	std::ostream& operator<<(std::ostream& outputStream, const Color& color)
	{
		color.write(outputStream);
		return outputStream;
	}

}
