#include "TestHarness.h"

#include "CodecLibrary.h"
#include "BrightnessDecorator.h"
//#include "ColorInversionDecorator.h"
#include "WindowsBitmapDecoder.h"
#include "WindowsBitmapEncoder.h"
#include "BitmapIterator.h"
#include <fstream>
#include <functional>
#include <iostream>
#include <memory>

using namespace BitmapGraphics;

namespace
{
	const std::string msBmp{ "image/x-ms-bmp" };

	std::shared_ptr<CodecLibrary> theCodecLibrary{};

	void setUp()
	{
		theCodecLibrary.reset(new CodecLibrary);
		theCodecLibrary->registerEncoder(HBitmapEncoder(new WindowsBitmapEncoder));
		theCodecLibrary->registerDecoder(HBitmapDecoder(new WindowsBitmapDecoder));
	}

	void tearDown()
	{
		theCodecLibrary.reset();
	}

	class Finally
	{
	public:
		explicit Finally(std::function<void()>&& op)
			: m_cleanup(std::move(op))
		{
		}

		~Finally()
		{
			m_cleanup();
		}

		Finally(const Finally&) = delete;
		Finally& operator=(const Finally&) = delete;
		Finally(Finally&&) = delete;
		Finally& operator=(Finally&&) = delete;

	private:
		std::function<void()> m_cleanup;
	};
}

TEST(invalidDecoder, CodecLibrary)
{
	HBitmapDecoder decoder{ new WindowsBitmapDecoder };

	try
	{
		decoder->createIterator();
		CHECK(false);
	}
	catch (const std::exception& exc)
	{
		std::cout << exc.what() << std::endl;
		CHECK(true);
	}
}

TEST(invalidEncoder, CodecLibrary)
{
	HBitmapEncoder encoder{ new WindowsBitmapEncoder };

	try
	{
		std::ostringstream os{ std::ios::binary };
		encoder->encodeToStream(os);
		CHECK(false);
	}
	catch (const std::exception& exc)
	{
		std::cout << exc.what() << std::endl;
		CHECK(true);
	}
}

TEST(createEncoderViaMimeType, CodecLibrary)
{
	setUp();

	Bitmap nullBitmap{ 0, 0 };
	HBitmapIterator iterator{ nullBitmap.createIterator() };
	const HBitmapEncoder encoder{ theCodecLibrary->createEncoder(msBmp, iterator) };

	CHECK(dynamic_cast<WindowsBitmapEncoder*>(encoder.get()));

	tearDown();
}

TEST(failedCreateEncoderViaMimeType, CodecLibrary)
{
	setUp();

	Bitmap nullBitmap{ 0, 0 };
	HBitmapIterator iterator{ nullBitmap.createIterator() };

	try
	{
		HBitmapEncoder encoder{ theCodecLibrary->createEncoder("image/unsupported-type", iterator) };
		CHECK(false);
	}
	catch (const std::exception& exc)
	{
		std::cout << exc.what() << std::endl;
		CHECK(true);
	}

	tearDown();
}

TEST(createDecoderViaMimeType, CodecLibrary)
{
	setUp();

	std::stringstream ss;
	const HBitmapDecoder decoder{ theCodecLibrary->createDecoder(msBmp, ss) };

	CHECK(dynamic_cast<WindowsBitmapDecoder*>(decoder.get()));

	tearDown();
}

TEST(createFailedDecoderViaMimeType, CodecLibrary)
{
	setUp();

	std::stringstream ss;

	try
	{
		HBitmapDecoder decoder{ theCodecLibrary->createDecoder("image/unsupported-type", ss) };
		CHECK(false);
	}
	catch (const std::exception& exc)
	{
		std::cout << exc.what() << std::endl;
		CHECK(true);
	}

	tearDown();
}

TEST(createDecoderAutoDetermine, CodecLibrary)
{
	setUp();

	std::ifstream inFile{ "basic.bmp", std::ios::binary };
	CHECK_EQUAL(0, !inFile);
	HBitmapDecoder decoder{ theCodecLibrary->createDecoder(inFile) };

	CHECK(decoder.get());
	CHECK(dynamic_cast<WindowsBitmapDecoder*>(decoder.get()));

	tearDown();
}

TEST(windowsBitmapDecodeEncode, CodecLibrary)
{
	setUp();

	std::ifstream inFile{ "basic.bmp", std::ios::binary };
	CHECK_EQUAL(0, !inFile);

	HBitmapDecoder decoder{ theCodecLibrary->createDecoder(inFile) };
	HBitmapIterator iterator{ decoder->createIterator() };

	CHECK(iterator.get());
	CHECK_EQUAL(100, iterator->getBitmapHeight());
	CHECK_EQUAL(100, iterator->getBitmapWidth());

	HBitmapEncoder encoder{ theCodecLibrary->createEncoder(msBmp, iterator) };

	std::ofstream outFile{ "output_basicCopy.bmp", std::ios::binary };
	encoder->encodeToStream(outFile);
	// TODO: file compare input/output

	tearDown();
}

//TEST(brightnessDecoratorIterator, CodecLibrary)
//{
//	setUp();
//	Finally cleanup([] { tearDown(); });
//
//	std::ifstream inFile{ "basic.bmp", std::ios::binary };
//	CHECK_EQUAL(false, !inFile);
//
//	auto decoder{ theCodecLibrary->createDecoder(inFile) };
//	auto iterator{ decoder->createIterator() };
//
//	CHECK(iterator.get());
//	CHECK_EQUAL(100, iterator->getBitmapHeight());
//	CHECK_EQUAL(100, iterator->getBitmapWidth());
//
//	auto brightnessIterator = std::make_unique<BrightnessDecorator>(std::move(iterator), 80);
//
//	CHECK_EQUAL(80, brightnessIterator->getBrightnessAdjustment());
//
//	brightnessIterator->setBrightnessAdjustment(50);
//
//	CHECK_EQUAL(50, brightnessIterator->getBrightnessAdjustment());
//
//	auto encoder{ theCodecLibrary->createEncoder(msBmp, std::move(brightnessIterator)) };
//
//	std::ofstream outFile{ "output_basicBrightnessAdjusted.bmp", std::ios::binary };
//	encoder->encodeToStream(outFile);
//	outFile.close();
//
//	std::ifstream resultFile{ "output_basicBrightnessAdjusted.bmp", std::ios::binary };
//	auto resultDecoder{ theCodecLibrary->createDecoder(resultFile) };
//
//	// Read the 1st pixel from both.
//	inFile.seekg(0u, std::ios_base::beg);
//	auto verifySource = decoder->createIterator();
//	auto resultSource = resultDecoder->createIterator();
//
//	const auto sourceColor = verifySource->getColor();
//	const auto resultColor = resultSource->getColor();
//
//	CHECK_EQUAL(static_cast<uint8_t>(sourceColor.getRed()) + 50, static_cast<uint8_t>(resultColor.getRed()));
//	CHECK_EQUAL(static_cast<uint8_t>(sourceColor.getGreen()) + 50, static_cast<uint8_t>(resultColor.getGreen()));
//	CHECK_EQUAL(static_cast<uint8_t>(sourceColor.getBlue()) + 50, static_cast<uint8_t>(resultColor.getBlue()));
//}

//TEST(colorInvertDecoratorIterator, CodecLibrary)
//{
//    setUp();
//
//    std::ifstream inFile{"basic.bmp", std::ios::binary};
//    CHECK_EQUAL(0, !inFile);
//    
//    HBitmapDecoder decoder {theCodecLibrary->createDecoder(inFile)};
//    HBitmapIterator iterator {decoder->createIterator()};
//    
//    CHECK(iterator.get());
//    CHECK_EQUAL(100, iterator->getBitmapHeight());
//    CHECK_EQUAL(100, iterator->getBitmapWidth());
//
//    HBitmapIterator colorInvertIterator{new ColorInversionDecorator{iterator}};
//    HBitmapEncoder encoder {theCodecLibrary->createEncoder(msBmp, colorInvertIterator)};
//
//    std::ofstream outFile{"output_basicColorInvert.bmp", std::ios::binary};
//    encoder->encodeToStream(outFile);
//    // TODO: file compare input/output
//
//    tearDown();
//}
//
//TEST(doubleDecorator, CodecLibrary)
//{
//    setUp();
//
//    std::ifstream inFile{"basic.bmp", std::ios::binary};
//    CHECK_EQUAL(0, !inFile);
//    
//    HBitmapDecoder decoder {theCodecLibrary->createDecoder(inFile)};
//    HBitmapIterator iterator {decoder->createIterator()};
//    
//    CHECK(iterator.get());
//    CHECK_EQUAL(100, iterator->getBitmapHeight());
//    CHECK_EQUAL(100, iterator->getBitmapWidth());
//
//    HBitmapIterator colorInvertIterator{new ColorInversionDecorator{iterator}};
//    HBitmapIterator darkenColorInvertIterator{new BrightnessDecorator{colorInvertIterator, -50}};
//
//    HBitmapEncoder encoder {theCodecLibrary->createEncoder(msBmp, darkenColorInvertIterator)};
//        
//    std::ofstream outFile{"output_darkInverted.bmp", std::ios::binary};
//    encoder->encodeToStream(outFile);
//    // TODO: file compare input/output
//
//    tearDown();
//}
//
