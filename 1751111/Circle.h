#pragma once

#include "Square.h"

struct Circle : public Square {

	using Square::Square;

	void draw() const override {

		glBegin(GL_LINE_LOOP);

		const auto center_ = center();

		Point tmp{ {0, radius()} };
		tmp.translate(center_);

		
		const float incr = 2 * GL_PI / lines;
		for (int count = 0; count < lines; ++count) {
			tmp.rotate(ROTATE::CLOCKWISE(incr), center_).draw();
		}

		glEnd();
	}

	virtual Circle& translate(const Matrix<1, 2>& direction) override {
		Square::translate(direction);
		return *this;
	}

	virtual Circle& rotate(const Matrix<2, 2>& direction) override {
		Square::rotate(direction);
		return *this;
	}
	virtual Circle& rotate(const Matrix<2, 2>& direction, const Point& fixed_point) override {
		Square::rotate(direction, fixed_point);
		return *this;
	}

	virtual Circle& scale(const Matrix<2, 2>& direction) override {
		Square::scale(direction);
		return *this;
	}
	virtual Circle& scale(const Matrix<2, 2>& direction, const Point& fixed_point) override {
		Square::scale(direction, fixed_point);
		return *this;
	}

	virtual Circle& reflect(const Matrix<2, 2>& direction) override {
		Square::reflect(direction);
		return *this;
	}
	virtual Circle& reflect(const Matrix<2, 2>& direction, const Point& fixed_point) override {
		Square::reflect(direction, fixed_point);
		return *this;
	}

	GLfloat radius() const {
		return first.start.distance_to(second.start) / 2;
	}

private:
	constexpr static int lines = 50;
	constexpr static float incr = 2 * GL_PI / lines;
};

/*(tmp + center() + Point{{  radius_,       0 }}).draw();
		(tmp + center() + Point{{ -radius_,       0 }}).draw();
		(tmp + center() + Point{{        0,  radius_}}).draw();
		(tmp + center() + Point{{        0, -radius_}}).draw();
		GLfloat p = 1 - radius_;
		const GLint condition = GLint(radius_ / std::sqrt(2));
		for (++tmp.x(), tmp.y() += radius_; tmp.x() <= condition; ++tmp.x()) {
			if (p < 0) {
				p = p + 2 * (tmp.x() + 1) + 1;
			}
			else {
				tmp.y() -= 1;
				p = p + 2 * (tmp.x() + 1) + 1 - 2 * (tmp.y() - 1);
			}
			(tmp + center_).draw();
			(Point{{ -tmp.x(),  tmp.y() }} + center_).draw();
			(Point{{  tmp.x(), -tmp.y() }} + center_).draw();
			(Point{{ -tmp.x(), -tmp.y() }} + center_).draw();
			(Point{{  tmp.y(),  tmp.x() }} + center_).draw();
			(Point{{ -tmp.y(),  tmp.x() }} + center_).draw();
			(Point{{  tmp.y(), -tmp.x() }} + center_).draw();
			(Point{{ -tmp.y(), -tmp.x() }} + center_).draw();
		}*/