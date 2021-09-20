#pragma once

#include <memory>

#include "Point.h"
#include <vector>

#include "ICanvas.h"
#include "IStroke.h"

namespace VG
{
	class VectorGraphic;
	
	using HVectorGraphic = std::shared_ptr<VG::VectorGraphic>;
    using Points = std::vector<Point>;
	using PointsIterator = Points::const_iterator;

    class VectorGraphic
    {
    public:
        VectorGraphic();

        VectorGraphic(const VectorGraphic& other) = delete;
        VectorGraphic(VectorGraphic&& other) = default;
        ~VectorGraphic() = default;

        VectorGraphic& operator=(const VectorGraphic&) = delete;
        VectorGraphic& operator=(VectorGraphic&&) = default;

        void addPoint(const Point& p);
        void addPoint(Point&& p);
        void removePoint(const Point& p);
        void erasePoint(int index);

        void openShape();
        void closeShape();

        [[nodiscard]] bool isOpen() const;
        [[nodiscard]] bool isClosed() const;

        [[nodiscard]] int getWidth() const;
        [[nodiscard]] int getHeight() const;

        [[nodiscard]] size_t getPointCount() const;
        [[nodiscard]] const Point& getPoint(int index) const;

    	void draw (Point const& upperLeftOrigin, BitmapGraphics::HCanvas& canvas);
    	[[nodiscard]] PointsIterator begin() const;
    	[[nodiscard]] PointsIterator end() const;

        bool operator==(const VectorGraphic &other) const;
        bool operator!=(const VectorGraphic &other) const;

    private:
    	Points myPath;
    	BitmapGraphics::HStroke stroke;

        enum class ShapeStyle { Open, Closed } myShapeStyle;
    };

}
