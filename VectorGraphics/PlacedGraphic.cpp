#include "PlacedGraphic.h"

namespace Framework
{
	PlacedGraphic::PlacedGraphic() : placementPoint(VG::Point(0, 0)), graphic(std::make_shared<VG::VectorGraphic>())
	{
	}
	
	PlacedGraphic::PlacedGraphic(const VG::Point& point, VG::HVectorGraphic vectorGraphic) : placementPoint(point), graphic(std::move(vectorGraphic))
	{
	}
	
	void PlacedGraphic::setPlacementPoint(VG::Point const& placement)
	{
		placementPoint = placement;
	}

	VG::Point const& PlacedGraphic::getPlacementPoint() const
	{
		return placementPoint;
	}

	void PlacedGraphic::setGraphic(VG::HVectorGraphic const& vectorGraphic)
	{
		graphic = vectorGraphic;
	}

	const VG::HVectorGraphic& PlacedGraphic::getGraphic() const
	{
		return graphic;
	}

	bool PlacedGraphic::operator==(const PlacedGraphic &other) const
	{
		return (placementPoint == other.getPlacementPoint()) && (graphic == other.getGraphic());
	}

	bool PlacedGraphic::operator!=(const PlacedGraphic &other) const
	{
		return !(*this == other);
	}

	void PlacedGraphic::draw(BitmapGraphics::HCanvas& canvas)
	{
		graphic->draw(placementPoint, canvas);
	}

}
