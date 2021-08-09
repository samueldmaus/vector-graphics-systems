#pragma once

#include "Element.h"
#include "tinyxml2.h"

#include <memory>
#include <sstream>

namespace Xml
{
	using HElement = std::shared_ptr<Element>;
	
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
