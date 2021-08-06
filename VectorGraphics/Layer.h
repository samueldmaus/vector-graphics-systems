#pragma once

#include "PlacedGraphic.h"
#include <list>
#include <string>

namespace VG
{
	class Layer
	{
	public:
		explicit Layer(std::string name);
		
		Layer(const Layer& other) = default;
        Layer(Layer&& other) = default;
        ~Layer() = default;

        Layer& operator=(const Layer&) = default;
        Layer& operator=(Layer&&) = default;

		void setAlias(const std::string& newAlias);
		[[nodiscard]] std::string getAlias() const;

		void addGraphic(const PlacedGraphic& graphic);
		void removeGraphics(const Point& point);

	private:
		std::list<PlacedGraphic> graphics;
		std::string alias;
	};
}
