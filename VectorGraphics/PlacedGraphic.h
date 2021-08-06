#pragma once

#include "VectorGraphic.h"
#include "Point.h"
#include <memory>

namespace VG
{
    using HVectorGraphic = std::shared_ptr<VectorGraphic>;

    class PlacedGraphic
    {
    public:
    	PlacedGraphic(const Point& point, HVectorGraphic vectorGraphic);

        void setPlacementPoint (Point const& placement);
        [[nodiscard]] Point const& getPlacementPoint () const;

        void setGraphic (HVectorGraphic const& graphic);
        [[nodiscard]] HVectorGraphic const& getGraphic() const;

    private:
        Point placementPoint;
        HVectorGraphic graphic;
    };
}