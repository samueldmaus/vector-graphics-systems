#include "XmlWriter.h"
#include "tinyxml2.h"
#include <algorithm>

void Xml::Writer::writeXml(HElement element, std::ostream& os)
{
	os << "<" << element->getName();
	AttributeMap attributes = element->getAttributes();
	std::for_each(std::begin(attributes), std::end(attributes), [&os](const auto& attribute) { os << " " << attribute.first << "=\"" << attribute.second << "\""; });

	auto childElements{element->getChildElements()};

	if(!childElements.empty())
	{
		os << ">" << std::endl;
	}
	else
	{
		os << "/>" << std::endl;
	}

	std::for_each(std::begin(childElements), std::end(childElements), [&os](const auto& e) { writeElement(e, os); });    
    os << "</" << element->getName() << ">" << std::endl;

	// implementation that bakes in TinyXML2 framework
	// tinyxml2::XMLDocument doc;

	// // Root Element
	// tinyxml2::XMLElement* root = doc.NewElement(element->getName().c_str());
	// for (const auto& [key, value] : element->getAttributes())
	// {
	// 	root->SetAttribute(key.c_str(), value.c_str());
	// }

	// // Layer Loop
	// for (auto& layerChild : element->getChildElements())
	// {
	// 	// Layer Element
	// 	tinyxml2::XMLElement* layer = doc.NewElement(layerChild.getName().c_str());

	// 	// Placed Graphic Loop
	// 	for (auto& placedGraphicChild : layerChild.getChildElements())
	// 	{
	// 		// Placed Graphic Element
	// 		tinyxml2::XMLElement* placedGraphic = doc.NewElement(placedGraphicChild.getName().c_str());

	// 		// Vector Graphic Loop
	// 		for (auto& vectorGraphicChild : placedGraphicChild.getChildElements())
	// 		{
	// 			// Vector Graphic Element
	// 			tinyxml2::XMLElement* vectorGraphic = doc.NewElement(vectorGraphicChild.getName().c_str());

	// 			// Point Loop
	// 			for(auto& pointChild : vectorGraphicChild.getChildElements())
	// 			{
	// 				// Point Element
	// 				tinyxml2::XMLElement* point = doc.NewElement(pointChild.getName().c_str());
					
	// 				// Point Attributes/Insert
	// 				for(const auto& [key, value] : pointChild.getAttributes())
	// 				{
	// 					point->SetAttribute(key.c_str(), value.c_str());
	// 				}
	// 				vectorGraphic->InsertEndChild(point);
	// 			}
				
	// 			// Vector Graphic Attributes/Insert
	// 			for(const auto& [key, value] : vectorGraphicChild.getAttributes())
	// 			{
	// 				vectorGraphic->SetAttribute(key.c_str(), value.c_str());
	// 			}
	// 			placedGraphic->InsertEndChild(vectorGraphic);
	// 		}

	// 		// Placed Graphic Attributes/Insert
	// 		for (const auto& [key, value] : placedGraphicChild.getAttributes())
	// 		{
	// 			placedGraphic->SetAttribute(key.c_str(), value.c_str());
	// 		}
	// 		layer->InsertEndChild(placedGraphic);
	// 	}

	// 	// Layer Attributes/Insert
	// 	for (const auto& [key, value] : layerChild.getAttributes())
	// 	{
	// 		layer->SetAttribute(key.c_str(), value.c_str());
	// 	}
	// 	root->InsertEndChild(layer);
	// }

	// doc.InsertFirstChild(root);

	// tinyxml2::XMLPrinter printer;
	// doc.Print(&printer);
	// os << printer.CStr();
}
