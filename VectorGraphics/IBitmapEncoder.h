#pragma once
#include <memory>
#include <string>

namespace BitmapGraphics
{
	class IBitmapEncoder
	{
	public:
		using HBitmapEncoder = std::unique_ptr<IBitmapEncoder>;
		
		virtual ~IBitmapEncoder() = default;

		virtual HBitmapEncoder clone(HBitmapEncoder i) = 0;
		virtual void encodeToStream(std::ostream& destinationStream) = 0;
		[[nodiscard]] virtual std::string getMimeType() = 0;
	};
}
