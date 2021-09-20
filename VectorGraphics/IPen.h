#pragma once
#include <memory>

#include "Point.h"
#include <ICanvas.h>

namespace BitmapGraphics
{
	class IPen
	{
	public:
		virtual ~IPen() = default;

		virtual void drawPoint(const HCanvas& canvas, VG::Point const& point) = 0;
	};

	using HPen = std::unique_ptr<IPen>;
}
