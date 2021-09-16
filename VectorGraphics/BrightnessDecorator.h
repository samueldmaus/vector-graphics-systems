#pragma once

#include "BitmapIteratorDecorator.h"
#include "Byte.h"

namespace BitmapGraphics
{
    class BrightnessDecorator final : public BitmapIteratorDecorator
    {
    public:
        BrightnessDecorator(
            HBitmapIterator originalIterator,
            const int& brightnessAdjustment);

        void setBrightnessAdjustment(int brightnessAdjustment);
        [[nodiscard]]int getBrightnessAdjustment() const;

        [[nodiscard]] Color getColor() const override;

    private:
        int myBrightnessAdjustment;
    };
}