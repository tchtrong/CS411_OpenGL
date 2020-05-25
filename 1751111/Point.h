#pragma once

#include "Shape.h"

class Point : public Shape {
public:

    Point() noexcept = default;

    Point(const Matrix<1, 2>& a) noexcept : matrix(a) {}

    void draw() const {
        glVertex2f(x(), y());
    }

    Point& translate(const Matrix<1, 2>& direction) {
        return *this += direction;
    }

    Point& rotate(const Matrix<2, 2>& direction) override {
        return *this *= direction;
    }
    Point& rotate(const Matrix<2, 2>& direction, const Point& fixed_point) override {
        return *this = fixed_point + (*this - fixed_point) * direction;
    }

    Point& reflect(const Matrix<2, 2>& direction) override {
        return *this *= direction;
    }
    Point& reflect(const Matrix<2, 2>& direction, const Point& fixed_point) override {
        return *this = fixed_point + (*this - fixed_point) * direction;
    }

    Point& scale(const Matrix<2, 2>& direction) override {
        return *this *= direction;
    }
    Point& scale(const Matrix<2, 2>& direction, const Point& fixed_point) override {
        const auto tmp = fixed_point * (IDENTITY_2x2 - direction);
        return *this = *this * direction + tmp;
    }

    virtual Point& update(const Point& new_end) override {
        *this = new_end;
        return *this;
    }

    float distance_to(const Point& rhs) const {
        const auto& [x, y] = matrix[0];
        const auto& [r_x, r_y] = rhs.matrix[0];
        return std::sqrt((x - r_x) * (x - r_x) + (y - r_y) * (y - r_y));
    }

    operator Matrix<1, 2>() const {
        return matrix;
    }

    Point& move_x_axis(float x) {
        matrix += {x, 0};
        return *this;
    }
    Point& move_y_axis(float y) {
        matrix += { 0, y };
        return *this;
    }

    bool is_to_left(const Point& rhs) const {
        return this->x() < rhs.x();
    }
    bool is_to_right(const Point& rhs) const {
        return this->x() > rhs.x();
    }
    bool is_same_x(const Point& rhs) const {
        return this->x() == rhs.x();
    }

    bool is_higher(const Point& rhs) const {
        return this->y() > rhs.y();
    }
    bool is_lower(const Point& rhs) const {
        return this->y() < rhs.y();
    }
    bool is_same_y(const Point& rhs) const {
        return this->y() == rhs.y();
    }

    Point get_point_symmetry(const Point& mid) {
        return mid * 2 - *this;
    }

    Point operator+(const Point& rhs) const {
        return Point{ matrix + rhs.matrix };
    }
    Point operator-(const Point& rhs) const {
        return Point{ matrix - rhs.matrix };
    }
    Point& operator+=(const Point& rhs) {
        matrix += rhs.matrix;
        return *this;
    }
    Point& operator-=(const Point& rhs) {
        matrix -= rhs.matrix;
        return *this;
    }
    Point& operator*=(const Matrix<2, 2>& rhs) {
        matrix *= rhs;
        return *this;
    }
    Point operator*(float a) const {
        return matrix * a;
    }
    Point operator*=(float a) {
        return *this = *this * a;
    }
    Point operator/(float a) const {
        return matrix / a;
    }
    Point operator/=(float a) {
        return *this = *this / a;
    }

    template<int N>
    Point operator*(const Matrix<2, N>& rhs) const {
        return Point{ matrix * rhs };
    }

    friend std::ostream& operator << (std::ostream& os, const Point& p) {
        os << "Point: " << p.x() << ' ' << p.y() << '\n';
        return os;
    }

    virtual TYPE type() const {
        return TYPE::POINT;
    }

    float x() const {
        return matrix[0][0];
    }
    float y() const {
        return matrix[0][1];
    }
    float& x() {
        return matrix[0][0];
    }
    float& y() {
        return matrix[0][1];
    }

private:
    Matrix<1, 2> matrix{};
};