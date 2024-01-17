#pragma once

namespace MilkyWay::Math
{
template <typename T>
class Vector2
{
public:
    union
    {
        struct
        {
            T X;
            T Y;
        };

        T Data[2];
    };

    static const Vector2 Zero;
    static const Vector2 Unit;

public:
    Vector2(T p_x, T p_y);

    Vector2(const Vector2 &p_other);

public:
    Vector2 operator=(const Vector2 &p_other);

    bool operator==(const Vector2 &p_other);

    bool operator!=(const Vector2 &p_other);

    Vector2 operator-() const;

    Vector2 operator-(const Vector2 &p_other) const;

    Vector2 &operator-=(const Vector2 &p_other);

    Vector2 operator+(const Vector2 &p_other) const;

    Vector2 &operator+=(const Vector2 &p_other);

    Vector2 operator*(T p_scalar) const;

    Vector2 &operator*=(T p_scalar);

    Vector2 operator/(T p_scalar) const;

    Vector2 &operator/=(T p_scalar);

    T operator[](int index) const;

    T DotProduct(const Vector2 &p_other);

public:
    static T DotProduct(const Vector2 &p_a, const Vector2 &p_b);
};

using Vector2f = Vector2<float>;

} // namespace MilkyWay::Math