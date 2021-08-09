#pragma once

#include <string>

namespace Xml
{
	class Attribute
	{
	public:
		Attribute(std::string n, std::string v);

		[[nodiscard]] const std::string& getName() const;
		[[nodiscard]] const std::string& getValue() const;

		void setName(std::string n);
		void setValue(std::string v);

	private:
		std::string name;
		std::string value;
	};
}
