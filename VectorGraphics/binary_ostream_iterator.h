#pragma once
#include <iostream>

namespace BitmapGraphics
{
	template<class T>
	class binary_ostream_iterator
	{
	public:
		explicit binary_ostream_iterator(std::ostream& stream) : outputStream(&stream)
		{}

		~binary_ostream_iterator() = default;

		binary_ostream_iterator(const binary_ostream_iterator&) = default;
		binary_ostream_iterator(binary_ostream_iterator&&) = default;
		
		binary_ostream_iterator& operator=(const binary_ostream_iterator&) = default;
		binary_ostream_iterator& operator=(binary_ostream_iterator&&) = default;

		binary_ostream_iterator<T>& operator=(const T& value)
		{
			value.write(*outputStream);
			return *this;
		}

		binary_ostream_iterator<T>& operator*() noexcept
		{
			return *this;
		}

		binary_ostream_iterator<T>& operator++()
		{
			return *this;
		}

		binary_ostream_iterator<T>& operator++(int)
		{
			return *this;
		}

	private:
		std::ostream* outputStream;
	};
}