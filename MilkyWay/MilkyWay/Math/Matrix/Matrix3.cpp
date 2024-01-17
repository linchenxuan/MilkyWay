#include <string>
#include <stdexcept>
#include <cmath>

#include "Matrix3.h"

namespace MilkyWay::Math
{

template <typename T>
Matrix3<T>::Matrix3()
{
    memcpy(Data, Identity.Data, sizeof(Data));
}

template <typename T>
Matrix3<T>::Matrix3(T p_value)
{
    memset(Data, p_value, sizeof(Data));
}

template <typename T>
Matrix3<T>::Matrix3(T p_element1, T p_element2, T p_element3, T p_element4, T p_element5, T p_element6, T p_element7, T p_element8, T p_element9)
{
    Data[0] = p_element1;
    Data[1] = p_element2;
    Data[2] = p_element3;
    Data[1][0] = p_element4;
    Data[1][1] = p_element5;
    Data[1][2] = p_element6;
    Data[2][0] = p_element7;
    Data[2][1] = p_element8;
    Data[2][2] = p_element9;
}

template <typename T>
Matrix3<T>::Matrix3(const Matrix3<T> &p_other)
{
    *this = p_other;
}

template <typename T>
Matrix3<T> &Matrix3<T>::operator=(const Matrix3<T> &p_other)
{
    memcpy(this->Data, p_other.Data, sizeof(Data));
    return *this;
}

template <typename T>
bool Matrix3<T>::operator==(const Matrix3<T> &p_other)
{
    return memcmp(this, &p_other, sizeof(Data)) == 0;
}

template <typename T>
Matrix3<T> Matrix3<T>::operator+(const Matrix3<T> &p_other) const
{
    Matrix3<T> result(*this);
    for (uint8_t i = 0; i < 3; ++i)
    {
        for (uint8_t j = 0; j < 3; j++)
        {
            result.Data[i][j] += p_other[i][j];
        }
    }

    return result;
}

template <typename T>
Matrix3<T> &Matrix3<T>::operator+=(const Matrix3<T> &p_other)
{
    for (uint8_t i = 0; i < 3; ++i)
    {
        for (uint8_t j = 0; j < 3; j++)
        {
            Data[i][j] += p_other[i][j];
        }
    }

    return *this;
}

template <typename T>
Matrix3<T> Matrix3<T>::operator-(const Matrix3<T> &p_other) const
{
    Matrix3<T> result(*this);
    for (uint8_t i = 0; i < 3; ++i)
    {
        for (uint8_t j = 0; j < 3; j++)
        {
            result.Data[i][j] -= p_other[i][j];
        }
    }

    return result;
}

template <typename T>
Matrix3<T> &Matrix3<T>::operator-=(const Matrix3<T> &p_other)
{
    for (uint8_t i = 0; i < 3; ++i)
    {
        for (uint8_t j = 0; j < 3; j++)
        {
            Data[i][j] -= p_other[i][j];
        }
    }

    return *this;
}

template <typename T>
Matrix3<T> Matrix3<T>::operator*(T p_scalar) const
{
    Matrix3<T> result(*this);
    for (uint8_t i = 0; i < 3; ++i)
    {
        for (uint8_t j = 0; j < 3; j++)
        {
            result.Data[i][j] *= p_scalar;
        }
    }
}

template <typename T>
Matrix3<T> &Matrix3<T>::operator*=(T p_scalar)
{
    for (uint8_t i = 0; i < 3; ++i)
    {
        for (uint8_t j = 0; j < 3; j++)
        {
            Data[i][j] *= p_scalar;
        }
    }

    return *this;
}

template <typename T>
Vector3<T> Matrix3<T>::operator*(const Vector3<T> &p_vector) const
{
    Vector3<T> result;
    result.x = ((Data[0][0] * p_vector.x) + (Data[0][1] * p_vector.y) + (Data[0][2] * p_vector.z));
    result.y = ((Data[1][0] * p_vector.x) + (Data[1][1] * p_vector.y) + (Data[1][2] * p_vector.z));
    result.z = ((Data[2][0] * p_vector.x) + (Data[2][1] * p_vector.y) + (Data[2][2] * p_vector.z));

    return result;
}

template <typename T>
Matrix3<T> Matrix3<T>::operator*(const Matrix3<T> &p_other) const
{
    return Matrix3<T>(
        (Data[0][0] * p_other.Data[0][0]) + (Data[0][1] * p_other.Data[1][0]) + (Data[0][2] * p_other.Data[2][0]),
        (Data[0][0] * p_other.Data[0][1]) + (Data[0][1] * p_other.Data[1][1]) + (Data[0][2] * p_other.Data[2][1]),
        (Data[0][0] * p_other.Data[0][2]) + (Data[0][1] * p_other.Data[1][2]) + (Data[0][2] * p_other.Data[2][2]),

        (Data[1][0] * p_other.Data[0][0]) + (Data[1][1] * p_other.Data[1][0]) + (Data[1][2] * p_other.Data[2][0]),
        (Data[1][0] * p_other.Data[0][1]) + (Data[1][1] * p_other.Data[1][1]) + (Data[1][2] * p_other.Data[2][1]),
        (Data[1][0] * p_other.Data[0][2]) + (Data[1][1] * p_other.Data[1][2]) + (Data[1][2] * p_other.Data[2][2]),

        (Data[2][0] * p_other.Data[0][0]) + (Data[2][1] * p_other.Data[1][0]) + (Data[2][2] * p_other.Data[2][0]),
        (Data[2][0] * p_other.Data[0][1]) + (Data[2][1] * p_other.Data[1][1]) + (Data[2][2] * p_other.Data[2][1]),
        (Data[2][0] * p_other.Data[0][2]) + (Data[2][1] * p_other.Data[1][2]) + (Data[2][2] * p_other.Data[2][2]));
}

template <typename T>
Matrix3<T> &Matrix3<T>::operator*=(const Matrix3<T> &p_other)
{
    *this = this * p_other;
    return *this;
}

template <typename T>
Matrix3<T> Matrix3<T>::operator/(T p_scalar) const
{
    Matrix3<T> result(*this);
    for (T &element : result.Data)
    {
        element /= p_scalar;
    }
    return result;
}

template <typename T>
Matrix3<T> &Matrix3<T>::operator/=(T p_scalar)
{
    for (T &element : Data)
    {
        element /= p_scalar;
    }
    return *this;
}

template <typename T>
Matrix3<T> Matrix3<T>::operator/(const Matrix3<T> &p_other) const
{
    return *this * Inverse(p_other);
}

template <typename T>
Matrix3<T> &Matrix3<T>::operator/=(const Matrix3<T> &p_other)
{
    *this = *this * Inverse(p_other);
    return *this;
}

template <typename T>
T Matrix3<T>::Determinant() const
{
    return Data[0][0] * (Data[1][1] * Data[2][2] - Data[1][2] * Data[2][1])
           - Data[0][1] * (Data[1][0] * Data[2][2] - Data[1][2] * Data[2][0])
           + Data[0][2] * (Data[1][0] * Data[2][1] - Data[1][1] * Data[2][0]);
}

template <typename T>
Matrix3<T> Matrix3<T>::Transpose() const
{
    Matrix3<T> result;

    result.Data[0][0] = Data[0][0];
    result.Data[0][1] = Data[1][0];
    result.Data[0][2] = Data[2][0];

    result.Data[1][0] = Data[0][1];
    result.Data[1][1] = Data[1][1];
    result.Data[1][2] = Data[2][1];

    result.Data[2][0] = Data[0][2];
    result.Data[2][1] = Data[1][2];
    result.Data[2][2] = Data[2][2];

    result.Data[3][0] = Data[0][3];
    result.Data[3][1] = Data[1][3];
    result.Data[3][2] = Data[2][3];

    return result;
}

template <typename T>
Matrix3<T> Matrix3<T>::Manjor() const
{
    Matrix3<T> result;

    result.Data[0][0] = Data[1][1] * Data[2][2] - Data[1][2] * Data[2][1];
    result.Data[0][1] = -(Data[1][0] * Data[2][2] - Data[1][2] * Data[2][0]);
    result.Data[0][2] = Data[1][0] * Data[2][1] - Data[1][1] * Data[2][0];

    result.Data[1][0] = -(Data[0][1] * Data[2][2] - Data[0][2] * Data[2][1]);
    result.Data[1][1] = Data[0][0] * Data[2][2] - Data[0][2] * Data[2][0];
    result.Data[1][2] = -(Data[0][0] * Data[2][1] - Data[0][1] * Data[1][1]);

    result.Data[2][0] = Data[0][1] * Data[1][2] - Data[0][2] * Data[1][1];
    result.Data[2][1] = -(Data[0][0] * Data[1][2] - Data[0][2] * Data[1][0]);
    result.Data[2][2] = Data[0][0] * Data[1][1] - Data[0][1] * Data[1][0];

    return result;
}

template <typename T>
Matrix3<T> Matrix3<T>::Adjoint() const
{
    Matrix3<T> result;

    result.Data[0][0] = Data[1][1] * Data[2][2] - Data[1][2] * Data[2][1];
    result.Data[0][1] = Data[1][0] * Data[2][2] - Data[1][2] * Data[2][0];
    result.Data[0][2] = Data[1][0] * Data[2][1] - Data[1][1] * Data[2][0];

    result.Data[1][0] = Data[0][1] * Data[2][2] - Data[0][2] * Data[2][1];
    result.Data[1][1] = Data[0][0] * Data[2][2] - Data[0][2] * Data[2][0];
    result.Data[1][2] = Data[0][0] * Data[2][1] - Data[0][1] * Data[1][1];

    result.Data[2][0] = Data[0][1] * Data[1][2] - Data[0][2] * Data[1][1];
    result.Data[2][1] = Data[0][0] * Data[1][2] - Data[0][2] * Data[1][0];
    result.Data[2][2] = Data[0][0] * Data[1][1] - Data[0][1] * Data[1][0];

    return result;
}

template <typename T>
Matrix3<T> Matrix3<T>::Inverse() const
{
    T determinant = Determinant();
    if (determinant())
    {
        throw std::logic_error("determinant is 0");
    }

    return Adjoint() / determinant;
}
} // namespace MilkyWay::Math
