#pragma once

namespace BitmapGraphics
{

	inline int numberOfPadBytes(int widthInPixels)
	{
		const auto remainder{ (widthInPixels * 3) % 4 };
		return (remainder == 0) ? 0 : (4 - remainder);
	}
}
