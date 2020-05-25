#pragma once

#include "Line.h"

struct RecTangle : public Drawing {

	RecTangle() = default;

	RecTangle(Line first);

	virtual void draw() const override;

	virtual RecTangle& translate(const Matrix<1, 2>& direction) override;

	virtual RecTangle& rotate(const Matrix<2, 2>& direction) override;
	virtual RecTangle& rotate(const Matrix<2, 2>& direction, const Point & fixed_point) override;

	virtual RecTangle& scale(const Matrix<2, 2>& direction) override;
	virtual RecTangle& scale(const Matrix<2, 2>& direction, const Point & fixed_point) override;

	virtual RecTangle& reflect(const Matrix<2, 2>& direction) override;
	virtual RecTangle& reflect(const Matrix<2, 2>& direction, const Point & fixed_point) override;

	virtual RecTangle& update(const Point& new_end) override;

	virtual TYPE type() const override;

	virtual Point center() const override;

	Line first{};
	Line second{};
};