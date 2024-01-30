#pragma once

#include <cstdint>
#include "MilkyWay/Math/Vector/Vector3.h"
#include "MilkyWay/Math/Vector/Vector2.h"

namespace MilkyWay::Math
{

template <typename T>
struct Matrix3
{
public:
    T Data[3][3];

    static const Matrix3 Identity;

public:
    Matrix3();

    Matrix3(T p_value);

    Matrix3(T p_element1, T p_element2, T p_element3,
            T p_element4, T p_element5, T p_element6,
            T p_element7, T p_element8, T p_element9);

    Matrix3(const Matrix3 &p_other);

public:
    Matrix3 &operator=(const Matrix3 &p_other);

    bool operator==(const Matrix3 &p_other);

    Matrix3 operator+(const Matrix3 &p_other) const;

    Matrix3 &operator+=(const Matrix3 &p_other);

    Matrix3 operator-(const Matrix3 &p_other) const;

    Matrix3 &operator-=(const Matrix3 &p_other);

    Matrix3 operator*(T p_scalar) const;

    Matrix3 &operator*=(T p_scalar);

    Vector3<T> operator*(const Vector3<T> &p_vector) const;

    Matrix3 operator*(const Matrix3 &p_other) const;

    Matrix3 &operator*=(const Matrix3 &p_other);

    Matrix3 operator/(T p_scalar) const;

    Matrix3 &operator/=(T p_scalar);

    Matrix3 operator/(const Matrix3 &p_other) const;

    Matrix3 &operator/=(const Matrix3 &p_other);

public:
    T Determinant() const;
    Matrix3 Transpose() const;
    Matrix3 Manjor() const;
    Matrix3 Adjoint() const;
    Matrix3 Inverse() const;
};

using Matrix3f = Matrix3<float>;
} // namespace MilkyWay::Math