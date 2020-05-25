#pragma once

#include "Rectangle.h"

struct Square : public RecTangle {

	Square(const Line& line);

	virtual Square& translate(const Matrix<1, 2>& direction) override {
		RecTangle::translate(direction);
		return *this;
	}

	virtual Square& rotate(const Matrix<2, 2>& direction) override {
		RecTangle::rotate(direction);
		return *this;
	}
	virtual Square& rotate(const Matrix<2, 2>& direction, const Point& fixed_point) override {
		RecTangle::rotate(direction, fixed_point);
		return *this;
	}

	virtual Square& scale(const Matrix<2, 2>& direction) override {
		RecTangle::scale(direction);
		return *this;
	}
	virtual Square& scale(const Matrix<2, 2>& direction, const Point& fixed_point) override {
		RecTangle::scale(direction, fixed_point);
		return *this;
	}

	virtual Square& reflect(const Matrix<2, 2>& direction) override {
		RecTangle::reflect(direction);
		return *this;
	}
	virtual Square& reflect(const Matrix<2, 2>& direction, const Point& fixed_point) override {
		RecTangle::reflect(direction, fixed_point);
		return *this;
	}

	virtual Square& update(const Point& new_end) override;
};