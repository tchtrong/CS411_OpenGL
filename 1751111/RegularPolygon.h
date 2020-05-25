#pragma once

#include "Rectangle.h"

template<int N>
struct RegularPolygon : public Drawing {

    RegularPolygon(Line line) : line(line) {}

    virtual void draw() const {
        glBegin(GL_LINE_LOOP);
        Point tmp{ first };
        for (int count = 0; count < N; ++count) {
            tmp.rotate(ROTATE::CLOCKWISE(incr_angle), center_).draw();
        }
        glEnd();
    }

    virtual RegularPolygon& translate(const Matrix<1, 2>& direction) {
        first.translate(direction);
        center_.translate(direction);
        return *this;
    }

    virtual RegularPolygon& rotate(const Matrix<2, 2>& direction) {
        first.rotate(direction, center_);
        return *this;
    }
    virtual RegularPolygon& rotate(const Matrix<2, 2>& direction, const Point& fixed_point) {
        first.rotate(direction, fixed_point);
        center_.rotate(direction, fixed_point);
        return *this;
    }

    virtual RegularPolygon& scale(const Matrix<2, 2>& direction) {
        first.scale(direction, center_);
        radius_ = first.distance_to(center_);
        return *this;
    }
    virtual RegularPolygon& scale(const Matrix<2, 2>& direction, const Point& fixed_point) {
        first.scale(direction, fixed_point);
        center_.scale(direction, fixed_point);
        radius_ = first.distance_to(center_);
        return *this;
    }

    virtual RegularPolygon& reflect(const Matrix<2, 2>& direction) {
        first.reflect(direction);
        center_.reflect(direction);
        return *this;
    }
    virtual RegularPolygon& reflect(const Matrix<2, 2>& direction, const Point& fixed_point) {
        first.reflect(direction, fixed_point);
        center_.reflect(direction, fixed_point);
        return *this;
    }

    virtual RegularPolygon& update(const Point& new_end) {
        line.update(new_end);
        re_evaluate();
        return *this;
    }

    float radius() const {
        return radius_;
    }

    virtual Point center() const {
        return center_;
    }

    virtual TYPE type() const override {
        return TYPE::REGULAR_POLYGON;
    }

private:
    constexpr static float incr_angle = 2 * GL_PI / N;
    const static inline auto width_height = [&]()->std::array<float, 2> {
        if (!(N % 2)) {
            return { 2 * std::cos(incr_angle / 2), 2 };
        }
        else {
            Point tmp{ { 0,1 } };
            if (N % 4 == 1) {
                tmp.rotate(ROTATE::COUNTER_CLOCKWISE((N / 4)     * incr_angle));
            }
            else if (N % 4 == 3) {
                tmp.rotate(ROTATE::COUNTER_CLOCKWISE((N / 4 + 1) * incr_angle));
            }
            return { std::abs(2 * tmp.x()), std::abs(1 + std::cos(incr_angle / 2)) };
        }
    }();

    void re_evaluate() {
        const float dx = line.start.x() - line.end.x();
        const float dy = line.start.y() - line.end.y();
        const auto& [width, height] = width_height;

        const auto dx_over_width = dx / width;
        const auto co_x = dx_over_width < 0 ? -1 : 1;

        const auto dy_over_height = dy / height;
        const auto co_y = dy_over_height < 0 ? -1 : 1;

        if (dx_over_width * co_x < dy_over_height * co_y) {
            radius_ = dx_over_width * co_x;
        }
        else {
            radius_ = dy_over_height * co_y;
        }

        line.end.x() = line.start.x() - width  * int(radius_) * co_x;
        line.end.y() = line.start.y() - height * int(radius_) * co_y;

        first = Point{
            {
                line.center().x(),
                line.end.y() < line.start.y() ? line.end.y() : line.start.y()
            } 
        };

        center_ = Point{
            {
                first.x(),
                first.y() + radius_
            } 
        };
    }

    Point first{};
    Point center_{};
    float radius_{};
    Line line{};
};

using RegularTriangle   = RegularPolygon<3>;
using RegularPentagon   = RegularPolygon<5>;
using RegularHexagon    = RegularPolygon<6>;
using RegularHeptagon   = RegularPolygon<7>;
using RegularOctagon    = RegularPolygon<8>;
using RegularNonagon    = RegularPolygon<9>;
using RegularDecagon    = RegularPolygon<10>;
using RegularHendecagon = RegularPolygon<11>;
using Regular_12        = RegularPolygon<12>;