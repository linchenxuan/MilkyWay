#pragma once

namespace MilkyWay::Math
{
template <typename T>
class Vector3
{
public:
    union
    {
        struct
        {
            T X;
            T Y;
            T Z;
        };
        T Data[3];
    };

    static const Vector3 Zero;
    static const Vector3 Unit;

public:
    Vector3(T p_x, T p_y, T p_z);

    Vector3(const Vector3 &p_other);

public:
    Vector3 operator-() const;

    Vector3 operator=(const Vector3 &p_other);

    Vector3 operator+(const Vector3 &p_other) const;

    Vector3 &operator+=(const Vector3 &p_other);

    Vector3 operator-(const Vector3 &p_other) const;

    Vector3 &operator-=(const Vector3 &p_other);

    Vector3 operator*(T p_scalar) const;

    Vector3 operator*(const Vector3 &p_vec) const;

    Vector3 &operator*=(T p_scalar);

    Vector3 operator/(T p_scalar) const;

    Vector3 operator/(Vector3 p_vec3) const;

    Vector3 &operator/=(T p_scalar);

    bool operator==(const Vector3 &p_other);

    bool operator!=(const Vector3 &p_other);

    T operator[](int index) const;

    T DotProduct(const Vector3 &p_other) const;

    void CrossProduct(const Vector3 &p_other);

public:
    static T DotProduct(const Vector3 &p_a, const Vector3 &p_b);

    static Vector3 CrossProduct(const Vector3 &p_a, const Vector3 &p_b);
};

using Vector3f = Vector3<float>;
} // namespace MilkyWay::Math