#pragma once

#include "Point.h"

struct TamGiacVC : public Shape {

	TamGiacVC(const Point& start = Point{}, Point end = Point{}) :start(start), end(end) {}

	void Draw() override {
		Point tmp;
		tmp.x = end.x;
		tmp.y = start.y;
		if (end.y > start.y) {
			end.y = tmp.y + abs(tmp.x - start.x);
		}
		else {
			end.y = tmp.y - abs(tmp.x - start.x);
		}

		glBegin(GL_LINES);

		glVertex2i(start.x, start.y);
		glVertex2i(end.x, end.y);

		glVertex2i(start.x, start.y);
		glVertex2i(tmp.x, tmp.y);

		glVertex2i(tmp.x, tmp.y);
		glVertex2i(end.x, end.y);

		glEnd();
	}

	Point start;
	Point end;
};