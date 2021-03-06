#include "XmlReader.h"
#include "Scene.h"
#include "SceneReader.h"
#include "SceneWriter.h"
#include "TestHarness.h"

#define STR(a) #a

const char* const TestXml = STR(
<Scene width="800" height="600">
  <Layer alias="sky">
    <PlacedGraphic x="86" y="99">
      <VectorGraphic closed="true">
        <Point x="1" y="2" />
        <Point x="3" y="4" />
        <Point x="5" y="6" />
      </VectorGraphic>
    </PlacedGraphic>
    <PlacedGraphic x="700" y="0">
      <VectorGraphic closed="false">
        <Point x="7" y="8" />
        <Point x="9" y="10" />
        <Point x="11" y="12" />
        <!--- etc. ---------->
      </VectorGraphic>
    </PlacedGraphic>
  </Layer>
  <Layer alias="mountains">
    <PlacedGraphic x="250" y="250">
      <VectorGraphic closed="false">
        <Point x="13" y="14" />
        <Point x="15" y="19" />
        <Point x="17" y="18" />
      </VectorGraphic>
    </PlacedGraphic>
  </Layer>
</Scene>);


TEST(WriteScene, SceneWriter)
{
	std::stringstream xmlStream(TestXml);

	// Parse the XML stream and create an XML "DOM"
	Xml::HElement readRoot = Xml::Reader::loadXml(xmlStream);

	// Construct a Scene from the DOM
	Framework::Scene scene = Framework::SceneReader::readScene(*readRoot);

	// Go back the other way and construct another DOM from the Scene
	Xml::HElement root = Framework::SceneWriter::writeScene(scene);

	// Now verify some things in the new DOM...

	CHECK_EQUAL("Scene", root->getName());
	CHECK_EQUAL("800", root->getAttribute("width"));
	CHECK_EQUAL("600", root->getAttribute("height"));
}

TEST(sceneAttributes, SceneWriter)
{
	std::stringstream xmlStream(TestXml);

	// Parse the XML stream and create an XML "DOM"
	Xml::HElement readRoot = Xml::Reader::loadXml(xmlStream);

	// Construct a Scene from the DOM
	Framework::Scene scene = Framework::SceneReader::readScene(*readRoot);

	// Go back the other way and construct another DOM from the Scene
	Xml::HElement root = Framework::SceneWriter::writeScene(scene);

	Xml::AttributeMap attributes = root->getAttributes();

	CHECK_EQUAL(2, attributes.size());
}

TEST(sceneLayer, SceneWriter)
{
	std::stringstream xmlStream(TestXml);

	// Parse the XML stream and create an XML "DOM"
	Xml::HElement readRoot = Xml::Reader::loadXml(xmlStream);

	// Construct a Scene from the DOM
	Framework::Scene scene = Framework::SceneReader::readScene(*readRoot);

	// Go back the other way and construct another DOM from the Scene
	Xml::HElement root = Framework::SceneWriter::writeScene(scene);
	Xml::ElementList childElements = root->getChildElements();
	Xml::Element child = childElements[0];
	CHECK_EQUAL("Layer", child.getName());
	CHECK_EQUAL(1, child.getAttributes().size());
	CHECK_EQUAL("sky", child.getAttribute("alias"));
}

TEST(scenePlacedGraphics, SceneWriter)
{
	std::stringstream xmlStream(TestXml);

	// Parse the XML stream and create an XML "DOM"
	Xml::HElement readRoot = Xml::Reader::loadXml(xmlStream);

	// Construct a Scene from the DOM
	Framework::Scene scene = Framework::SceneReader::readScene(*readRoot);

	// Go back the other way and construct another DOM from the Scene
	Xml::HElement root = Framework::SceneWriter::writeScene(scene);
	Xml::ElementList childElements = root->getChildElements();
	Xml::Element child = childElements[0];

	Xml::ElementList pGraphicChildElements = child.getChildElements();
	Xml::Element pChild = pGraphicChildElements[0];

	CHECK_EQUAL("PlacedGraphic", pChild.getName());
	CHECK_EQUAL(2, pGraphicChildElements.size());
	CHECK_EQUAL("86", pChild.getAttribute("x"))
		CHECK_EQUAL("99", pChild.getAttribute("y"))
}

TEST(sceneVectorGraphic, SceneWriter)
{
	std::stringstream xmlStream(TestXml);

	// Parse the XML stream and create an XML "DOM"
	Xml::HElement readRoot = Xml::Reader::loadXml(xmlStream);

	// Construct a Scene from the DOM
	Framework::Scene scene = Framework::SceneReader::readScene(*readRoot);

	// Go back the other way and construct another DOM from the Scene
	Xml::HElement root = Framework::SceneWriter::writeScene(scene);
	Xml::ElementList childElements = root->getChildElements();
	Xml::Element child = childElements[0];

	Xml::ElementList pGraphicChildElements = child.getChildElements();
	Xml::Element pChild = pGraphicChildElements[0];

	Xml::ElementList vGraphicsChildElements = pChild.getChildElements();
	Xml::Element vChild = vGraphicsChildElements[0];

	CHECK_EQUAL("VectorGraphic", vChild.getName());
	CHECK_EQUAL(1, vGraphicsChildElements.size());
	CHECK_EQUAL("true", vChild.getAttribute("closed"));
}

TEST(scenePoint, SceneWriter)
{
	std::stringstream xmlStream(TestXml);

	// Parse the XML stream and create an XML "DOM"
	Xml::HElement readRoot = Xml::Reader::loadXml(xmlStream);

	// Construct a Scene from the DOM
	Framework::Scene scene = Framework::SceneReader::readScene(*readRoot);

	// Go back the other way and construct another DOM from the Scene
	Xml::HElement root = Framework::SceneWriter::writeScene(scene);
	Xml::ElementList childElements = root->getChildElements();
	Xml::Element child = childElements[0];

	Xml::ElementList pGraphicChildElements = child.getChildElements();
	Xml::Element pChild = pGraphicChildElements[0];

	Xml::ElementList vGraphicsChildElements = pChild.getChildElements();
	Xml::Element vChild = vGraphicsChildElements[0];

	Xml::ElementList pointChildElements = vChild.getChildElements();
	Xml::Element pointChild = pointChildElements[0];

	CHECK_EQUAL("Point", pointChild.getName());
	CHECK_EQUAL(3, pointChildElements.size());
	CHECK_EQUAL("1", pointChild.getAttribute("x"));
	CHECK_EQUAL("2", pointChild.getAttribute("y"));
}
