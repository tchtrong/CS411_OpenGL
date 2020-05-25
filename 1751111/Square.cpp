#include "Square.h"

Square::Square(const Line& line) : RecTangle(line) {
	update(first.end);
}

Square& Square::update(const Point& new_end) {
	RecTangle::update(new_end);
	auto dx = first.start.distance_to(second.start);
	auto dy = first.start.distance_to(second.end);
	if (dx < dy) {
		if (first.start.is_higher(second.end)) {
			second.end += { {0, dy - dx} };
			first.end += { {0, dy - dx} };
		}
		else {
			second.end -= { {0, dy - dx} };
			first.end -= { {0, dy - dx} };
		}
	}
	else {
		if (first.start.is_to_left(second.start)) {
			second.start -= { {dx - dy, 0} };
			first.end -= { {dx - dy, 0} };
		}
		else {
			second.start += { {dx - dy, 0} };
			first.end += { {dx - dy, 0} };
		}
	}
	return *this;
}
