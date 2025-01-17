/**
 * @file Polygon.cpp
 * 
 * @brief This file contains a class representing a poligon with n vertices
 * 
 * @author Filip Andrei
 * @date 12-01-2024
 */

#pragma once

#include <vector>
#include <stdexcept>


#include "geometry/Vector2.hpp"
#include "geometry/Shape.hpp"
#include "geometry/Movable.hpp"

namespace geometry {
    class Polygon : public Shape, public Movable {
        // ==============================
        //      Constructors and destructor
        // ==============================
    public:
        template <typename ...Vertices>
        Polygon(Vector2 firstVertice, Vector2 secondVertice, Vector2 thirdVertice, Vertices... restVertices)
            : vertices{firstVertice, secondVertice, thirdVertice, restVertices...}
        {

        }

        Polygon(const Polygon& src);

        virtual ~Polygon() = default;

        // ==============================
        //      Public methods
        // ==============================
    public:
        double area() const override;
        double perimeter() const override;
        Vector2 center() const override;

        void moveTo(const Vector2& newPos) override;
        void moveWith(const Vector2& changePos) override;

        Polygon& addVertex(const Vector2 vertex);

        // ==============================
        //      Private fields
        // ==============================
    private:
        std::vector<Vector2> vertices;

        // ==============================
        //      Private methods
        // ==============================
    private:
        void putVerticesInOrder();
    };
}