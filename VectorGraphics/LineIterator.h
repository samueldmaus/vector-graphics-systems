#pragma once

#include "Point.h"

class LineIterator
{
public:
    LineIterator(const VG::Point& beginPoint, const VG::Point& endPoint);
    [[nodiscard]] bool isEnd() const;
    [[nodiscard]] VG::Point getBeginPoint() const;
    [[nodiscard]] VG::Point getEndPoint() const;
    [[nodiscard]] VG::Point getCurrentPoint() const;
    void nextPoint();

private:
    VG::Point myBeginPoint;
    VG::Point myEndPoint;
    VG::Point myCurrentPoint;

    int myDeltaX;
    int myDeltaY;
    int myStepX;
    int myStepY;
	int myFraction;
};
