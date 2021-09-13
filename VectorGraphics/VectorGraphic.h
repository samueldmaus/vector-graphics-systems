#pragma once

#include <memory>

#include "Point.h"
#include <vector>

namespace VG
{
	class VectorGraphic;
	
	using HVectorGraphic = std::shared_ptr<VG::VectorGraphic>;
    using Points = std::vector<Point>;

    class VectorGraphic
    {
    public:
        VectorGraphic();

        VectorGraphic(const VectorGraphic& other) = default;
        VectorGraphic(VectorGraphic&& other) = default;
        ~VectorGraphic() = default;

        VectorGraphic& operator=(const VectorGraphic&) = default;
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

        bool operator==(const VectorGraphic &other) const;
        bool operator!=(const VectorGraphic &other) const;

    private:
    	Points myPath;

        enum class ShapeStyle { Open, Closed } myShapeStyle;
    };

}
