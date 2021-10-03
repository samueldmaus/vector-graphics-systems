#pragma once

#include "VectorGraphic.h"
#include "Point.h"
#include <memory>

namespace Framework
{

    class PlacedGraphic
	{
	public:
		explicit PlacedGraphic();
		PlacedGraphic(const VG::Point& point, VG::HVectorGraphic vectorGraphic);

		PlacedGraphic(const PlacedGraphic& other) = default;
		PlacedGraphic(PlacedGraphic&& other) noexcept = default;
		~PlacedGraphic() = default;

		PlacedGraphic& operator=(const PlacedGraphic&) = default;
		PlacedGraphic& operator=(PlacedGraphic&&) = default;

        void setPlacementPoint (VG::Point const& placement);
        [[nodiscard]] VG::Point const& getPlacementPoint () const;

        void setGraphic (VG::HVectorGraphic const& graphic);
        [[nodiscard]] const VG::HVectorGraphic& getGraphic() const;

    	bool operator==(const PlacedGraphic &other) const;
        bool operator!=(const PlacedGraphic &other) const;

    	void draw(BitmapGraphics::HCanvas& canvas);

    private:
        VG::Point placementPoint;
        VG::HVectorGraphic graphic;
    };
}