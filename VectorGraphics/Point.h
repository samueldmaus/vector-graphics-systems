#pragma once

#include <iosfwd>

namespace VG
{
    class Point
    {
    public:
        constexpr Point(const int x, const int y) : myX{ x }, myY{ y } { }

        Point(const Point& other) = default;
        Point(Point&& other) = default;
        ~Point() = default;

        Point& operator=(const Point&) = default;
        Point& operator=(Point&&) = default;

        bool operator==(const Point& rhs) const = default;
        bool operator!=(const Point&) const = default;
    	bool operator<(const Point&) const;

        [[nodiscard]] constexpr int getX() const { return myX; }
        [[nodiscard]] constexpr int getY() const { return myY; }

        constexpr void setX(const int x) { myX = x; }
        constexpr void setY(const int y) { myY = y; }

    private:
        int myX{ 0 };
        int myY{ 0 };
    };

    std::ostream& operator<<(std::ostream& os, const Point& p);
}
