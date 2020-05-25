#pragma once

#include "Rectangle.h"

struct Elipse : public RecTangle {

	using RecTangle::RecTangle;

	void draw() const override;

	virtual Elipse& translate(const Matrix<1, 2>& direction) override {
		RecTangle::translate(direction);
		return *this;
	}

	virtual Elipse& rotate(const Matrix<2, 2>& direction) override {
		RecTangle::rotate(direction);
		rotate_para *= direction;
		return *this;
	}
	virtual Elipse& rotate(const Matrix<2, 2>& direction, const Point& fixed_point) override {
		RecTangle::rotate(direction, fixed_point);
		rotate_para *= direction;
		return *this;
	}

	virtual Elipse& scale(const Matrix<2, 2>& direction) override {
		RecTangle::scale(direction);
		return *this;
	}
	virtual Elipse& scale(const Matrix<2, 2>& direction, const Point& fixed_point) override {
		RecTangle::scale(direction, fixed_point);
		return *this;
	}

	virtual Elipse& reflect(const Matrix<2, 2>& direction) override {
		RecTangle::reflect(direction);
		return *this;
	}
	virtual Elipse& reflect(const Matrix<2, 2>& direction, const Point& fixed_point) override {
		RecTangle::reflect(direction, fixed_point);
		return *this;
	}

	GLfloat half_major() const {
		return first.start.distance_to(second.start) / 2;
	}

	GLfloat half_minor() const {
		return first.start.distance_to(second.end) / 2;
	}

private:
	Matrix<2, 2> rotate_para = { {{1,0},{0,1}} };
	constexpr static int lines = 50;	
	constexpr static float incr = 2 * GL_PI / lines;
};