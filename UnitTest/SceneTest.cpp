#include "TestHarness.h"
#include "Scene.h"

TEST(ctor, Scene)
{
	const Framework::Scene scene(400, 600);

	CHECK_EQUAL(0UL, scene.getLayerCount());
	CHECK_EQUAL(400, scene.getWidth());
	CHECK_EQUAL(600, scene.getHeight());
}

TEST(copyCtor, Scene)
{
	Framework::Scene scene(400, 600);
	scene.addLayer(Framework::Layer("Mountains"));

	Framework::Scene scene_two(scene);

	CHECK_EQUAL(scene.getLayerCount(), scene_two.getLayerCount());
	CHECK_EQUAL("Mountains", scene_two.getLayer(0).getAlias());
}

TEST(copyAssignment, Scene)
{
	Framework::Scene scene(400, 600);
	scene.addLayer(Framework::Layer("Mountains"));

	Framework::Scene scene_two = scene;

	CHECK_EQUAL(scene.getLayerCount(), scene_two.getLayerCount());
	CHECK_EQUAL("Mountains", scene_two.getLayer(0).getAlias());
}

TEST(moveCtor, Scene)
{
	Framework::Scene scene(400, 600);
	scene.addLayer(Framework::Layer("Mountains"));

	Framework::Scene scene_two(std::move(scene));

	CHECK_EQUAL(1UL, scene_two.getLayerCount());
	CHECK_EQUAL("Mountains", scene_two.getLayer(0).getAlias());
}

TEST(moveAssignment, Scene)
{
	Framework::Scene scene(400, 600);
	scene.addLayer(Framework::Layer("Mountains"));

	Framework::Scene scene_two = std::move(scene);

	CHECK_EQUAL(1UL, scene_two.getLayerCount());
	CHECK_EQUAL("Mountains", scene_two.getLayer(0).getAlias());
}

TEST(addLayer, Scene)
{
	Framework::Scene scene(400, 600);
	scene.addLayer(Framework::Layer("Mountains"));

	CHECK_EQUAL(1UL, scene.getLayerCount());
	CHECK_EQUAL("Mountains", scene.getLayer(0).getAlias());
}

TEST(addLayerRValue, Scene)
{
	Framework::Scene scene(400, 600);
	scene.addLayer(Framework::Layer("Mountains"));

	Framework::Layer sea_layer("Sea");
	scene.addLayer(std::move(sea_layer));

	CHECK_EQUAL(2UL, scene.getLayerCount());
	CHECK_EQUAL("Sea", scene.getLayer(1).getAlias());
}

TEST(removeLayer, Scene)
{
	Framework::Scene scene(400, 600);
	scene.addLayer(Framework::Layer("Mountains"));
	scene.addLayer(Framework::Layer("Sea"));

	scene.removeLayer("Sea");

	CHECK_EQUAL(1UL, scene.getLayerCount());
	CHECK_EQUAL("Mountains", scene.getLayer(0).getAlias());
}

TEST(removeLayerNotInLayers, Scene)
{
	bool condition = false;

	Framework::Scene scene(400, 600);
	scene.addLayer(Framework::Layer("Mountains"));
	scene.addLayer(Framework::Layer("Sea"));

	try
	{
		scene.removeLayer("Grass");
	}
	catch (std::invalid_argument&)
	{
		condition = true;
	}
	CHECK(condition);
}

TEST(eraseLayer, Scene)
{
	Framework::Scene scene(400, 600);
	scene.addLayer(Framework::Layer("Mountains"));
	scene.addLayer(Framework::Layer("Sea"));

	scene.eraseLayer(1);

	CHECK_EQUAL(1UL, scene.getLayerCount());
	CHECK_EQUAL("Mountains", scene.getLayer(0).getAlias());
}

TEST(eraseLayerOutOfRange, Scene)
{
	bool condition = false;

	Framework::Scene scene(400, 600);
	scene.addLayer(Framework::Layer("Mountains"));
	scene.addLayer(Framework::Layer("Sea"));

	try
	{
		scene.eraseLayer(2);
	}
	catch (std::out_of_range&)
	{
		condition = true;
	}
	CHECK(condition);
}

TEST(getLayerByName, Scene)
{
	Framework::Scene scene(400, 600);
	scene.addLayer(Framework::Layer("Mountains"));
	scene.addLayer(Framework::Layer("Sea"));

	CHECK_EQUAL("Sea", scene.getLayer("Sea").getAlias());
}

TEST(getLayerByNameInvalidArgument, Scene)
{
	bool condition = false;

	Framework::Scene scene(400, 600);
	scene.addLayer(Framework::Layer("Mountains"));
	scene.addLayer(Framework::Layer("Sea"));

	try
	{
		scene.getLayer("Grass");
	}
	catch (std::invalid_argument&)
	{
		condition = true;
	}
	CHECK(condition);
}

TEST(getLayerByIndex, Scene)
{
	bool condition = false;

	Framework::Scene scene(400, 600);
	scene.addLayer(Framework::Layer("Mountains"));
	scene.addLayer(Framework::Layer("Sea"));

	try
	{
		scene.getLayer(2);
	}
	catch (std::out_of_range&)
	{
		condition = true;
	}
	CHECK(condition);
}

TEST(getLayerMethodsAreEqual, Layer)
{
	Framework::Scene scene(400, 600);
	Framework::Layer layer("Mountains");
	scene.addLayer(std::move(layer));

	CHECK_EQUAL(&scene.getLayer("Mountains"), &scene.getLayer(0));
}

TEST(getWidth, Scene)
{
	const Framework::Scene scene(400, 600);

	CHECK_EQUAL(400, scene.getWidth());
}

TEST(setWdith, Scene)
{
	Framework::Scene scene(400, 600);
	scene.setWidth(600);

	CHECK_EQUAL(600, scene.getWidth());
}

TEST(getHeight, Scene)
{
	const Framework::Scene scene(400, 600);

	CHECK_EQUAL(600, scene.getHeight());
}

TEST(setHeight, Scene)
{
	Framework::Scene scene(400, 600);
	scene.setHeight(800);

	CHECK_EQUAL(800, scene.getHeight());
}

TEST(getLayerSize, Scene)
{
	Framework::Scene scene(400, 600);
	scene.addLayer(Framework::Layer("Mountains"));
	scene.addLayer(Framework::Layer("Sea"));

	CHECK_EQUAL(2UL, scene.getLayerCount());
}