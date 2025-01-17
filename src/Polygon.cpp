/**
 * @file Polygon.cpp
 * 
 * @brief This file contains a class representing a poligon with n vertices
 * 
 * @author Filip Andrei
 * @date 12-01-2024
 */

#pragma once

#include "geometry/Polygon.hpp"

using namespace geometry;

Polygon::Polygon(const Polygon& src)
    : vertices(src.vertices)
{

}

double Polygon::area() const
{

}

double Polygon::perimeter() const
{

}

Vector2 Polygon::center() const
{
    float sumX = 0.0f, sumY = 0.0f;
    int numberOfVertices = vertices.size();
    
    for (const auto& vertex : vertices)
    {
        sumX += vertex.x;
        sumY += vertex.y;
    }

    return Vector2(sumX / numberOfVertices, sumY / numberOfVertices);
}

void Polygon::putVerticesInOrder()
{

}