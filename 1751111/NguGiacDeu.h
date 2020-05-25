#pragma once

#include "Rectangle.h"

struct NguGiacDeu : public RecTangle {
	NguGiacDeu(const Point& start = Point{}, Point end = Point{}) :start(start), end(end) {}

	void draw() const override {

		const GLint dx = end.x() - start.x();
		const GLint dy = end.y() - start.y();

		GLint radius;

		const Point center{
			[&]() {
				GLint dyToCenter;
				GLint dxToCenter;
				if (abs(dy) < abs(dx)) {
					dyToCenter = abs(dy) / (1 + std::cos(GL_PI / 5));
					dxToCenter = dyToCenter * std::cos(GL_PI / 10);
				}
				else {
					dxToCenter = abs(dx) / 2;
					dyToCenter = dxToCenter / std::cos(GL_PI / 10);
				}
				radius = dyToCenter;
				return Point{ { dx < 0 ? start.x() - dxToCenter : start.x() + dxToCenter ,
							   dy < 0 ? start.y() - dyToCenter : start.y() + dyToCenter } };
			}()
		};

		float angleIncrement = 2 * GL_PI / 5;
		glBegin(GL_LINE_LOOP);
		float angle = -GL_PI / 2;
			for (int k = 0; k < 5; ++k) {
				glVertex2i(radius * cos(angle) + center.x(), radius * sin(angle) + center.y());
				angle += angleIncrement;
			}
		glEnd();
	}

	Point start;
	Point end;
};