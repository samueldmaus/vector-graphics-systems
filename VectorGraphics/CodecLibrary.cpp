#include "CodecLibrary.h"

namespace BitmapGraphics
{
	void CodecLibrary::registerEncoder(HBitmapEncoder encoder)
	{
		encoders.push_back(std::move(encoder));
	}

	void CodecLibrary::registerDecoder(HBitmapDecoder decoder)
	{
		decoders.push_back(std::move(decoder));
	}

	HBitmapDecoder CodecLibrary::createDecoder(std::istream& sourceStream)
	{
		char str[100];
		sourceStream.get(str, 100);
		for (const auto& d : decoders)
		{
			if(d->isSupported(str))
			{
				d->clone(sourceStream);
			}
		}
		throw std::invalid_argument("Not a supported stream");
	}

	HBitmapDecoder CodecLibrary::createDecoder(std::string const& mimeType, std::istream& sourceStream)
	{
		for (const auto& d : decoders)
		{
			if (d->getMimeType() == mimeType)
			{
				return d->clone(sourceStream);
			}
		}
		throw std::invalid_argument(mimeType + " is not a supported MIME Type");
	}

	HBitmapEncoder CodecLibrary::createEncoder(std::string const& mimeType, HBitmapIterator& bitmapIterator)
	{
		for (const auto& e : encoders)
		{
			if (e->getMimeType() == mimeType)
			{
				return e->clone(std::move(bitmapIterator));
			}
		}
		throw std::invalid_argument(mimeType + " is not a supported MIME Type");
	}

}
