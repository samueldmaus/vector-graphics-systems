#include "TestHarness.h"
#include "Element.h"
#include "tinyxml2.h"

TEST(ctor, Element)
{
	tinyxml2::XMLDocument doc;
	tinyxml2::XMLElement* tiElement = doc.NewElement("Scene");
	Xml::Element element(tiElement);

	CHECK_EQUAL("Scene", element.getName());
}


TEST(copyCtor, Element)
{
	tinyxml2::XMLDocument doc;
	tinyxml2::XMLElement* tiElement = doc.NewElement("Scene");
	Xml::Element element(tiElement);

	const Xml::Element element_two(element);

	CHECK_EQUAL(element.getName(), element_two.getName());
}

TEST(copyAssignment, Element)
{
	tinyxml2::XMLDocument doc;
	tinyxml2::XMLElement* tiElement = doc.NewElement("Scene");
	Xml::Element element(tiElement);
	element.addChildElement(Xml::Element("Layer"));

	Xml::Element element_two = element;

	CHECK_EQUAL(element.getName(), element_two.getName());
	CHECK_EQUAL(1, element_two.getChildElements().size());
}

TEST(moveCtor, Element)
{
	tinyxml2::XMLDocument doc;
	tinyxml2::XMLElement* tiElement = doc.NewElement("Scene");
	Xml::Element element(tiElement);
	element.addChildElement(Xml::Element("Layer"));

	Xml::Element element_two(std::move(element));

	CHECK_EQUAL("Scene", element_two.getName());
	CHECK_EQUAL(1, element_two.getChildElements().size());
}

TEST(moveAssignment, Element)
{
	tinyxml2::XMLDocument doc;
	tinyxml2::XMLElement* tiElement = doc.NewElement("Scene");
	Xml::Element element(tiElement);
	element.addChildElement(Xml::Element("Layer"));

	Xml::Element element_two = std::move(element);

	CHECK_EQUAL("Scene", element_two.getName());
	CHECK_EQUAL(1, element_two.getChildElements().size());
}

TEST(setName, Element)
{
	tinyxml2::XMLDocument doc;
	tinyxml2::XMLElement* tiElement = doc.NewElement("Scene");
	Xml::Element element(tiElement);

	element.setName("Layer");

	CHECK_EQUAL("Layer", element.getName());
}

TEST(getAttribute, Element)
{
	tinyxml2::XMLDocument doc;
	tinyxml2::XMLElement* tiElement = doc.NewElement("Scene");
	tiElement->SetAttribute("width", "100");
	Xml::Element element(tiElement);

	CHECK_EQUAL("100", element.getAttribute("width"));
}

TEST(addAttribute, Element)
{
	tinyxml2::XMLDocument doc;
	tinyxml2::XMLElement* tiElement = doc.NewElement("Scene");
	tiElement->SetAttribute("width", "100");
	Xml::Element element(tiElement);
	element.addAttribute("height", "500");

	CHECK_EQUAL("100", element.getAttribute("width"));
	CHECK_EQUAL("500", element.getAttribute("height"));
}

TEST(getAttributes, Element)
{
	tinyxml2::XMLDocument doc;
	tinyxml2::XMLElement* tiElement = doc.NewElement("Scene");
	tiElement->SetAttribute("width", "100");
	Xml::Element element(tiElement);
	element.addAttribute("height", "500");

	auto attributes = element.getAttributes();

	CHECK_EQUAL(2, attributes.size());
	CHECK_EQUAL("100", attributes["width"]);
	CHECK_EQUAL("500", attributes["height"]);
}

TEST(getChildElements, Element)
{
	tinyxml2::XMLDocument doc;
	tinyxml2::XMLElement* tiElement = doc.NewElement("Scene");
	tiElement->SetAttribute("width", "100");
	tinyxml2::XMLElement* tiElementTwo = doc.NewElement("Layer");
	tiElementTwo->SetAttribute("alias", "Sea");

	tiElement->InsertEndChild(tiElementTwo);
	Xml::Element element(tiElement);

	CHECK_EQUAL(1, element.getChildElements().size());
	CHECK_EQUAL("Layer", element.getChildElements()[0].getName());
}

TEST(addChildElement, Element)
{
	tinyxml2::XMLDocument doc;
	tinyxml2::XMLElement* tiElement = doc.NewElement("Scene");
	tinyxml2::XMLElement* tiElementTwo = doc.NewElement("Layer");
	Xml::Element element(tiElement);
	Xml::Element element_two(tiElementTwo);
	element.addChildElement(element_two);

	CHECK_EQUAL(1, element.getChildElements().size());
	CHECK_EQUAL("Layer", element.getChildElements()[0].getName());
}