#include "SceneWriter.h"

namespace Framework
{
	Xml::HElement SceneWriter::writeScene(Scene& scene)
	{
		Xml::Element root("Scene");
		root.addAttribute("width", std::to_string(scene.getWidth()));
		root.addAttribute("height", std::to_string(scene.getHeight()));
		for (size_t i = 0; i < scene.getLayerCount(); ++i)
		{
			Xml::Element layerElement("Layer");
			for (size_t h = 0; h < scene.getLayer(i).getGraphicsCount(); ++h)
			{
				Xml::Element pGraphicElement("PlacedGraphic");
				Xml::Element vGraphicElement("VectorGraphic");
				for (size_t g = 0; g < scene.getLayer(i).getGraphic(h).getGraphic()->getPointCount(); ++g)
				{
					Xml::Element pointElement("Point");
					pointElement.addAttribute("x", std::to_string(scene.getLayer(i).getGraphic(h).getGraphic()->getPoint(g).getX()));
					pointElement.addAttribute("y", std::to_string(scene.getLayer(i).getGraphic(h).getGraphic()->getPoint(g).getY()));
					vGraphicElement.addChildElement(pointElement);
				}

				if(scene.getLayer(i).getGraphic(h).getGraphic()->isClosed())
				{
					vGraphicElement.addAttribute("closed", "true");
				}
				else
				{
					vGraphicElement.addAttribute("closed", "false");
				}

				pGraphicElement.addChildElement(vGraphicElement);
				pGraphicElement.addAttribute("x", std::to_string(scene.getLayer(i).getGraphic(h).getPlacementPoint().getX()));
				pGraphicElement.addAttribute("y", std::to_string(scene.getLayer(i).getGraphic(h).getPlacementPoint().getY()));
				layerElement.addChildElement(pGraphicElement);
			}
			layerElement.addAttribute("alias", scene.getLayer(i).getAlias());
			root.addChildElement(layerElement);
		}
		return std::make_shared<Xml::Element>(root);
	}
}