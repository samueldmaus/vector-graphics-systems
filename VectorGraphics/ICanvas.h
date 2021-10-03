#pragma once
#include <memory>

#include "BitmapIterator.h"
#include "Point.h"

namespace BitmapGraphics
{
	class ICanvas
{
public:
    virtual ~ICanvas() = default;
		
    virtual void setPixelColor (VG::Point const& location, Color const& color) = 0;
    [[nodiscard]] virtual Color getPixelColor (VG::Point const& location) const = 0;
    [[nodiscard]] virtual int getWidth () const = 0;
    [[nodiscard]] virtual int getHeight () const = 0;
    [[nodiscard]] virtual HBitmapIterator createBitmapIterator () const = 0;
};
	
	using HCanvas = std::unique_ptr<ICanvas>;
}
