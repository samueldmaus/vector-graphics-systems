#include "TestHarness.h"
#include "VerifyEquality.h"
#include "Word.h"
#include <iostream>

TEST(verifyEquality, Word)
{
    const unsigned char input[]{ 0xAB, 0xCD, 0 };
    std::stringstream ss{reinterpret_cast<const char*>(input)};

    Binary::Word actual{ Binary::Word::readLittleEndian(ss) };
    const Binary::Word notReallyExpected{0xABCD};

	std::stringstream errorStream;

    try
    {
        verifyEquality(notReallyExpected, actual, "notReallyExpected");
        CHECK(false);
    }
    catch (const std::exception& e)
    {
        errorStream << e.what();
    	CHECK_EQUAL("notReallyExpected", errorStream.str());
        CHECK(true);
    }
}
