#include "WindowsBitmapFileProjector.h"

#include <fstream>

namespace BitmapGraphics
{
	WindowsBitmapFileProjector::WindowsBitmapFileProjector(std::string name, CodecLibrary& cl) : file(std::move(name)), codecLibrary(cl)
	{
	}

	void WindowsBitmapFileProjector::projectCanvas(HCanvas const& canvas)
	{
		auto iterator = canvas->createBitmapIterator();
		// flip the scan lines
		
		auto encoder = codecLibrary.createEncoder("image/x-ms-bmp", iterator);
		std::ofstream output(file, std::ios::binary);
		encoder->encodeToStream(output);
	}
}