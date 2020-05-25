#pragma once

#include "Point.h"

struct Star : public Shape {
	Star(const Point& start = Point{}, Point end = Point{}) :start(start), end(end) {}

	void Draw() override {

		const GLint dx = end.x - start.x;
		const GLint dy = end.y - start.y;

		GLint radius;
		GLint mRadius;

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
				mRadius = dyToCenter * std::cos(2 * GL_PI / 5) / std::cos(GL_PI / 5);

				return Point { dx < 0 ? start.x - dxToCenter : start.x + dxToCenter ,
							   dy < 0 ? start.y - dyToCenter : start.y + dyToCenter };
			}()
		};

		float angleIncrement = 2 * GL_PI / 10;
		glBegin(GL_LINE_LOOP);
		float angle = -GL_PI / 2;
		GLint tmp_radius = radius;
		for (int k = 0; k < 10; ++k) {
			glVertex2i(tmp_radius * cos(angle) + center.x, tmp_radius * sin(angle) + center.y);
			angle += angleIncrement;
			if (tmp_radius == radius) {
				tmp_radius = mRadius;
			}
			else {
				tmp_radius = radius;
			}
		}
		glEnd();
	}

	Point start;
	Point end;
};