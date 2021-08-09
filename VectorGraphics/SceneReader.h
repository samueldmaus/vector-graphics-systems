#pragma once

#include "Element.h"
#include "Scene.h"

namespace Framework
{
	class SceneReader
	{
	public:
		SceneReader() = default;

		SceneReader(const SceneReader& other) = default;
		SceneReader(SceneReader&& other) noexcept = default;
		~SceneReader() = default;

		SceneReader& operator=(const SceneReader&) = default;
		SceneReader& operator=(SceneReader&&) = default;

		static Scene readScene(Xml::Element element);
	};
}
