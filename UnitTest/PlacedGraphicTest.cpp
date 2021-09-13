#include "PlacedGraphic.h"
#include "VectorGraphic.h"
#include "TestHarness.h"

TEST(ctor, PlacedGraphic)
{
    const auto vg = std::make_shared<VG::VectorGraphic>();
    Framework::PlacedGraphic pg(VG::Point(44, 55), vg);

	constexpr VG::Point expected(44, 55);
	CHECK_EQUAL(expected, pg.getPlacementPoint());
	CHECK_EQUAL(vg.get(), pg.getGraphic().get());
}

TEST(copyCtor, PlacedGraphics)
{
	const Framework::PlacedGraphic pg(VG::Point(44, 55), std::make_shared<VG::VectorGraphic>());

	const Framework::PlacedGraphic pg2(pg);

	CHECK_EQUAL(2, pg.getGraphic().use_count());
	CHECK_EQUAL(pg.getPlacementPoint(), pg2.getPlacementPoint());
}

TEST(copyAssignment, PlacedGraphics)
{
	const Framework::PlacedGraphic pg(VG::Point(44, 55), std::make_shared<VG::VectorGraphic>());

	const auto pg2 = pg;

	CHECK_EQUAL(2, pg.getGraphic().use_count());
	CHECK_EQUAL(pg.getPlacementPoint(), pg2.getPlacementPoint());
}

TEST(moveCtor, PlacedGraphics)
{
	Framework::PlacedGraphic pg(VG::Point(44, 55), std::make_shared<VG::VectorGraphic>());

	const auto pg2(std::move(pg));

	CHECK_EQUAL(1, pg2.getGraphic().use_count());
	CHECK_EQUAL(VG::Point(44, 55), pg2.getPlacementPoint());
}

TEST(moveAssignment, PlacedGraphics)
{
	Framework::PlacedGraphic pg(VG::Point(44, 55), std::make_shared<VG::VectorGraphic>());

	const auto pg2 = std::move(pg);

	CHECK_EQUAL(1, pg2.getGraphic().use_count());
	CHECK_EQUAL(VG::Point(44, 55), pg2.getPlacementPoint());
}

TEST(setPlacementPoint, PlacedGraphic)
{
	Framework::PlacedGraphic graphic;
	graphic.setPlacementPoint(VG::Point(44, 55));

	constexpr VG::Point expected(44, 55);
	CHECK_EQUAL(expected, graphic.getPlacementPoint());
}

TEST(getPlacementPoint, PlacedGraphic)
{
	Framework::PlacedGraphic pg(VG::Point(44, 55), std::make_shared<VG::VectorGraphic>());
	pg.setPlacementPoint(VG::Point(10, 10));

	CHECK_EQUAL(VG::Point(10, 10), pg.getPlacementPoint());
}

TEST(setGraphic, PlacedGraphic)
{
    Framework::PlacedGraphic pg;
    const auto vg = std::make_shared<VG::VectorGraphic>();
    pg.setGraphic(vg);

    CHECK_EQUAL(vg.get(), pg.getGraphic().get());
}
