#include "XmlReader.h"
#include "Element.h"
#include "Scene.h"
#include "SceneReader.h"
#include "TestHarness.h"

const std::string TestXml = R"(
<Scene width="800" height="600">
  <Layer alias="sky">
    <PlacedGraphic x="0" y="0">
      <VectorGraphic closed="true">
        <Point x="1" y="2" />
        <!-- Comment -->
        <Point x="3" y="4" />
        <Point x="5" y="6" />
      </VectorGraphic>
    </PlacedGraphic>
    <!-- Comment -->
    <PlacedGraphic x="700" y="0">
      <VectorGraphic closed="false">
        <Point x="7" y="8" />
        <Point x="9" y="10" />
        <Point x="11" y="12" />
      </VectorGraphic>
    </PlacedGraphic>
  </Layer>
  <Layer alias="mountains">
    <PlacedGraphic x="250" y="250">
      <VectorGraphic closed="false">
        <Point x="13" y="14" />
        <Point x="15" y="19" />
        <Point x="17" y="18" />
        <!-- etc... -->
      </VectorGraphic>
    </PlacedGraphic>
  </Layer>
</Scene>)";

TEST(readScene, SceneReader)
{
	std::stringstream xmlStream(TestXml);
	const auto root = Xml::Reader::loadXml(xmlStream);

	const auto scene = Framework::SceneReader::readScene(*root);

	CHECK_EQUAL(800, scene.getWidth());
	CHECK_EQUAL(600, scene.getHeight());
}

TEST(readSceneLayers, SceneReader)
{
	std::stringstream xmlStream(TestXml);
	const auto root = Xml::Reader::loadXml(xmlStream);

	auto scene = Framework::SceneReader::readScene(*root);

	CHECK_EQUAL(2, scene.getLayerCount());
	CHECK_EQUAL("sky", scene.getLayer(0).getAlias());
	CHECK_EQUAL("mountains", scene.getLayer(1).getAlias());
}

TEST(readScenePlacedGraphics, SceneReader)
{
	std::stringstream xmlStream(TestXml);
	const auto root = Xml::Reader::loadXml(xmlStream);

	auto scene = Framework::SceneReader::readScene(*root);

	auto& layer = scene.getLayer("sky");

	CHECK_EQUAL(2, layer.getGraphicsCount());

	const auto& pGraphic = layer.getGraphic(VG::Point(0, 0));
	
	CHECK_EQUAL(VG::Point(0, 0), pGraphic.getPlacementPoint());
	CHECK_EQUAL(3UL, pGraphic.getGraphic()->getPointCount());
}

TEST(readSceneVectorGraphic, SceneReader)
{
		std::stringstream xmlStream(TestXml);
	const auto root = Xml::Reader::loadXml(xmlStream);

	auto scene = Framework::SceneReader::readScene(*root);

	auto& layer = scene.getLayer("mountains");
	
    const auto& pGraphic = layer.getGraphic(VG::Point(250, 250));
	
	auto& hVGraphic = pGraphic.getGraphic();

	CHECK(hVGraphic->isOpen());
    CHECK_EQUAL(3UL, hVGraphic->getPointCount());
	CHECK_EQUAL(VG::Point(15, 19), hVGraphic->getPoint(1));
}
