#include "Line.h"

Line::Line(const Point& x, const Point& y) : start(x), end(y) {}

void Line::draw() const {
    glBegin(GL_LINES);
        start.draw();
        end.draw();
    glEnd();
}

Line& Line::translate(const Matrix<1, 2>& direction)
{
    start.translate(direction);
    end.translate(direction);
    return *this;
}

Line& Line::rotate(const Matrix<2, 2>& direction)
{
    const auto c = center();
    start.rotate(direction, c);
    end.rotate(direction, c);
    return *this;
}

Line& Line::rotate(const Matrix<2, 2>& direction, const Point& fixed_point)
{
    start.rotate(direction, fixed_point);
    end.rotate(direction, fixed_point);
    return *this;
}

Line& Line::reflect(const Matrix<2, 2>& direction)
{
    const auto c = center();
    start.reflect(direction, c);
    end.reflect(direction, c);
    return *this;
}

Line& Line::reflect(const Matrix<2, 2>& direction, const Point& fixed_point)
{
    start.reflect(direction, fixed_point);
    end.reflect(direction, fixed_point);
    return *this;
}

Line& Line::scale(const Matrix<2, 2>& direction)
{
    const auto c = center();
    start.scale(direction, c);
    end.scale(direction, c);
    return *this;
}

Line& Line::scale(const Matrix<2, 2>& direction, const Point& fixed_point)
{
    start.scale(direction, fixed_point);
    end.scale(direction, fixed_point);
    return *this;
}

Line& Line::update(const Point& new_end)
{
    end = new_end;
    return *this;
}

TYPE Line::type() const {
    return TYPE::LINE;
}

Point Line::center() const {
    return (start + end) / 2;
}

inline float Line::length() const {
    start.distance_to(end);
}