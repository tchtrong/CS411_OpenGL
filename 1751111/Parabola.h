#pragma once

#include"Point.h"

struct Parabola :public Shape
{
	Parabola() = default;
	Parabola(Point x, GLint y, DrawAlgo a = DrawAlgo::Midpoint) : center(x), l_focus(y), Shape(a) {

	}
	void Draw() override;

	Point center{};
	GLint l_focus{}; //Focus length
};
