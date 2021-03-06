#pragma once

#include "PlacedGraphic.h"
#include <list>
#include <string>

namespace Framework
{
	class Layer
	{
	public:
		Layer() = default;
		explicit Layer(std::string name);

		Layer(const Layer& other) = default;
		Layer(Layer&& other) noexcept = default;
		~Layer() = default;

		Layer& operator=(const Layer&) = default;
		Layer& operator=(Layer&&) = default;

		void setAlias(const std::string& newAlias);
		[[nodiscard]] std::string getAlias() const;

		void addGraphic(const PlacedGraphic& graphic);
		void addGraphic(PlacedGraphic&& graphic);
		void removeGraphic(const PlacedGraphic& placedGraphic);
		void eraseGraphic(int index);

		PlacedGraphic& getGraphic(const VG::Point& point);
		PlacedGraphic& getGraphic(int index);

		[[nodiscard]] size_t getGraphicsCount() const;

		void draw(BitmapGraphics::HCanvas& canvas);
		[[nodiscard]] std::list<PlacedGraphic>::const_iterator begin() const;
		[[nodiscard]] std::list<PlacedGraphic>::const_iterator end() const;

	private:
		std::list<PlacedGraphic> graphics;
		std::string alias;
	};
}
