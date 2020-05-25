#pragma once

#include "Dependencies\glew\glew.h"
#include "Dependencies\freeglut\freeglut.h"
#include "Matrix.h"

constexpr GLfloat GL_PI = 3.14159265358979323846f;

struct TRANSLATE {
    constexpr static inline Matrix<1, 2> UP(float speed = 1.0f) { return { 0, -speed }; }
    constexpr static inline Matrix<1, 2> DOWN(float speed = 1.0f) { return { 0,  speed }; }
    constexpr static inline Matrix<1, 2> LEFT(float speed = 1.0f) { return { -speed,      0 }; }
    constexpr static inline Matrix<1, 2> RIGHT(float speed = 1.0f) { return { speed,      0 }; }
};

struct ROTATE {
private:
    constexpr static inline GLfloat plus_1 = GL_PI / 180;
    constexpr static inline GLfloat minus_1 = -GL_PI / 180;

public:
    static inline Matrix<2, 2> CLOCKWISE(float degree = plus_1) {
        return{ {{ std::cos(degree), std::sin(degree)}, {-std::sin(degree), std::cos(degree)}}
        };
    }
    static inline Matrix<2, 2> COUNTER_CLOCKWISE(float degree = minus_1) {
        return{ {{ std::cos(degree), std::sin(degree)}, {-std::sin(degree), std::cos(degree)}}
        };
    }
};

struct REFLECTION {
private:
    constexpr static inline GLfloat plus_1 = -GL_PI / 180;

public:
    static inline Matrix<2, 2> DEGREE(float degree = 0.0f) {
        degree *= (2 * plus_1);
        return{ {{ std::cos(degree), std::sin(degree)}, {std::sin(degree), -std::cos(degree)}}
        };
    }
};

struct SCALE {
    constexpr static inline Matrix<2, 2> ENLARGE = { {{1.05f, 0.0f},{0.0f, 1.05f}} };

    constexpr static inline Matrix<2, 2> REDUCE = { {{0.95f, 0.0f},{0.0f, 0.95f}} };
};