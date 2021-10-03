#pragma once

#include "ICanvas.h"
#include "IPen.h"

namespace BitmapGraphics
{
	class IStroke
	{
	public:
		virtual ~IStroke() = default;

		virtual void setSize(int size) = 0;
		[[nodiscard]] virtual int getSize() const = 0;
		virtual void setColor(Color const& color) = 0;
		[[nodiscard]] virtual Color getColor() const = 0;
		virtual HPen createPen(HCanvas const& canvas) = 0;
	};

	using HStroke = std::unique_ptr<IStroke>;
}
