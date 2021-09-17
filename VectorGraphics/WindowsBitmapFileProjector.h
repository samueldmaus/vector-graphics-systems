#pragma once

#include "IProjector.h"

namespace BitmapGraphics
{
	class WindowsBitmapFileProjector : public IProjector
	{
	public:
		WindowsBitmapFileProjector(std::string name, CodecLibrary& cl);

		WindowsBitmapFileProjector(const WindowsBitmapFileProjector& other) = default;
		WindowsBitmapFileProjector(WindowsBitmapFileProjector&& other) = default;
		~WindowsBitmapFileProjector() override = default;

		WindowsBitmapFileProjector& operator=(const WindowsBitmapFileProjector&) = default;
		WindowsBitmapFileProjector& operator=(WindowsBitmapFileProjector&&) = default;

		void projectCanvas(HCanvas const& canvas) override;

	private:
		std::string file;
		CodecLibrary codecLibrary;
	};

	using HProjector = std::unique_ptr<IProjector>;
}
