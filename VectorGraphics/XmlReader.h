#pragma once

#include "Element.h"

#include <sstream>

namespace Xml
{	
	class Reader
	{
	public:
		Reader() = default;

		Reader(const Reader& other) = default;
		Reader(Reader&& other) noexcept = default;
		~Reader() = default;

		Reader& operator=(const Reader&) = default;
		Reader& operator=(Reader&&) = default;

		static HElement loadXml(std::stringstream& xml);
	};
}
