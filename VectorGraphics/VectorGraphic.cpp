#include "VectorGraphic.h"

#include <algorithm>
#include <stdexcept>

namespace VG
{
	VectorGraphic::VectorGraphic() : myShapeStyle(ShapeStyle::Closed)
	{
	}

	
	void VectorGraphic::addPoint(const Point& p)
	{
		myPath.push_back(p);
	}

	void VectorGraphic::addPoint(Point&& p)
	{
		myPath.push_back(p);
	}

	void VectorGraphic::removePoint(const Point& p)
	{
		myPath.erase(std::remove(myPath.begin(), myPath.end(), p), myPath.end());
	}

	void VectorGraphic::erasePoint(int index)
	{
		removePoint(myPath.at(index));
	}

	void VectorGraphic::openShape()
	{
		myShapeStyle = ShapeStyle::Open;
	}

	void VectorGraphic::closeShape()
	{
		myShapeStyle = ShapeStyle::Closed;
	}

	bool VectorGraphic::isOpen() const
	{
		if(myShapeStyle == ShapeStyle::Open)
		{
			return true;
		}
		return false;
	}

	bool VectorGraphic::isClosed() const
	{
		if(myShapeStyle == ShapeStyle::Closed)
		{
			return true;
		}
		return false;
	}

	int VectorGraphic::getWidth() const
	{
		auto leftPoint = myPath.at(0).getX(), rightPoint = myPath.at(0).getX();
		for(auto& point : myPath)
		{
			if(point.getX() < leftPoint)
			{
				leftPoint = point.getX();
			}
			if(point.getX() > rightPoint)
			{
				rightPoint = point.getX();
			}
		}
		return rightPoint - leftPoint;
	}

	int VectorGraphic::getHeight() const
	{
		auto topPoint = myPath.at(0).getY(), botPoint = myPath.at(0).getY();
		for(auto& point : myPath)
		{
			if(point.getY() > topPoint)
			{
				topPoint = point.getY();
			}
			if(point.getY() < botPoint)
			{
				botPoint = point.getY();
			}
		}
		return topPoint - botPoint;
	}

	size_t VectorGraphic::getPointCount() const
	{
		return myPath.size();
	}

	const Point& VectorGraphic::getPoint(int index) const
	{
		return myPath.at(index);
	}

	bool VectorGraphic::operator==(const VectorGraphic &other) const
	{
		if(this->isClosed() != other.isClosed() || this->getPointCount() != other.getPointCount())
		{
			return false;
		}
		for(size_t p = 0; p < this->getPointCount(); ++p)
		{
			if(this->getPoint(p) != other.getPoint(p))
			{
				return false;
			}
		}
		return true;
	}

	bool VectorGraphic::operator!=(const VectorGraphic &other) const
	{
		return !(*this == other);
	}

}
