#include "CodecLibrary.h"

namespace BitmapGraphics
{
	void CodecLibrary::registerEncoder(HBitmapEncoder const& decoder)
	{
		
	}
	
	void CodecLibrary::registerDecoder(HBitmapDecoder const& decoder)
	{
	}
	HBitmapDecoder CodecLibrary::createDecoder(std::istream& sourceStream)
	{
		return HBitmapDecoder();
	}
	
	HBitmapDecoder CodecLibrary::createDecoder(std::string const& mimeType, std::istream& sourceStream)
	{
		return HBitmapDecoder();
	}
	
	HBitmapEncoder CodecLibrary::createEncoder(std::string const& mimeType, HBitmapIterator const& bitmapIterator)
	{
		return HBitmapEncoder();
	}
	
}
