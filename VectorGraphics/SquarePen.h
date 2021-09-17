#pragma once

#include "Color.h"
#include "IPen.h"

namespace BitmapGraphics
{
	class SquarePen : public IPen
	{
	public:
		SquarePen(int s, const Color& c);

		SquarePen(const SquarePen& other) = default;
		SquarePen(SquarePen&& other) = default;
		~SquarePen() override = default;

		SquarePen& operator=(const SquarePen&) = default;
		SquarePen& operator=(SquarePen&&) = default;

		void drawPoint(HCanvas& canvas, VG::Point const& point) override;

	private:
		Color penColor;
		int penSize;
	};
}
