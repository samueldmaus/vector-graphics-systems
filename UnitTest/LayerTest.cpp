#include "Layer.h"
#include "TestHarness.h"

TEST(ctor, Layer)
{
	const Framework::Layer layer;

	CHECK_EQUAL("", layer.getAlias());
	CHECK_EQUAL(0UL, layer.getGraphicsCount());
}

TEST(ctorString, Layer)
{
	const Framework::Layer layer("layer");

	CHECK_EQUAL("layer", layer.getAlias());
	CHECK_EQUAL(0UL, layer.getGraphicsCount());
}

TEST(copyCtor, Layer)
{
	Framework::Layer layer("layer");
	VG::HVectorGraphic vg(new VG::VectorGraphic);
    const Framework::PlacedGraphic pg(VG::Point(44, 55), vg);
	
	layer.addGraphic(pg);
	
	auto layer_two(layer);

	CHECK_EQUAL(layer.getAlias(), layer_two.getAlias());
	CHECK_EQUAL(1UL, layer_two.getGraphicsCount());
	CHECK_EQUAL(44, layer_two.getGraphic(0).getPlacementPoint().getX())
}

TEST(moveCtor, Layer)
{
	Framework::Layer layer("layer");
	VG::HVectorGraphic vg(new VG::VectorGraphic);
	const Framework::PlacedGraphic pg(VG::Point(44, 55), vg);

	layer.addGraphic(pg);

	auto new_layer(std::move(layer));

	CHECK_EQUAL("layer", new_layer.getAlias());
	CHECK_EQUAL(1UL, new_layer.getGraphicsCount());
	CHECK_EQUAL(44, new_layer.getGraphic(0).getPlacementPoint().getX());
}

TEST(copyAssignment, Layer)
{
	Framework::Layer layer("layer");
	VG::HVectorGraphic vg(new VG::VectorGraphic);
	const Framework::PlacedGraphic pg(VG::Point(44, 55), vg);

	layer.addGraphic(pg);

	auto layer_two = layer;

	CHECK_EQUAL(layer.getAlias(), layer_two.getAlias());
	CHECK_EQUAL(1UL, layer_two.getGraphicsCount());
	CHECK_EQUAL(44, layer_two.getGraphic(0).getPlacementPoint().getX())
}

TEST(moveAssignment, Layer)
{
	Framework::Layer layer("layer");
	VG::HVectorGraphic vg(new VG::VectorGraphic);
	const Framework::PlacedGraphic pg(VG::Point(44, 55), vg);

	layer.addGraphic(pg);

	auto new_layer = std::move(layer);

	CHECK_EQUAL("layer", new_layer.getAlias());
	CHECK_EQUAL(1UL, new_layer.getGraphicsCount());
	CHECK_EQUAL(44, new_layer.getGraphic(0).getPlacementPoint().getX());
}

TEST(setAndGetAlias, Layer)
{
	Framework::Layer layer("layer");
	CHECK_EQUAL("layer", layer.getAlias());

	layer.setAlias("new layer");
	CHECK_EQUAL("new layer", layer.getAlias());
}

TEST(addGraphic, Layer)
{
	Framework::Layer layer("layer");
	VG::HVectorGraphic vg(new VG::VectorGraphic);
	const Framework::PlacedGraphic pg(VG::Point(50, 50), vg);

	layer.addGraphic(pg);

	CHECK_EQUAL(1UL, layer.getGraphicsCount());
}

TEST(addRValueGraphic, Layer)
{
	Framework::Layer layer("layer");
	VG::HVectorGraphic vg(new VG::VectorGraphic);
	Framework::PlacedGraphic pg(VG::Point(50, 50), vg);

	layer.addGraphic(std::move(pg));

	layer.getGraphic(0).setPlacementPoint(VG::Point(10, 10));

	CHECK_EQUAL(VG::Point(10, 10), layer.getGraphic(0).getPlacementPoint());
}

TEST(removeGraphic, Layer)
{
	Framework::Layer layer("layer");
	VG::HVectorGraphic vg(new VG::VectorGraphic);
	const Framework::PlacedGraphic pg(VG::Point(50, 50), vg);

	VG::HVectorGraphic vg2(new VG::VectorGraphic);
	const Framework::PlacedGraphic pg2(VG::Point(1, 1), vg2);
	
	layer.addGraphic(pg);
	layer.addGraphic(pg2);

	layer.removeGraphic(VG::Point(1, 1));

	CHECK_EQUAL(1UL, layer.getGraphicsCount());
	CHECK_EQUAL(VG::Point(50, 50), layer.getGraphic(0).getPlacementPoint());
}

TEST(removeGraphicNotInGraphics, Layer)
{
	bool condition = false;
	
	Framework::Layer layer("layer");
	VG::HVectorGraphic vg(new VG::VectorGraphic);
	const Framework::PlacedGraphic pg(VG::Point(50, 50), vg);

	VG::HVectorGraphic vg2(new VG::VectorGraphic);
	const Framework::PlacedGraphic pg2(VG::Point(1, 1), vg2);

	layer.addGraphic(pg);
	layer.addGraphic(pg2);

	try
	{
		layer.removeGraphic(VG::Point(25, 25));
	}
	catch(std::invalid_argument&)
	{
		condition = true;
	}

	CHECK(condition);
}

TEST(eraseGraphic, Layer)
{
	Framework::Layer layer("layer");
	VG::HVectorGraphic vg(new VG::VectorGraphic);
	const Framework::PlacedGraphic pg(VG::Point(50, 50), vg);

	VG::HVectorGraphic vg2(new VG::VectorGraphic);
	const Framework::PlacedGraphic pg2(VG::Point(1, 1), vg2);

	layer.addGraphic(pg);
	layer.addGraphic(pg2);

	layer.eraseGraphic(0);

	CHECK_EQUAL(1UL, layer.getGraphicsCount());
	CHECK_EQUAL(VG::Point(1, 1), layer.getGraphic(0).getPlacementPoint());
}

TEST(eraseGraphicOutOfRange, Layer)
{
	auto condition = false;
	
	Framework::Layer layer("layer");

	const Framework::PlacedGraphic pg(VG::Point(50, 50), std::make_shared<VG::VectorGraphic>());

	const Framework::PlacedGraphic pg2(VG::Point(1, 1), std::make_shared<VG::VectorGraphic>());

	layer.addGraphic(pg);
	layer.addGraphic(pg2);

	try
	{
		layer.eraseGraphic(2);
	}
	catch(std::out_of_range&)
	{
		condition = true;
	}
	CHECK(condition);
}

TEST(getGraphicByPoint, Layer)
{
	Framework::Layer layer("layer");
	const Framework::PlacedGraphic pg(VG::Point(50, 50), std::make_shared<VG::VectorGraphic>());

	const Framework::PlacedGraphic pg2(VG::Point(1, 1), std::make_shared<VG::VectorGraphic>());

	layer.addGraphic(pg);
	layer.addGraphic(pg2);

	CHECK(pg2 == layer.getGraphic(VG::Point(1, 1)));
}

TEST(getGraphicByPointInvalidArgument, Layer)
{
	bool condition = false;

	Framework::Layer layer("layer");
	const Framework::PlacedGraphic pg(VG::Point(50, 50), std::make_shared<VG::VectorGraphic>());

	const Framework::PlacedGraphic pg2(VG::Point(1, 1), std::make_shared<VG::VectorGraphic>());

	layer.addGraphic(pg);
	layer.addGraphic(pg2);

	try
	{
		layer.getGraphic(VG::Point(100, 100));
	}
	catch (std::invalid_argument&)
	{
		condition = true;
	}
	CHECK(condition);
}

TEST(getGrahpicByIndex, Layer)
{
	Framework::Layer layer("layer");
	const Framework::PlacedGraphic pg(VG::Point(50, 50), std::make_shared<VG::VectorGraphic>());

	const Framework::PlacedGraphic pg2(VG::Point(1, 1), std::make_shared<VG::VectorGraphic>());

	layer.addGraphic(pg);
	layer.addGraphic(pg2);

	CHECK(pg2 == layer.getGraphic(1));
}

TEST(getGraphicByIndexOutOfRange, Layer)
{
	bool condition = false;

	Framework::Layer layer("layer");
	const Framework::PlacedGraphic pg(VG::Point(50, 50), std::make_shared<VG::VectorGraphic>());

	const Framework::PlacedGraphic pg2(VG::Point(1, 1), std::make_shared<VG::VectorGraphic>());

	try
	{
		layer.getGraphic(2);
	}
	catch (std::out_of_range&)
	{
		condition = true;
	}

	CHECK(condition);
}

TEST(getGraphicMethodsAreEqual, Layer)
{
	Framework::Layer layer("layer");
	Framework::PlacedGraphic pg(VG::Point(10, 10), std::make_shared<VG::VectorGraphic>());
	layer.addGraphic(std::move(pg));

	CHECK_EQUAL(&layer.getGraphic(VG::Point(10, 10)), &layer.getGraphic(0));
}

TEST(graphicsSize, Layers)
{
	Framework::Layer layer("layer");
	const VG::HVectorGraphic vg(new VG::VectorGraphic);
	const Framework::PlacedGraphic pg(VG::Point(50, 50), vg);

	layer.addGraphic(pg);

	CHECK_EQUAL(1UL, layer.getGraphicsCount());
}