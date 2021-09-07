#pragma once
#include <list>
#include <string>

#include "IBitmapIterator.h"
#include "IBitmapDecoder.h"
#include "IBitmapEncoder.h"

#include <memory>

namespace BitmapGraphics
{
	using HBitmapIterator = std::unique_ptr<IBitmapIterator>;
	using HBitmapEncoder = std::unique_ptr<IBitmapEncoder>;
	using HBitmapDecoder = std::unique_ptr<IBitmapDecoder>;
	
	class CodecLibrary {
	public:
		explicit CodecLibrary() = default;

		CodecLibrary(const CodecLibrary& other) = default;
		CodecLibrary(CodecLibrary&& other) noexcept = default;
		~CodecLibrary() = default;

		CodecLibrary& operator=(const CodecLibrary&) = default;
		CodecLibrary& operator=(CodecLibrary&&) = default;

		void registerEncoder(HBitmapEncoder encoder);
		void registerDecoder(HBitmapDecoder decoder);

		// provide a mime type version and an
		// auto determination version of createDecoder
		HBitmapDecoder createDecoder(std::istream& sourceStream);
		HBitmapDecoder createDecoder(std::string const& mimeType,
			std::istream& sourceStream);

		HBitmapEncoder createEncoder(std::string const& mimeType,
			HBitmapIterator& bitmapIterator);

	private:
		std::list<HBitmapDecoder> decoders;
		std::list<HBitmapEncoder> encoders;
		
	};
}
