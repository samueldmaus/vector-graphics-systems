#include "XMLReader.h"
#include <iostream>

namespace Xml
{
	HElement Reader::loadXml(std::stringstream& xml)
	{
		auto doc = std::make_unique<tinyxml2::XMLDocument>();
		doc->Parse(xml.str().c_str());
		const auto root = doc->RootElement();

		if (root == nullptr)
		{
			throw std::invalid_argument("Root element is null");
		}

		return std::make_shared<Element>(root);
	}
}
