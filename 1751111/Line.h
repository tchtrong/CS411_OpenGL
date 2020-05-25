#pragma once

#include "Point.h"

struct Line : public Drawing {

    Line() = default;

    Line(const Point& x, const Point& y);

    virtual void draw() const override;

    virtual Line& translate(const Matrix<1, 2>& direction) override;

    virtual Line& rotate(const Matrix<2, 2>& direction) override;
    virtual Line& rotate(const Matrix<2, 2>& direction, const Point& fixed_point) override;

    virtual Line& reflect(const Matrix<2, 2>& direction) override;
    virtual Line& reflect(const Matrix<2, 2>& direction, const Point& fixed_point) override;

    virtual Line& scale(const Matrix<2, 2>& direction) override;
    virtual Line& scale(const Matrix<2, 2>& direction, const Point& fixed_point) override;

    virtual Line& update(const Point& new_end) override;

    virtual TYPE type() const override;

    virtual Point center() const override;

    float length() const;

    Point start{};
    Point end{};

};

