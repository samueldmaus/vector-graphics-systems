#pragma once

#include "Element.h"
#include "Scene.h"

namespace Framework
{
	class SceneWriter
	{
	public:
		SceneWriter() = default;
		
		SceneWriter(const SceneWriter& other) = default;
		SceneWriter(SceneWriter&& other) noexcept = default;
		~SceneWriter() = default;

		SceneWriter& operator=(const SceneWriter&) = default;
		SceneWriter& operator=(SceneWriter&&) = default;

		static Xml::HElement writeScene(Scene& scene);
	};
}