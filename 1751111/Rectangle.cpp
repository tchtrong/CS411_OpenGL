#include "Rectangle.h"

RecTangle::RecTangle(Line first) :
	first(first),
	second(
		[&]()
		{
			first.reflect(REFLECTION::DEGREE(90), first.center());
			return first;
		}()
	) 
{}

RecTangle& RecTangle::rotate(const Matrix<2, 2>& direction)
{
	const auto c = center();
	first.rotate(direction, c);
	second.rotate(direction, c);
	return *this;
}

RecTangle& RecTangle::rotate(const Matrix<2, 2>& direction, const Point& fixed_point) {
	first.rotate(direction, fixed_point);
	second.rotate(direction, fixed_point);
	return *this;
}

RecTangle& RecTangle::translate(const Matrix<1, 2>& direction) {
	first.translate(direction);
	second.translate(direction);
	return *this;
}

RecTangle& RecTangle::scale(const Matrix<2, 2>& direction)
{
	const auto c = center();
	first.scale(direction, c);
	second.scale(direction, c);
	return *this;
}

RecTangle& RecTangle::scale(const Matrix<2, 2>& direction, const Point& fixed_point) {
	first.scale(direction, fixed_point);
	second.scale(direction, fixed_point);
	return *this;
}

RecTangle& RecTangle::reflect(const Matrix<2, 2>& direction)
{
	const auto c = center();
	first.reflect(direction, c);
	second.reflect(direction, c);
	return *this;
}

RecTangle& RecTangle::reflect(const Matrix<2, 2>& direction, const Point & fixed_point)
{
	first.reflect(direction, fixed_point);
	second.reflect(direction, fixed_point);
	return *this;
}

RecTangle& RecTangle::update(const Point& new_end) {
	first.update(new_end);
	second = reflect_v(first, REFLECTION::DEGREE(90), first.center());
	return *this;
}

TYPE RecTangle::type() const {
	return TYPE::RECTANGLE;
}

inline Point RecTangle::center() const {
	return first.center();
}

void RecTangle::draw() const {
	glBegin(GL_LINE_LOOP);
	first.start.draw();
	second.start.draw();
	first.end.draw();
	second.end.draw();
	glEnd();
}