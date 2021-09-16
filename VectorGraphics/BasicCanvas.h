#pragma once

#include <map>

#include "ICanvas.h"

namespace BitmapGraphics
{
	class BasicCanvas : public ICanvas
	{
	public:
		BasicCanvas(int w, int h, const Color& bg);

		BasicCanvas(const BasicCanvas& other) = default;
		BasicCanvas(BasicCanvas&& other) = default;
		~BasicCanvas() override = default;

		BasicCanvas& operator=(const BasicCanvas&) = default;
		BasicCanvas& operator=(BasicCanvas&&) = default;

		void setPixelColor(VG::Point const& location, Color const& color) override;
		[[nodiscard]] Color getPixelColor(VG::Point const& location) const override;
		[[nodiscard]] int getWidth() const override;
		[[nodiscard]] int getHeight() const override;
		[[nodiscard]] HBitmapIterator createBitmapIterator() const override;

		[[nodiscard]] bool outsideDimensions(const VG::Point& point) const;

	private:
		int width;
		int height;
		
		Color backgroundColor;

		std::map<VG::Point, Color> pixelMap;

	};
}
