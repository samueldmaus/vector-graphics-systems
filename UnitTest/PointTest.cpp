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

TEST(copyCtor, Point)
{
	const VG::Point p1{ 2, 2 };

	const VG::Point p2{ p1 };

	CHECK_EQUAL(p1, p2);
}

TEST(copyAssign, Point)
{
	const VG::Point p1{ 2, 2 };
	VG::Point p2{ 3, 3 };
	p2 = p1;

	CHECK_EQUAL(p1, p2);
}

TEST(moveCtor, Point)
{
	VG::Point p1{ 2, 2 };
	const VG::Point p2(std::move(p1));

	CHECK_EQUAL(p2, VG::Point(2, 2));
}

TEST(moveAssign, Point)
{
	VG::Point p1{ 2, 2 };
	VG::Point p2{ 3, 3 };
	p2 = std::move(p1);

	CHECK_EQUAL(p2, VG::Point(2, 2));
}

TEST(constexprPoint, Point)
{
	constexpr int x = VG::Point{ 4, 5 }.getX();

	CHECK_EQUAL(x, 4);
}

TEST(setX, Point)
{
	auto point = VG::Point{ 1, 1 };
	point.setX(2);

	CHECK_EQUAL(2, point.getX());
}

TEST(setY, Point)
{
    auto point = VG::Point{1, 1};
    point.setY(5);

    CHECK_EQUAL(5, point.getY());
}

TEST(streamOperator, Point)
{
    const VG::Point point(1, 1);
    std::stringstream ss;
    ss << point;

    CHECK_EQUAL("(1, 1)", ss.str());
}