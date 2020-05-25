//#pragma once
//
//#include "Point.h"
//
//struct LucGiacDeu : public Shape {
//
//	LucGiacDeu(const Point& start = Point{}, Point end = Point{}) :start(start), end(end) {}
//
//	void Draw() override {
//
//		const GLint min_ = abs(end.x - start.x) < abs(end.y - start.y) ? abs(end.x - start.x) : abs(end.y - start.y);
//
//		const GLint radius = min_ / 2;
//
//		const Point center{
//			end.x > start.x ? start.x + radius : start.x - radius ,
//			end.y > start.y ? start.y + radius : start.y - radius
//		};
//
//		float angleIncrement = 2 * GL_PI / 6;
//		glBegin(GL_LINE_LOOP);
//		float angle = -GL_PI / 3;
//		for (int k = 0; k < 6; ++k) {
//			glVertex2i(radius * cos(angle) + center.x, radius * sin(angle) + center.y);
//			angle += angleIncrement;
//		}
//		glEnd();
//	}
//
//	Point start;
//	Point end;
//};