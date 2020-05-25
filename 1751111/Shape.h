#pragma once

#include "Transformation.h"
#include "Matrix.h"
#include <array>
#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <cmath>

enum class TYPE {
    POINT,
    LINE,
    TRIANGLE,
    SQUARE,
    CIRCLE,
    RECTANGLE,
    REGULAR_POLYGON,
};

enum class BOX {
    RECT,
    SQUARE,
};

class Point;

struct Shape
{
    virtual void draw() const = 0;

    virtual Shape& translate(const Matrix<1, 2>& direction) = 0;

    virtual Shape& rotate(const Matrix<2, 2>& direction) = 0;
    virtual Shape& rotate(const Matrix<2, 2>& direction, const Point& fixed_point) = 0;

    virtual Shape& scale(const Matrix<2, 2>& direction) = 0;
    virtual Shape& scale(const Matrix<2, 2>& direction, const Point& fixed_point) = 0;

    virtual Shape& reflect(const Matrix<2, 2>& direction) = 0;
    virtual Shape& reflect(const Matrix<2, 2>& direction, const Point& fixed_point) = 0;

    virtual Shape& update(const Point& new_end) = 0;

    virtual TYPE type() const = 0;
};

template<typename SHAPE>
SHAPE translate_v(SHAPE s, const Matrix<1, 2>& direction) {    
    return s.translate(direction);
}

template<typename SHAPE>
SHAPE rotate_v(SHAPE s, const Matrix<2, 2>& direction) {
    return s.rotate(direction);
}

template<typename SHAPE>
SHAPE rotate_v(SHAPE s, const Matrix<2, 2>& direction, const Point& fixed_point) {
    return s.rotate(direction, fixed_point);
}

template<typename SHAPE>
SHAPE scale_v(SHAPE s, const Matrix<2, 2>& direction) {
    return s.scale(direction);
}

template<typename SHAPE>
SHAPE scale_v(SHAPE s, const Matrix<2, 2>& direction, const Point& fixed_point) {
    return s.scale(direction, fixed_point);
}

template<typename SHAPE>
SHAPE reflect_v(SHAPE s, const Matrix<2, 2>& direction) {
    return s.reflect(direction);
}

template<typename SHAPE>
SHAPE reflect_v(SHAPE s, const Matrix<2, 2>& direction, const Point& fixed_point) {
    return s.reflect(direction, fixed_point);
}

struct Drawing : public Shape {

    virtual Point center() const = 0;

};


struct Clicking : public Shape {
    
};