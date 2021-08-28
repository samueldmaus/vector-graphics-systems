#include "SceneReader.h"
#include <stdexcept>

namespace Framework
{
	Scene Framework::SceneReader::readScene(Xml::Element element)
	{
		if(element.getName() != "Scene")
		{
			throw std::runtime_error("Expected a Scene");
		}
		Scene scene(std::stoi(element.getAttribute("width")), std::stoi(element.getAttribute("height")));
		for (auto& childLayer : element.getChildElements())
		{
			if(childLayer.getName() != "Layer")
			{
				throw std::runtime_error("Expected a Layer");
			}
			Layer layer(childLayer.getAttribute("alias"));
			for (auto& childPlacedGraphic : childLayer.getChildElements())
			{
				if(childPlacedGraphic.getName() != "PlacedGraphic")
				{
					throw std::runtime_error("Expected a Placed Graphic");
				}
				for (auto& childVectorGraphic : childPlacedGraphic.getChildElements())
				{
					VG::VectorGraphic vectorGraphic;
					for (auto& childPoint : childVectorGraphic.getChildElements())
					{
						vectorGraphic.addPoint(VG::Point(std::stoi(childPoint.getAttribute("x")), std::stoi(childPoint.getAttribute("y"))));
					}
					
					if(childVectorGraphic.getAttribute("closed") == "false")
					{
						vectorGraphic.openShape();
					}
					PlacedGraphic placedGraphic(VG::Point(std::stoi(childPlacedGraphic.getAttribute("x")), std::stoi(childPlacedGraphic.getAttribute("y"))), std::make_shared<VG::VectorGraphic>(vectorGraphic));
					layer.addGraphic(placedGraphic);
				}
			}
			scene.addLayer(layer);
		}
		return scene;
	}
	
}