#pragma once

#include "Element.h"

#include <sstream>

namespace Xml
{
	class Writer
	{
	public:
		Writer() = default;

		Writer(const Writer& other) = default;
		Writer(Writer&& other) noexcept = default;
		~Writer() = default;

		Writer& operator=(const Writer&) = default;
		Writer& operator=(Writer&&) = default;

		static void writeXml(HElement element, std::ostream& os);
	};
}
