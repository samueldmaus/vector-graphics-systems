#pragma once

#include "IBitmapIterator.h"
#include <CodecLibrary.h>

namespace BitmapGraphics
{
    class BitmapIteratorDecorator : public IBitmapIterator
    {
    public:
        explicit BitmapIteratorDecorator(HBitmapIterator originalIterator);

        void nextScanLine() override;
        [[nodiscard]] bool isEndOfImage() const override;
        void nextPixel() override;
        [[nodiscard]] bool isEndOfScanLine() const override;

        [[nodiscard]] int getBitmapWidth() const override;
        [[nodiscard]] int getBitmapHeight() const override;

    protected:
        HBitmapIterator myOriginalIterator;
    };
}