#include <utility>
#include <stdexcept>
#include <cmath>

#include "Vector3.h"

namespace MilkyWay::Math
{
template <typename T>
Vector3<T>::Vector3<T>(T p_x, T p_y, T p_z) :
    X(p_x), Y(p_y), Z(p_z)
{
}

template <typename T>
Vector3<T>::Vector3<T>(const Vector3<T> &p_toCopy) :
    X(p_toCopy.X), Y(p_toCopy.Y), Z(p_toCopy.Z)
{
}

template <typename T>
Vector3<T> Vector3<T>::operator-() const
{
    return {-X, -Y, -Z};
}

template <typename T>
Vector3<T> Vector3<T>::operator=(const Vector3<T> &p_other)
{
    X = p_other.X;
    Y = p_other.Y;
    Z = p_other.Z;

    return *this;
}

template <typename T>
Vector3<T> Vector3<T>::operator+(const Vector3<T> &p_other) const
{
    return {X + p_other.X, Y + p_other.Y, Z + p_other.Z};
}

template <typename T>
Vector3<T> &Vector3<T>::operator+=(const Vector3<T> &p_other)
{
    X += p_other.X;
    Y += p_other.Y;
    Z += p_other.Z;

    return *this;
}

template <typename T>
Vector3<T> Vector3<T>::operator-(const Vector3<T> &p_other) const
{
    return {X - p_other.X, Y - p_other.Y, Z - p_other.Z};
}

template <typename T>
Vector3<T> &Vector3<T>::operator-=(const Vector3<T> &p_other)
{
    X -= p_other.X;
    Y -= p_other.Y;
    Z -= p_other.Z;

    return *this;
}

template <typename T>
Vector3<T> Vector3<T>::operator*(T p_scalar) const
{
    return {X * p_scalar, Y * p_scalar, Z * p_scalar};
}

template <typename T>
Vector3<T> Vector3<T>::operator*(const Vector3<T> &p_vec) const
{
    return Vector3{p_vec.X * p_vec.X, p_vec.Y * p_vec.Y, p_vec.Z * p_vec.Z};
}

template <typename T>
Vector3<T> &Vector3<T>::operator*=(T p_scalar)
{
    X *= p_scalar;
    Y *= p_scalar;
    Z *= p_scalar;

    return *this;
}

template <typename T>
Vector3<T> Vector3<T>::operator/(T p_scalar) const
{
    return {X / p_scalar, Y / p_scalar, Z / p_scalar};
}

template <typename T>
Vector3<T> Vector3<T>::operator/(Vector3<T> p_vec3) const
{
    return {X / p_vec3.X, Y / p_vec3.Y, Z / p_vec3.Z};
}

template <typename T>
Vector3<T> &Vector3<T>::operator/=(T p_scalar)
{
    X /= p_scalar;
    Y /= p_scalar;
    Z /= p_scalar;

    return *this;
}

template <typename T>
bool Vector3<T>::operator==(const Vector3<T> &p_other)
{
    return X == p_other.X && Y == p_other.Y && Z == p_other.Z;
}

template <typename T>
bool Vector3<T>::operator!=(const Vector3<T> &p_other)
{
    return X != p_other.X || Y != p_other.Y || Z != p_other.Z;
}

template <typename T>
T Vector3<T>::operator[](int index) const
{
    return Data[index];
}

template <typename T>
T Vector3<T>::DotProduct(const Vector3<T> &p_other) const
{
    return X * p_other.X + Y * p_other.Y + Z * p_other.Z;
}

template <typename T>
void Vector3<T>::CrossProduct(const Vector3<T> &p_other)
{
    T x = Y * p_other.Z - Z * p_other.Y;
    T y = Z * p_other.X - X * p_other.Z;
    T z = X * p_other.Y - Y * p_other.X;
    X = x;
    Y = y;
    Z = z;
}

template <typename T>
T static Vector3<T>::DotProduct(const Vector3 &p_a, const Vector3 &p_b)
{
    return p_a.X * p_b.X + p_a.Y * p_b.Y + p_a.Z * p_b.Z;
}

template <typename T>
static Vector3<T> Vector3<T>::CrossProduct(const Vector3 &p_a, const Vector3 &p_b)
{
    return {p_a.Y * p_b.Z - p_a.Z * p_b.Y, p_a.Z * p_b.X - p_a.X * p_b.Z, p_a.X * p_b.Y - p_a.Y * p_b.X};
}

} // namespace MilkyWay::Math
