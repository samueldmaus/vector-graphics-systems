#include "SquareStroke.h"
#include "SquarePen.h"

namespace BitmapGraphics
{
	SquareStroke::SquareStroke(int s, const Color& c) : strokeColor(c), strokeSize(s)
	{
	}

	void SquareStroke::setSize(int size)
	{
		strokeSize = size;
	}

	int SquareStroke::getSize() const
	{
		return strokeSize;
	}

	void SquareStroke::setColor(Color const& color)
	{
		strokeColor = color;
	}

	Color SquareStroke::getColor() const
	{
		return strokeColor;
	}

	HPen SquareStroke::createPen(HCanvas const& canvas)
	{
		return std::make_unique<SquarePen>(getSize(), getColor());
	}

}

