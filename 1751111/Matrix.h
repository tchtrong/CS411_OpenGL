#pragma once

#include <array>
#include <cmath>

template<size_t M, size_t N>
using Matrix = std::array<std::array<float, N>, M>;

constexpr Matrix<2, 2> IDENTITY_2x2{ {{1,0},{0,1}} };

template<size_t M, size_t N, size_t L>
constexpr Matrix<M, L> operator*(const Matrix<M, N>& left, const Matrix<N, L>& right) {
    Matrix<M, L> res{};
    for (size_t i = 0; i < M; ++i) {
        for (size_t j = 0; j < L; ++j) {
            for (size_t k = 0; k < N; ++k) {
                res[i][j] += left[i][k] * right[k][j];
            }
        }
    }
    return res;
}

template<size_t M, size_t N>
constexpr Matrix<M, N>& operator*=(Matrix<M, N>& left, const Matrix<N, N>& right) {
    left = left * right;
    return left;
}

template<size_t M, size_t N>
constexpr Matrix<M, N> operator*(const Matrix<M, N>& left, float coefficient) {
    auto res = left;
    for (size_t i = 0; i < M; ++i) {
        for (size_t j = 0; j < N; ++j) {
            res[i][j] = res[i][j] * coefficient;
        }
    }
    return res;
}

template<size_t M, size_t N>
constexpr Matrix<M, N> operator*(float coefficient, const Matrix<M, N>& left) {
    auto res = left;
    for (size_t i = 0; i < M; ++i) {
        for (size_t j = 0; j < N; ++j) {
            res[i][j] = res[i][j] * coefficient;
        }
    }
    return res;
}

template<size_t M, size_t N>
constexpr Matrix<M, N> operator/(const Matrix<M, N>& left, float coefficient) {
    auto res = left;
    for (size_t i = 0; i < M; ++i) {
        for (size_t j = 0; j < N; ++j) {
            res[i][j] = res[i][j] / coefficient;
        }
    }
    return res;
}

template<size_t M, size_t N>
constexpr Matrix<M, N> operator+(const Matrix<M, N>& left, const Matrix<M, N>& right) {
    Matrix<M, N> res{};
    for (size_t i = 0; i < M; ++i) {
        for (size_t j = 0; j < N; ++j) {
            res[i][j] = left[i][j] + right[i][j];
        }
    }
    return res;
}

template<size_t M, size_t N>
constexpr Matrix<M, N> operator-(const Matrix<M, N>& left, const Matrix<M, N>& right) {
    Matrix<M, N> res{};
    for (size_t i = 0; i < M; ++i) {
        for (size_t j = 0; j < N; ++j) {
            res[i][j] = left[i][j] - right[i][j];
        }
    }
    return res;
}

template<size_t M, size_t N>
constexpr Matrix<M, N>& operator+=(Matrix<M, N>& left, const Matrix<M, N>& right) {
    for (size_t i = 0; i < M; ++i) {
        for (size_t j = 0; j < N; ++j) {
            left[i][j] = left[i][j] + right[i][j];
        }
    }
    return left;
}

template<size_t M, size_t N>
constexpr Matrix<M, N>& operator-=(Matrix<M, N>& left, const Matrix<M, N>& right) {
    for (size_t i = 0; i < M; ++i) {
        for (size_t j = 0; j < N; ++j) {
            left[i][j] = left[i][j] - right[i][j];
        }
    }
    return left;
}

//template<size_t M, size_t N>
//std::ostream& operator<<(std::ostream& os, const Matrix<M, N>& matrix) {
//    for (size_t i = 0; i < M; ++i) {
//        for (size_t j = 0; j < N; ++j) {
//            os << matrix[i][j] << ' ';
//            if (j == N - 1) {
//                os << '\n';
//            }
//        }
//    }
//    return os;
//}
