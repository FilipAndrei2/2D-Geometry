/**
 * @file Shape.hpp
 * 
 * @brief A file that contains an interface for a 2D shape.
 * 
 * @author Filip Andrei
 * @date 12-01-2024
 */

#pragma once

#include <geometry/Vector2.hpp>

namespace geometry {
    class Shape {

        // ==============================
        //      Virtual destructor
        // ==============================
    public:
        /**
         * @brief Virtual destructor for proper cleanup
         */
        virtual ~Shape() = default;

        // ==============================
        //      Interface methods
        // ==============================
    public:
        virtual double area() const = 0;
        virtual double perimeter() const = 0;
        virtual Vector2 center() const = 0;
    };
}