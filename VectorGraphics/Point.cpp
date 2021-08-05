#include "Point.h"
#include <iostream>

namespace VG
{

    std::ostream& operator<<(std::ostream& os, const Point& p)
    {
        os << "(" << p.getX() << ", " << p.getY() << ")";
        return os;
    }

}
