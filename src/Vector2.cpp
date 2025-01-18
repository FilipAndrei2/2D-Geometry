#include <geometry/Vector2.hpp>

#include <cmath>

#include "geometry/internal/common.hpp"
#include "geometry/utils.hpp"

using namespace geometry;

Vector2::Vector2(float x, float y)
    : x(x), y(y)
{

}

Vector2::Vector2(const Vector2& src)
    : x(src.x), y(src.y)
{

}

Vector2::~Vector2()
{

}

float Vector2::lenght() const
{
    if (!cache.lenght.has_value())
    {
        cache.lenght.emplace(std::sqrt(x*x + y*y));
        
    }
    return cache.lenght.value();
}

float Vector2::sinTheta() const
{
    if (!cache.sinTheta.has_value())
    {
        cache.sinTheta.emplace(y / this->lenght());
    }
    return cache.sinTheta.value();
}

float Vector2::cosTheta() const
{
    if (!cache.cosTheta.has_value())
    {
        cache.cosTheta.emplace(x / this->lenght());
    }
    return cache.cosTheta.value();
}

float Vector2::dot(const Vector2& other) const
{
    return this->x * other.x + this->y * other.y;
}

float Vector2::angleBetween(const Vector2& other)
{
    return std::acos(this->dot(other) / (this->lenght() * other.lenght()));
}

Vector2 Vector2::normalized() const
{
    float lenght = this->lenght();
    if (lenght <= FLOAT_EPSILON)
    {
        return Vector2(0.0f, 0.0f);
    }
    return Vector2(x/lenght, y/lenght);
}

Vector2 Vector2::rotatedBy(float thetaRadians) const
{
    float sinTheta = std::sin(thetaRadians);
    float cosTheta = std::cos(thetaRadians);
    return Vector2(x * cosTheta - y * sinTheta, x * sinTheta + y * cosTheta);
}

Vector2 Vector2::scaledBy(float scalar) const
{
    return Vector2(scalar * x, scalar * y);
}

bool Vector2::isEqual(const Vector2& other) const
{
    return floatEq(this->x, other.y) && floatEq(this->y, other.y);
}

bool Vector2::isLessThan(const Vector2& other) const
{
    return this->lenght() < other.lenght();
}

bool Vector2::isGreaterThan(const Vector2& other) const
{
    return this->lenght() > other.lenght();
}

bool Vector2::isNull() const
{
    return (x <= FLOAT_EPSILON) && (y <= FLOAT_EPSILON);
}

Vector2& Vector2::moveTo(const float x, const float y)
{
    this->x = x;
    this->y = y;

    cache.invalidate();
    return *this;
}

Vector2& Vector2::normalize()
{
    float lenght = this->lenght();

    if (lenght > FLOAT_EPSILON)
    {
        x /= lenght;
        y /= lenght;
    }

    cache.invalidate();
    return *this;
}

Vector2& Vector2::rotateBy(float radians)
{
    float sinTheta = std::sin(radians);
    float cosTheta = std::cos(radians);
    float oldX = x;

    x = x * cosTheta - y * sinTheta;
    y = oldX * sinTheta + y * cosTheta;    

    cache.invalidate();
    return *this;
}

Vector2& Vector2::scaleBy(float scalar)
{
    x *= scalar;
    y *= scalar;

    cache.invalidate();
    return *this;
}

Vector2& Vector2::add(const Vector2& other)
{
    this->x += other.x;
    this->y += other.y;

    cache.invalidate();
    return *this;
}

Vector2& Vector2::subtract(const Vector2& other)
{
    this->x -= other.x;
    this->y -= other.y;

    cache.invalidate();
    return *this;
}

Vector2& Vector2::precompute()
{
    if(!cache.lenght.has_value())
    {
        cache.lenght.emplace(this->lenght());
    }
    if (!cache.cosTheta.has_value())
    {
        cache.cosTheta.emplace(this->cosTheta());
    }
    if (!cache.sinTheta.has_value())
    {
        cache.sinTheta.emplace(this->sinTheta());
    }

    return *this;
}

bool Vector2::operator ==(const Vector2& other) const
{
    return this->isEqual(other);
}

bool Vector2::operator !=(const Vector2& other) const
{
    return !this->isEqual(other);
}

bool Vector2::operator <(const Vector2& other) const
{
    return isLessThan(other);
}

bool Vector2::operator >(const Vector2& other) const
{
    return isGreaterThan(other);
}

bool Vector2::operator <=(const Vector2& other) const
{
    return isLessThan(other) || (floatEq(this->lenght(), other.lenght()));
}

bool Vector2::operator >=(const Vector2& other) const
{
    return isGreaterThan(other) || (floatEq(this->lenght(), other.lenght()))
}

Vector2 Vector2::operator -() const
{
    return *this * (-1.0f);
}

Vector2 Vector2::operator +() const
{
    return Vector2(*this);
}

Vector2 Vector2::operator +(const Vector2& other) const
{
    return Vector2(this->x + other.x, this->y + other.y);
}

Vector2 Vector2::operator -(const Vector2& other) const
{
    return Vector2(this->x - other.x, this->y - other.y);
}

Vector2 Vector2::operator *(const float scalar) const
{
    return Vector2(this->x * scalar, this->y * scalar);
}

Vector2 Vector2::operator /(const float scalar) const
{
    return Vector2(this->x / scalar, this->y / scalar);
}

Vector2& Vector2::operator =(const Vector2& src)
{
    this->x = src.x;
    this->y = src.y;

    return *this;
}

Vector2& Vector2::operator +=(const Vector2& other)
{
    this->x += other.x;
    this->y += other.y;

    return *this;
}

Vector2& Vector2::operator -=(const Vector2& other)
{
    this->x -= other.x;
    this->y -= other.y;

    return *this;
}

Vector2& Vector2::operator *=(const float scalar)
{
    this->x *= scalar;
    this->y *= scalar;

    return *this;
}

Vector2& Vector2::operator /=(const float scalar)
{
    this->x /= scalar;
    this->y /= scalar;

    return *this;
}