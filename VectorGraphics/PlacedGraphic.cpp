#include "PlacedGraphic.h"

namespace VG
{
	PlacedGraphic::PlacedGraphic(const Point& point, HVectorGraphic vectorGraphic) : placementPoint(point), graphic(std::move(vectorGraphic))
	{
	}
	
	void PlacedGraphic::setPlacementPoint(Point const& placement)
	{
		placementPoint = placement;
	}

	Point const& PlacedGraphic::getPlacementPoint() const
	{
		return placementPoint;
	}

	void PlacedGraphic::setGraphic(HVectorGraphic const& vectorGraphic)
	{
		graphic = vectorGraphic;
	}

	HVectorGraphic const& PlacedGraphic::getGraphic() const
	{
		return graphic;
	}

	
}
