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
    Vector2() = default;

    Vector2(T p_x, T p_y) :
        X(p_x), Y(p_y){};

    Vector2(const Vector2 &p_toCopy) :
        X(p_toCopy.X), Y(p_toCopy.Y){};

public:
    Vector2 operator=(const Vector2 &p_other)
    {
        X = p_other.X;
        Y = p_other.Y;

        return *this;
    }

    bool operator==(const Vector2 &p_other)
    {
        return X == p_other.X && Y == p_other.Y;
    };

    bool operator!=(const Vector2 &p_other)
    {
        return X != p_other.X || Y != p_other.Y;
    }

    Vector2 operator-() const
    {
        return {-X, -Y};
    }

    Vector2 operator-(const Vector2 &p_other) const
    {
        return {X - p_other.X, Y - p_other.Y};
    }

    Vector2 &operator-=(const Vector2 &p_other)
    {
        X -= p_other.X;
        Y -= p_other.Y;
        return *this;
    }

    Vector2 operator+(const Vector2 &p_other) const
    {
        return {X + p_other.X, Y + p_other.Y};
    };

    Vector2 &operator+=(const Vector2 &p_other)
    {
        X += p_other.X;
        Y += p_other.Y;
        return *this;
    }

    Vector2 operator*(T p_scalar) const
    {
        return {X * p_scalar, Y * p_scalar};
    }

    Vector2 &operator*=(T p_scalar)
    {
        X *= p_scalar;
        Y *= p_scalar;
        return *this;
    }

    Vector2 operator/(T p_scalar) const
    {
        return {X / p_scalar, Y / p_scalar};
    }

    Vector2 &operator/=(T p_scalar)
    {
        X /= p_scalar;
        Y /= p_scalar;
        return *this;
    }

    T operator[](int p_index) const
    {
        return Data[p_index];
    }
    T DotProduct(const Vector2 &p_other)
    {
        return X * p_other.X + Y * p_other.Y;
    }

public:
    static T DotProduct(const Vector2 &p_a, const Vector2 &p_b)
    {
        return p_a.X * p_b.X + p_a.Y * p_b.Y;
    }
};

using Vector2f = Vector2<float>;

} // namespace MilkyWay::Math
