﻿#include "XmlWriter.h"
#include "XmlReader.h"
#include "VectorGraphic.h"
#include "TestHarness.h"

#define STR(a) #a

const char* const SceneXml = STR(
<Scene width="800" height="600">
  <Layer alias="sky">
    <PlacedGraphic x="0" y="0">
      <VectorGraphic closed="true">
        <Point x="1" y="2" />
        <Point x="3" y="4" />
        <Point x="5" y="6" />
      </VectorGraphic>
    </PlacedGraphic>
    <PlacedGraphic x="700" y="0">
      <VectorGraphic closed="true">
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
      </VectorGraphic>
    </PlacedGraphic>
  </Layer>
</Scene>);


TEST(writeXml, XmlWriter)
{
    std::stringstream xmlStream(SceneXml);
    Xml::HElement root = Xml::Reader::loadXml(xmlStream);

	std::stringstream ss;
    Xml::Writer::writeXml(root, ss);

	const bool condition = strcmp(SceneXml, ss.str().c_str());
	
    CHECK(condition);
}
