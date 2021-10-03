#include "Scene.h"

#include <stdexcept>

namespace Framework
{
	Scene::Scene(int w, int h) : width(w), height(h)
	{
	}

	void Scene::addLayer(const Layer& new_layer)
	{
		layer.push_back(new_layer);
	}

	void Scene::addLayer(Layer&& new_layer)
	{
		layer.emplace_back(std::forward<Layer>(new_layer));
	}

	void Scene::removeLayer(const std::string& name)
	{
		const auto newEnd = std::remove_if(layer.begin(), layer.end(), [&](const Layer& remove_layer)
			{
				return remove_layer.getAlias() == name;
			});
		if (newEnd == layer.end())
		{
			throw std::invalid_argument("the layer to remove does not appear in the layers");
		}
		layer.erase(newEnd, layer.end());
	}

	void Scene::eraseLayer(int index)
	{
		if (index >= 0 && static_cast<std::size_t>(index) < layer.size())
		{
			const auto pos = layer.begin();
			auto newPos = std::next(pos, index);
			layer.erase(newPos);
		}
		else
		{
			throw std::out_of_range{ "index out of range" };
		}
	}

	Layer& Scene::getLayer(const std::string& name)
	{
		const auto newEnd = std::ranges::find_if(layer.begin(), layer.end(), [&](const Layer& find_layer)
			{
				return find_layer.getAlias() == name;
			});

		if (newEnd == layer.end())
		{
			throw std::invalid_argument("the point to get does not appear in the graphics");
		}

		return *newEnd;
	}

	Layer& Scene::getLayer(int index)
	{
		if (index >= 0 && static_cast<std::size_t>(index) < layer.size())
		{
			const auto& pos = layer.begin();
			const auto& newPos = std::next(pos, index);
			return *newPos;
		}
		else
		{
			throw std::out_of_range{ "index out of range" };
		}
	}

	int Scene::getWidth() const
	{
		return width;
	}

	void Scene::setWidth(int new_width)
	{
		width = new_width;
	}

	int Scene::getHeight() const
	{
		return height;
	}

	void Scene::setHeight(int new_height)
	{
		height = new_height;
	}

	size_t Scene::getLayerCount() const
	{
		return layer.size();
	}
}
