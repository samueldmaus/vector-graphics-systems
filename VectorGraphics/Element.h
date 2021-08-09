#pragma once

#include <string>
#include <unordered_map>
#include <vector>

#include "tinyxml2.h"
#include "Attribute.h"

namespace Xml
{
	class Element;
	
	using AttributeMap = std::unordered_map<std::string, std::string>;
	using ElementList = std::vector<Element>;
	
	class Element
	{
	public:
		explicit Element(tinyxml2::XMLElement* xmlElement);
		explicit Element(std::string name);

		Element(const Element& other) = default;
		Element(Element&& other) noexcept = default;
		~Element() = default;

		Element& operator=(const Element&) = default;
		Element& operator=(Element&&) = default;

		[[nodiscard]] const std::string& getName() const;
		[[nodiscard]] const std::string& getAttribute(const std::string& att);

		void addAttribute(std::string n, std::string v);
		
		[[nodiscard]] AttributeMap getAttributes() const;
		[[nodiscard]] ElementList& getChildElements();

	private:
		std::string tagName;
		std::vector<Attribute> attributes;
		std::vector<Element> childElements;
	};
}
