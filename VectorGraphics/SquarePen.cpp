#include "SquarePen.h"

namespace BitmapGraphics
{
	SquarePen::SquarePen(int s, const Color& c) : penColor(c), penSize(s)
	{
	}
	
	void SquarePen::drawPoint(const HCanvas& canvas, VG::Point const& point)
	{
		const VG::Point left(point.getX() - (penSize / 2), point.getY() - (penSize / 2));
		for(auto i = 0; i < penSize; ++i)
		{
			VG::Point ref(left.getX(), left.getY() + i );

			for(auto h = 0; h < penSize; ++h)
			{
				ref.setX(ref.getX() + 1);

				canvas->setPixelColor(ref, penColor);
			}
		}
	}
}
