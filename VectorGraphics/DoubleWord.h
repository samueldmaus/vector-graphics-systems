#pragma once
#include <cstdint>
#include <istream>

namespace Binary
{
	class DoubleWord
	{
	public:
		explicit DoubleWord(uint32_t initialValue = 0);

		DoubleWord(const DoubleWord&) = default;
		DoubleWord(DoubleWord&&) = default;
		~DoubleWord() = default;

		DoubleWord& operator=(const DoubleWord&) = default;
		DoubleWord& operator=(DoubleWord&&) noexcept = default;

		operator uint32_t () const;
		DoubleWord& operator=(uint32_t newValue);

		static DoubleWord readLittleEndian(std::istream& sourceStream);
		static DoubleWord readBigEndian (std::istream& sourceStream);
	
	private:
		uint32_t value;
	};
}
