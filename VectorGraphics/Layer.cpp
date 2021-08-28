#include "Layer.h"

#include <stdexcept>

namespace Framework
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

	void Layer::addGraphic(PlacedGraphic&& graphic)
	{
		graphics.emplace_back(std::forward<PlacedGraphic>(graphic));
	}

	void Layer::removeGraphic(const PlacedGraphic& placedGraphic)
	{
		graphics.remove(placedGraphic);
	}

	void Layer::eraseGraphic(int index)
	{
		if (index >= 0 && static_cast<std::size_t>(index) < graphics.size())
		{
			const auto pos = graphics.begin();
			auto newPos = std::next(pos, index);
			graphics.erase(newPos);
		}
		else
		{
			throw std::out_of_range{ "index out of range" };
		}
	}

	PlacedGraphic& Layer::getGraphic(const VG::Point& point)
	{
		const auto newEnd = std::ranges::find_if(graphics.begin(), graphics.end(), [&](const PlacedGraphic& graphic)
			{
				return graphic.getPlacementPoint() == point;
			});

		if (newEnd == graphics.end())
		{
			throw std::invalid_argument("the point to get does not appear in the graphics");
		}

		return *newEnd;
	}

	PlacedGraphic& Layer::getGraphic(int index)
	{
		if (index >= 0 && static_cast<std::size_t>(index) < graphics.size())
		{
			const auto& pos = graphics.begin();
			const auto& newPos = std::next(pos, index);
			return *newPos;
		}
		else
		{
			throw std::out_of_range{ "index out of range" };
		}
	}

	size_t Layer::getGraphicsCount() const
	{
		return graphics.size();
	}
	
}
