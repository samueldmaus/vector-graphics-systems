﻿#pragma once
#include "Layer.h"

namespace Framework
{
	class Scene
	{
	public:
		Scene(const int w, const int h);

		Scene(const Scene& other) = default;
		Scene(Scene&& other) noexcept = default;
		~Scene() = default;

		Scene& operator=(const Scene&) = default;
		Scene& operator=(Scene&&) = default;

		void addLayer(const Layer& new_layer);
		void addLayer(Layer&& new_layer);
		void removeLayer(const std::string& name);
		void eraseLayer(int index);

		Layer& getLayer(const std::string& name);
		Layer& getLayer(int index);

		[[nodiscard]] int getWidth() const;
		void setWidth(int new_width);

		[[nodiscard]] int getHeight() const;
		void setHeight(int new_height);

		[[nodiscard]] size_t getLayerCount() const;

	private:
		std::list<Layer> layer;
		int width;
		int height;
	};
}