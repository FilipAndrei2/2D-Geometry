/**
 * @file Rect.hpp
 * 
 * @brief A file that contains an interface for a 2D shape.
 * 
 * @author Filip Andrei
 * @date 12-01-2024
 */

#pragma once

#include "geometry/Shape.hpp"
#include "geometry/Movable.hpp"
#include "geometry/Vector2.hpp"

namespace geometry {
    class Rect : public Shape, public Movable {
        // ==============================
        //      Constructors and destructor
        // ==============================
    public:
        Rect(float x = 0, float y = 0, float width = 0, float height = 0);
        Rect(const Rect& src);

        virtual ~Rect() = default;

        // ==============================
        //      Public methods
        // ============================== 
    public:
        double area() const override;
        double perimeter() const override;
        Vector2 center() const override;

        void moveTo(const Vector2& newPos) override;
        void moveWith(const Vector2& posChange) override;
        Rect& scaleWith(float factor);
        Rect& resize(double width, double height);
        Rect& rotate90DegreesClockwise();
        Rect& rotate90DegreesTrigonometrically();

        bool isSquare() const;
        bool isValid() const;
        // ==============================
        //      Getters and setters
        // ==============================
    public:
        Vector2 getPosition() const;
        float getWidth() const;
        float getHeight() const;

        Rect& setWidth(float width);
        Rect& setHeight(float height);

        // ==============================
        //      Operators
        // ==============================
    public:
        Rect& operator =(const Rect& other);
        
        bool operator ==(const Rect& other);
        bool operator !=(const Rect& other);

        // ==============================
        //      Protected fields
        // ==============================
    protected:
        Vector2 position;
        float width, height;
    };
}