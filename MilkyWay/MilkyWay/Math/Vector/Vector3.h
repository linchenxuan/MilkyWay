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
    Vector3(T p_x, T p_y, T p_z) :
        X(p_x), Y(p_y), Z(p_z)
    {
    }

    Vector3(const Vector3 &p_toCopy) :
        X(p_toCopy.X), Y(p_toCopy.Y), Z(p_toCopy.Z)
    {
    }

public:
    Vector3() = default;

    Vector3 operator-() const
    {
        return {-X, -Y, -Z};
    }

    Vector3 operator=(const Vector3 &p_other)
    {
        X = p_other.X;
        Y = p_other.Y;
        Z = p_other.Z;

        return *this;
    }

    Vector3 operator+(const Vector3 &p_other) const
    {
        return {X + p_other.X, Y + p_other.Y, Z + p_other.Z};
    }

    Vector3 &operator+=(const Vector3 &p_other)
    {
        X += p_other.X;
        Y += p_other.Y;
        Z += p_other.Z;

        return *this;
    }

    Vector3 operator-(const Vector3 &p_other) const
    {
        return {X - p_other.X, Y - p_other.Y, Z - p_other.Z};
    }

    Vector3 &operator-=(const Vector3 &p_other)
    {
        X -= p_other.X;
        Y -= p_other.Y;
        Z -= p_other.Z;

        return *this;
    }

    Vector3 operator*(T p_scalar) const
    {
        return {X * p_scalar, Y * p_scalar, Z * p_scalar};
    }

    Vector3 operator*(const Vector3 &p_vec) const
    {
        return Vector3{p_vec.X * p_vec.X, p_vec.Y * p_vec.Y, p_vec.Z * p_vec.Z};
    }

    Vector3 &operator*=(T p_scalar)
    {
        X *= p_scalar;
        Y *= p_scalar;
        Z *= p_scalar;

        return *this;
    }

    Vector3 operator/(T p_scalar) const
    {
        return {X / p_scalar, Y / p_scalar, Z / p_scalar};
    }

    Vector3 operator/(Vector3 p_vec3) const
    {
        return {X / p_vec3.X, Y / p_vec3.Y, Z / p_vec3.Z};
    }

    Vector3 &operator/=(T p_scalar)
    {
        X /= p_scalar;
        Y /= p_scalar;
        Z /= p_scalar;

        return *this;
    }

    bool operator==(const Vector3 &p_other)
    {
        return X == p_other.X && Y == p_other.Y && Z == p_other.Z;
    }

    bool operator!=(const Vector3 &p_other)
    {
        return X != p_other.X || Y != p_other.Y || Z != p_other.Z;
    }

    T operator[](int p_index) const
    {
        return Data[p_index];
    }

    T DotProduct(const Vector3 &p_other) const
    {
        return X * p_other.X + Y * p_other.Y + Z * p_other.Z;
    }

    void CrossProduct(const Vector3 &p_other)
    {
        T x = Y * p_other.Z - Z * p_other.Y;
        T y = Z * p_other.X - X * p_other.Z;
        T z = X * p_other.Y - Y * p_other.X;
        X = x;
        Y = y;
        Z = z;
    }

public:
    static T DotProduct(const Vector3 &p_a, const Vector3 &p_b)
    {
        return p_a.X * p_b.X + p_a.Y * p_b.Y + p_a.Z * p_b.Z;
    }

    static Vector3 CrossProduct(const Vector3 &p_a, const Vector3 &p_b)
    {
        return {p_a.Y * p_b.Z - p_a.Z * p_b.Y, p_a.Z * p_b.X - p_a.X * p_b.Z, p_a.X * p_b.Y - p_a.Y * p_b.X};
    }
};

using Vector3f = Vector3<float>;
} // namespace MilkyWay::Math
