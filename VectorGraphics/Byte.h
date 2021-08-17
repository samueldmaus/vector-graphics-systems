#pragma once
#include <cstdint>
#include <istream>

namespace Binary
{
	class Byte
	{
	public:
		Byte(uint8_t initialValue = 0);

		Byte(const Byte&) = default;
		Byte(Byte&&) = default;
		~Byte() = default;

		Byte& operator=(const Byte&) = default;
		Byte& operator=(Byte&&) = default;

		operator char() const;
		operator unsigned char();
		
		static Byte read(std::istream& sourceStream);
		void write(std::ostream& destinationStream) const;

	private:
		uint8_t value;
	};
}
