#include "BasicCanvas.h"
#include "XmlReader.h"
#include "Element.h"
#include "Scene.h"
#include "SceneReader.h"
#include "TestHarness.h"
#include "WindowsBitmapDecoder.h"
#include "WindowsBitmapEncoder.h"
#include "Color.h"
#include "WindowsBitmapFileProjector.h"

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


const std::string SceneXml = R"(
<Scene width="800" height="800">
  <Layer alias="bottom">
    <PlacedGraphic x="0" y="0">
      <VectorGraphic closed="true">
        <Stroke tip="slash" size="7" color="FF0000" />
        <Point x="100" y="500" />
        <Point x="100" y="100" />
        <Point x="500" y="600" />
       </VectorGraphic>
    </PlacedGraphic>
    <PlacedGraphic x="400" y="300">
      <VectorGraphic closed="true">
        <Stroke tip="square" size="5" color="00FF00" />
        <Point x="0" y="0" />
        <Point x="0" y="100" />
        <Point x="100" y="100" />
        <Point x="100" y="0" />
      </VectorGraphic>
    </PlacedGraphic>
  </Layer>
  <Layer alias="top">
    <PlacedGraphic x="250" y="250">
      <VectorGraphic closed="false">
        <Stroke tip="square" size="3" color="0000FF" />
        <Point x="0" y="0" />
        <Point x="0" y="100" />
        <Point x="100" y="100" />
        <Point x="100" y="0" />
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

namespace
{
	class CodecLibrarySetup
	{
	public:
		CodecLibrarySetup()
		{
			myCodecLibrary.registerEncoder(std::make_unique<BitmapGraphics::WindowsBitmapEncoder>());
			myCodecLibrary.registerDecoder(std::make_unique<BitmapGraphics::WindowsBitmapDecoder>());
		}

		operator BitmapGraphics::CodecLibrary& ()
		{
			return myCodecLibrary;
		}

	private:
		BitmapGraphics::CodecLibrary myCodecLibrary;

	};
}

TEST(toBitmap, SceneReader)
{
	std::stringstream xmlStream(SceneXml);

	// Parse the XML into a DOM
	Xml::HElement root = Xml::Reader::loadXml(xmlStream);

	// Construct a vector graphic Scene from the DOM
	Framework::Scene scene = Framework::SceneReader::readScene(*root);

	// Create an empty Canvas
	BitmapGraphics::Color backgroundColor(100, 100, 100);
	BitmapGraphics::HCanvas canvas = std::make_unique<BitmapGraphics::BasicCanvas>(scene.getWidth(), scene.getHeight(), backgroundColor);

	// Draw the Scene onto the Canvas
	scene.draw(canvas);

	// Create a WindowsBitmapFileProjector and give it an output file name to create
	// Also give it the CodecLibrary ("dependency injection").
	CodecLibrarySetup codecLibrary;
	BitmapGraphics::HProjector projector = std::make_unique<BitmapGraphics::WindowsBitmapFileProjector>("output_scene.bmp", codecLibrary);

	// Project the Canvas into the bitmap file
	projector->projectCanvas(canvas);
}