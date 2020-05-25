#pragma once

#include "Point.h"

struct TamGiacDeu : public Shape {

	TamGiacDeu(const Point& start = Point{}, Point end = Point{}) :start(start), end(end) {}

	void Draw() override {
		Point A;
		Point B;
		Point C;
		const GLint height = abs(end.y - start.y);
		if (end.x > start.x) {
			if (end.y > start.y) {
				A = Point{ start.x,end.y };
				C = Point{ int(A.x + 2 * double(height) / sqrt(3)),A.y };
				B = Point{ abs(C.x - A.x) / 2 + A.x,start.y };
			}
			else {
				A = Point{ start.x,start.y };
				C = Point{ int(start.x + 2 * double(height) / sqrt(3)),A.y };
				B = Point{ abs(C.x - A.x) / 2 + A.x,end.y };
			}
		}
		else {
			if (end.y > start.y) {
				A = Point{ start.x,end.y };
				C = Point{ int(start.x - 2 * double(height) / sqrt(3)),A.y };
				B = Point{ A.x - abs(C.x - A.x) / 2,start.y };
			}
			else {
				A = Point{ start.x,start.y };
				C = Point{ int(start.x - 2 * double(height) / sqrt(3)),A.y };
				B = Point{ A.x - abs(C.x - A.x) / 2,end.y };
			}
		}

		glBegin(GL_LINES);

		glVertex2i(A.x, A.y);
		glVertex2i(B.x, B.y);

		glVertex2i(A.x, A.y);
		glVertex2i(C.x, C.y);

		glVertex2i(B.x, B.y);
		glVertex2i(C.x, C.y);

		glEnd();
	}

	Point start;
	Point end;
};