#include "TestHarness.h"
#include "Attribute.h"

TEST(ctor, Attribute)
{
	const Xml::Attribute attribute("name", "value");

	CHECK_EQUAL("name", attribute.getName());
	CHECK_EQUAL("value", attribute.getValue());
}

TEST(copyCtor, Attribute)
{
	const Xml::Attribute attribute("name", "value");

	const auto attribute_two(attribute);

	CHECK_EQUAL("name", attribute_two.getName());
	CHECK_EQUAL("value", attribute_two.getValue());
}

TEST(copyAssignment, Attribute)
{
	const Xml::Attribute attribute("name", "value");

	const auto attribute_two = attribute;

	CHECK_EQUAL("name", attribute_two.getName());
	CHECK_EQUAL("value", attribute_two.getValue());
}

TEST(moveCtor, Attribute)
{
	Xml::Attribute attribute("name", "value");

	const auto attribute_two(std::move(attribute));

	CHECK_EQUAL("name", attribute_two.getName());
	CHECK_EQUAL("value", attribute_two.getValue());
}

TEST(moveAssignment, Attribute)
{
	Xml::Attribute attribute("name", "value");

	const auto attribute_two = std::move(attribute);

	CHECK_EQUAL("name", attribute_two.getName());
	CHECK_EQUAL("value", attribute_two.getValue());
}

TEST(setName, Attribute)
{
	Xml::Attribute attribute("name", "value");
	attribute.setName("new name");

	CHECK_EQUAL("new name", attribute.getName());
}

TEST(setValue, Attribute)
{
	Xml::Attribute attribute("name", "value");
	attribute.setValue("new value");

	CHECK_EQUAL("new value", attribute.getValue());
}