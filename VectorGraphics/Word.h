#pragma once
#include <cstdint>
#include <istream>

namespace Binary
{
	class Word
	{
	public:
		explicit Word(uint16_t initialValue = 0);

		Word(const Word&) = default;
		Word(Word&&) = default;
		~Word() = default;

		Word& operator=(const Word&) = default;
		Word& operator=(Word&&) noexcept = default;
		
		operator uint16_t () const;
		Word& operator=(uint16_t newValue);

		static Word readLittleEndian (std::istream& sourceStream);
		void writeLittleEndian (std::ostream& destinationStream) const;
		static Word readBigEndian (std::istream& sourceStream);
		void writeBigEndian (std::ostream& destinationStream) const;

	private:
		uint16_t value;

		Word writeSwappedOrder(std::ostream& destinationStream) const;
		Word writeNativeOrder(std::ostream& destinationStream) const;
	};
}
