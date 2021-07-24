//
//  PointTest.cpp
//  Assignment1
//
//  Created by Chris Elderkin on 4/26/15.
//  Copyright (c) 2015 Chris Elderkin. All rights reserved.
//

#include "Point.h"
#include "TestHarness.h"


TEST(equality, Point)
{
    CHECK_EQUAL(VG::Point(1, 2), VG::Point(1, 2));
}

TEST(inequality, Point)
{
    CHECK(VG::Point(1, 2) != VG::Point(3, 4));
}

TEST(constexprPoint, Point)
{
    constexpr int x = VG::Point{4, 5}.getX();

    CHECK_EQUAL(x, 4);
}

TEST(setXY, Point)
{
    auto point = VG::Point{1, 1};
    point.setX(2);
    point.setY(5);

    CHECK_EQUAL(2, point.getX());
    CHECK_EQUAL(5, point.getY());
}

TEST(streamOperator, Point)
{
    const VG::Point point(1, 1);
    std::stringstream ss;
    ss << point;

    CHECK_EQUAL("(1, 1)", ss.str());
}