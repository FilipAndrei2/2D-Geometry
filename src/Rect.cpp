/**
 * @file Rect.cpp
 * 
 * @brief Implementation of the methods from the @c geometry::Rect class
 * 
 * @author Filip Andrei
 * @date 12-01-2024
 */

#include "geometry/Rect.hpp"

#include <cmath>

#include "geometry/internal/common.hpp"

using namespace geometry;

Rect::Rect(float x, float y, float width, float height)
    : position(x, y), width(width), height(height)
{

}

Rect::Rect(const Rect& src)
    : position(src.position), width(src.width), height(src.height)
{

}

double Rect::area() const
{
    return width * height;
}

double Rect::perimeter() const
{
    return 2 * width + 2 * height;
}

Vector2 Rect::center() const
{
    return position + Vector2(width / 2, height / 2);
}

void Rect::moveTo(const Vector2& newPos)
{
    position = newPos;
}

void Rect::moveWith(const Vector2& posChange)
{
    this->position += posChange;
}

Rect&Rect::scaleWith(float factor)
{
    this->width *= factor;
    this->height *= factor;
    return *this;
}

Rect&Rect::resize(double width, double height)
{
    this->width = width;
    this->height = height;
    return *this;
}

Rect&Rect::rotate90DegreesClockwise()
{
    float temp = this->width;
    this->width = this->height;
    this->height = temp;

    return *this;
}

Rect&Rect::rotate90DegreesTrigonometrically()
{
    float temp = this->width;
    this->width = this->height;
    this->height = temp;

    this->position.x -= width;

    return *this;
}

bool Rect::isSquare() const
{
    return fabs(this->width - this->height) < FLOAT_EPSILON;
}

bool Rect::isValid() const
{
    return (this->width > FLOAT_EPSILON) && (this->height > FLOAT_EPSILON);  
}

Vector2 Rect::getPosition() const
{
    return Vector2(this->position);
}

float Rect::getWidth() const
{
    return this->width;
}

float Rect::getHeight() const
{
    return this->height;
}

Rect& Rect::setWidth(float width)
{
    this->width = width;
    return *this;
}

Rect& Rect::setHeight(float height)
{
    this->height = height;
    return *this;
}

Rect& Rect::operator =(const Rect& other)
{
    this->position = other.position;
    this->width = other.width;
    this->height = other.height;

    return *this;
}

bool Rect::operator ==(const Rect& other)
{
    return (this->position == other.position) && (fabs(this->width - other.width) < FLOAT_EPSILON) && (fabs(this->height - other.height) < FLOAT_EPSILON);
}

bool Rect::operator !=(const Rect& other)
{
    return !(*this == other);
}