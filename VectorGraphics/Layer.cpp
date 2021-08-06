#include "Layer.h"

namespace VG
{
	Layer::Layer(std::string name) : alias(std::move(name))
	{
	}
	
	void Layer::setAlias(const std::string& newAlias)
	{
		alias = newAlias;
	}
	
	std::string Layer::getAlias() const
	{
		return alias;
	}
	
	void Layer::addGraphic(const PlacedGraphic& graphic)
	{
		graphics.push_back(graphic);
	}
	
	void Layer::removeGraphics(const Point& point)
	{

	}
	
}
