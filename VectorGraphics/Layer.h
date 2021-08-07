#pragma once

#include "PlacedGraphic.h"
#include <list>
#include <string>

namespace Framework
{
	class Layer
	{
	public:
		explicit Layer() = default;
		explicit Layer(std::string name);
		
		Layer(const Layer& other) = default;
        Layer(Layer&& other) noexcept = default;
        ~Layer() = default;

        Layer& operator=(const Layer&) = default;
        Layer& operator=(Layer&&) = default;

		void setAlias(const std::string& newAlias);
		[[nodiscard]] std::string getAlias() const;

		void addGraphic(const PlacedGraphic& graphic);
		void removeGraphic(const VG::Point& point);
		void eraseGraphic(int index);

		PlacedGraphic& getGraphic(const VG::Point& point);
		PlacedGraphic& getGraphic(int index);

		[[nodiscard]] size_t getGraphicsCount() const;

	private:
		std::list<PlacedGraphic> graphics;
		std::string alias;
	};
}
