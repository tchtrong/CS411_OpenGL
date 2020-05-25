#include "Elipse.h"

void Elipse::draw() const {

	glBegin(GL_LINE_LOOP);

	Point tmp{};

	const auto half_major_ = half_major();
	const auto half_minor_ = half_minor();
	const auto center_     = center();

	auto get_point = [&](float degree) {
		return Point{ {half_major_ * std::cos(degree),half_minor_ * std::sin(degree)} };
	};

	for (int count = 0; count < lines; ++count) {
		get_point(incr * count).rotate(rotate_para).translate(center_).draw();
	}

	glEnd();
}

//(Point{ {tmp.x() + half_major_,tmp.y() } } + center_).draw();
//(Point{ {tmp.x() - half_major_,tmp.y() } } + center_).draw();
//(Point{ {tmp.x(),tmp.y() - half_minor_ } } + center_).draw();
//(Point{ {tmp.x(),tmp.y() + half_minor_ } } + center_).draw();
//
//GLfloat his = half_minor_ * half_minor_; //b^2
//GLfloat has = half_major_ * half_major_; //a^2
//
//GLfloat p = his - has * half_minor_ + has / 4;
//
//for (++tmp.x(), tmp.y() += half_minor_; his * tmp.x() < has * tmp.y(); ++tmp.x()) {
//	if (p < 0) {
//		p = p + his * (2 * tmp.x() + 1);
//	}
//	else {
//		tmp.y() -= 1;
//		p = p + his * (2 * tmp.x() + 1) - 2 * has * (tmp.y() - 1);
//	}
//	(tmp + center_).draw();
//	(Point{ { -tmp.x(),  tmp.y()} } + center_).draw();
//	(Point{ { -tmp.x(), -tmp.y()} } + center_).draw();
//	(Point{ {  tmp.x(), -tmp.y()} } + center_).draw();
//}
//p = (his) * (tmp.x() + 0.5f) * (tmp.x() - 0.5f) + (has) * (tmp.y()) * (tmp.y()) - (has)*his;
//while (tmp.y() >= 0)
//{
//	if (p >= 0) {
//		p = p - has * (2 * tmp.y() - 1);
//	}
//	else
//	{
//		p = p - has * (2 * tmp.y() - 1) + 2 * his * (tmp.x() + 1);
//		++tmp.x();
//	}
//	--tmp.y();
//	(tmp + center_).draw();
//	(Point{ { -tmp.x(),  tmp.y()} } + center_).draw();
//	(Point{ { -tmp.x(), -tmp.y()} } + center_).draw();
//	(Point{ {  tmp.x(), -tmp.y()} } + center_).draw();
//}