#pragma once
#include "Byte.h"

#include <cstdint>

namespace BitmapGraphics
{
	class Color
	{
	public:
		Color(uint8_t initialRed, uint8_t initialGreen, uint8_t initialBlue);

		Color(const Color&) = default;
		Color(Color&&) = default;
		~Color() = default;

		Color& operator=(const Color&) = default;
		Color& operator=(Color&&) noexcept = default;

		bool operator==(const Color& rhs);
		bool operator!=(const Color& rhs);
		static Color read(std::istream& sourceStream);
		void write(std::ostream& destinationStream) const;

		[[nodiscard]] Binary::Byte getRed() const;
		[[nodiscard]] Binary::Byte getGreen() const;
		[[nodiscard]] Binary::Byte getBlue() const;

		void setRed(Binary::Byte newRed);
		void setGreen(Binary::Byte newGreen);
		void setBlue(Binary::Byte newBlue);

	private:
		Binary::Byte red;
		Binary::Byte green;
		Binary::Byte blue;
	};

	std::ostream& operator<<(std::ostream& outputStream, const Color& color);
}
