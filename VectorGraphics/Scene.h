#pragma once
#include "Layer.h"

namespace Framework
{
	class Scene
	{
	public:
		Scene(int w, int h);

	private:
		std::list<Layer> layer;
		int width;
		int height;
	};
}
