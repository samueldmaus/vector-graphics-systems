#include "Attribute.h"

namespace Xml
{
	Attribute::Attribute(std::string n, std::string v) : name(std::move(n)), value(std::move(v))
	{
	}

	const std::string& Attribute::getName() const
	{
		return name;
	}

	const std::string& Attribute::getValue() const
	{
		return value;
	}

	void Attribute::setName(std::string n)
	{
		name = std::move(n);
	}

	void Attribute::setValue(std::string v)
	{
		value = std::move(v);
	}

}
