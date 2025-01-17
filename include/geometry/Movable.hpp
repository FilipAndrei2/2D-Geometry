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
    class Movable {
        /**
         * @brief Virtual destructor for proper cleanup
         */
    public:
        virtual ~Movable() = default;
    
        virtual void moveTo(const Vector2& newPos) = 0;
        virtual void moveWith(const Vector2& changePos) = 0;
    };
}