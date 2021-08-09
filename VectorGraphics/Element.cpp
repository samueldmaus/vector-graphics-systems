#include "Element.h"

#include <stdexcept>

namespace Xml
{
	Element::Element(tinyxml2::XMLElement* xmlElement) : tagName(xmlElement->Value())
	{
		attributes.emplace_back(Attribute("width", xmlElement->Attribute("width")));
		attributes.emplace_back(Attribute("height", xmlElement->Attribute("height")));

		tinyxml2::XMLElement* layer = xmlElement->FirstChildElement("Layer");
		while(layer != nullptr)
		{
			Element child(layer->Value());
			child.addAttribute("alias", layer->Attribute("alias"));
			
			tinyxml2::XMLElement* placedGraphic = layer->FirstChildElement("PlacedGraphic");
			while(placedGraphic != nullptr)
			{
				Element pGraphicChild(placedGraphic->Value());
				pGraphicChild.addAttribute("x", placedGraphic->Attribute("x"));
				pGraphicChild.addAttribute("y", placedGraphic->Attribute("y"));

				tinyxml2::XMLElement* vectorGraphic = placedGraphic->FirstChildElement("VectorGraphic");
				while(vectorGraphic != nullptr)
				{
					Element vGraphicChild(vectorGraphic->Value());
					vGraphicChild.addAttribute("closed", vectorGraphic->Attribute("closed"));

					tinyxml2::XMLElement* point = vectorGraphic->FirstChildElement("Point");
					while(point != nullptr)
					{
						Element pointChild(point->Value());
						pointChild.addAttribute("x", point->Attribute("x"));
						pointChild.addAttribute("y", point->Attribute("y"));

						vGraphicChild.childElements.push_back(pointChild);
						point = point->NextSiblingElement("Point");
					}

					pGraphicChild.childElements.push_back(vGraphicChild);
					vectorGraphic = vectorGraphic->NextSiblingElement("VectorGraphic");
				}
				
				child.childElements.push_back(pGraphicChild);
				placedGraphic = placedGraphic->NextSiblingElement("PlacedGraphic");
			}
			
			childElements.push_back(child);
			layer = layer->NextSiblingElement("Layer");
		}
	}

	Element::Element(std::string name) : tagName(std::move(name))
	{
	}

	const std::string& Element::getName() const
	{
		return tagName;
	}
	
	const std::string& Element::getAttribute(const std::string& att)
	{
		const auto it = std::ranges::find_if(attributes.begin(), attributes.end(), [&](const Attribute& t)
		{
			return t.getName() == att;
		});
		if(it == attributes.end())
		{
			throw std::invalid_argument("The attribute: " + att + " does not appear to exist");
		}
		return (*it).getValue();
	}

	void Element::addAttribute(std::string n, std::string v)
	{
		attributes.emplace_back(Attribute(n, v));
	}
	
	AttributeMap Element::getAttributes() const
	{
		std::unordered_map<std::string, std::string> map;
		for(const auto& att : attributes)
		{
			map.insert(std::make_pair(att.getName(), att.getValue()));
		}
		return map;
	}
	
	ElementList& Element::getChildElements()
	{
		return childElements;
	}
}
