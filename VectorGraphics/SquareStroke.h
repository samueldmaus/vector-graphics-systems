#pragma once

#include "IStroke.h"

namespace BitmapGraphics
{
	class SquareStroke : public IStroke
	{
	public:
		SquareStroke(int s, const Color& c);

		SquareStroke(const SquareStroke& other) = default;
		SquareStroke(SquareStroke&& other) = default;
		~SquareStroke() override = default;

		SquareStroke& operator=(const SquareStroke&) = default;
		SquareStroke& operator=(SquareStroke&&) = default;

		void setSize(int size) override;
		[[nodiscard]] int getSize() const override;
		void setColor(Color const& color) override;
		[[nodiscard]] Color getColor() const override;
		HPen createPen(HCanvas const& canvas) override;

	private:
		Color strokeColor;
		int strokeSize;
	};
}