#pragma once

#include "BitmapIterator.h"
#include "IBitmapIterator.h"

namespace BitmapGraphics
{
	class BrightnessDecorator : public IBitmapIterator
	{
	public:
		BrightnessDecorator(HBitmapIterator& originalIterator) : brightnessAdjustment(0), bitmapIterator(std::move(originalIterator))
		{
		}

		void setBrightnessAdjustment(int brightnessAdjustment)
		{
			this->brightnessAdjustment = brightnessAdjustment;
		}

		[[nodiscard]] int getBrightnessAdjustment() const
		{
			return this->brightnessAdjustment;
		}

		void nextScanLine() override
		{
			bitmapIterator->nextScanLine();
		}

		[[nodiscard]] bool isEndOfImage() const override
		{
			return bitmapIterator->isEndOfImage();
		}

		void nextPixel() override
		{
			bitmapIterator->nextPixel();
		}

		[[nodiscard]] bool isEndOfScanLine() const override
		{
			return bitmapIterator->isEndOfScanLine();
		}

		[[nodiscard]] Color getColor() const override
		{
			Color adjustedColor = bitmapIterator->getColor();
			
			adjustedColor.setRed(adjustColorComponent(adjustedColor.getRed()));
			adjustedColor.setRed(adjustColorComponent(adjustedColor.getGreen()));
			adjustedColor.setRed(adjustColorComponent(adjustedColor.getBlue()));

			return adjustedColor;
		}

	private:
		int brightnessAdjustment;
		HBitmapIterator bitmapIterator;

		static int adjustColorComponent(int colorComponent)
		{
			int adjustedColorComponent = colorComponent + brightnessAdjustment;
			if (adjustedColorComponent > 255)
			{
				adjustedColorComponent = 255;
			}
			else if (adjustedColorComponent < 0)
			{
				adjustedColorComponent = 0;
			}
		}
	};
}
