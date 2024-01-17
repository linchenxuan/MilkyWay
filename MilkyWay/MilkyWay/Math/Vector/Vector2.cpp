#include <utility>
#include <stdexcept>

#include "Vector2.h"

namespace MilkyWay::Math
{
template <typename T>
Vector2<T>::Vector2(T p_x, T p_y) :
    X(p_x), Y(p_y)
{
}

template <typename T>
Vector2<T>::Vector2<T>(const Vector2<T> &p_toCopy) :
    X(p_toCopy.X), Y(p_toCopy.Y)
{
}

template <typename T>
Vector2<T> Vector2<T>::operator-() const
{
    return {-X, -Y};
}

template <typename T>
Vector2<T> Vector2<T>::operator=(const Vector2<T> &p_other)
{
    X = p_other.X;
    Y = p_other.Y;

    return *this;
}

template <typename T>
Vector2<T> Vector2<T>::operator+(const Vector2<T> &p_other) const
{
    return {X + p_other.X, Y + p_other.Y};
}

template <typename T>
Vector2<T> &Vector2<T>::operator+=(const Vector2<T> &p_other)
{
    X += p_other.X;
    Y += p_other.Y;
    return *this;
}

template <typename T>
Vector2<T> Vector2<T>::operator-(const Vector2<T> &p_other) const
{
    return {X - p_other.X, Y - p_other.Y};
}

template <typename T>
Vector2<T> &Vector2<T>::operator-=(const Vector2<T> &p_other)
{
    X -= p_other.X;
    Y -= p_other.Y;
    return *this;
}

template <typename T>
Vector2<T> Vector2<T>::operator*(T p_scalar) const
{
    return {X * p_scalar, Y * p_scalar};
}

template <typename T>
Vector2<T> &Vector2<T>::operator*=(T p_scalar)
{
    X *= p_scalar;
    Y *= p_scalar;
    return *this;
}

template <typename T>
Vector2<T> Vector2<T>::operator/(T p_scalar) const
{
    return {X / p_scalar, Y / p_scalar};
}

template <typename T>
Vector2<T> &Vector2<T>::operator/=(T p_scalar)
{
    X /= p_scalar;
    Y /= p_scalar;
    return *this;
}

template <typename T>
bool Vector2<T>::operator==(const Vector2<T> &p_other)
{
    return X == p_other.X && Y == p_other.Y;
}

template <typename T>
bool Vector2<T>::operator!=(const Vector2<T> &p_other)
{
    return X != p_other.X || Y != p_other.Y;
}

template <typename T>
T Vector2<T>::operator[](int index) const
{
    return Data[index];
}

template <typename T>
T Vector2<T>::DotProduct(const Vector2<T> &p_other)
{
    return X * p_other.X + Y * p_other.Y;
}

template <typename T>
static T Vector2<T>::DotProduct(const Vector2<T> &p_a, const Vector2<T> &p_b)
{
    return p_a.X * p_b.X + p_a.Y * p_b.Y;
}

} // namespace MilkyWay::Math
