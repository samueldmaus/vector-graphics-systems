#include "Point.h"
#include <iostream>

namespace VG
{

	std::ostream& operator<<(std::ostream& os, const Point& p)
	{
		os << "(" << p.getX() << ", " << p.getY() << ")";
		return os;
	}

	bool Point::operator<(const Point& rhs) const
	{
		return (myX < rhs.getX()) || (myX == rhs.getX() && myY < rhs.getY());
	}

	Point Point::operator+(const Point& rhs) const
	{
		return { getX() + rhs.getX(), getY() + rhs.getY() };
	}

}
