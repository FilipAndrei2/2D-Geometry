/**
 * @file Vector2.hpp
 * 
 * @brief A file that contains the definitions of a class made for manipulating 2D vectors.
 * 
 * @author Filip Andrei
 * @date 12-01-2024
 */

#pragma once

#include <optional>

namespace geometry {
    struct Vector2 final {

        // ==============================
        //      Public members
        // ==============================
    public:
        /**
         * Coordinates of a 2D vector.
         * The coordinates are relative to the top-left corner of the screen.
         */
        float x, y; 

        // ==============================
        //      Constructors and Destructor
        // ==============================
    public:
        Vector2(float x = 0.0f, float y = 0.0f);
        
        /**
         * @brief The copy constructor of the Vector2 class.
         * 
         * This method constructs a @c Vector2 object from another @c Vector2 source object.
         * 
         * @param src The reference source @c Vector2 object. 
         */
        Vector2(const Vector2& src);

        ~Vector2();

        // ==============================
        //      Public methods
        // ==============================
    public:
        // Const methods

        /**
         * @brief Returns the magnitude of the vector. 
         * 
         * @returns The magnitude of the vector as a float.
         */
        float lenght() const;

        /**
         * @brief Returns the sin of the angle between the current object vector and OX.
         * 
         * @returns The value of the sin of the angle between the current object vector and OX as a float.
         */
        float sinTheta() const;

        /**
         * @brief Returns the cos of the angle between the current object vector and OX.
         * 
         * @returns The value of the sin of the angle between the current object vector and OX as a float.
         */
        float cosTheta() const;

        /**
         * @brief Calculates the dot product of this vector and another vector.
         * 
         * This method computes the dot product between the current vector and another @c Vector2 object.
         * The dot product is a scalar value that represents the 
         * projection of one vector onto another and is often used in calculations 
         * involving angles and magnitudes. 
         * 
         * @param other The other vector to compute the dot product with.
         * 
         * @returns The dot product as a float.
         */
        float dot(const Vector2& other) const;

        /**
         * @brief Calculates the angle between this vector and another.
         * 
         * This method computes the value of the angle of this vector and another 'Vector2' object.
         * 
         * @param other The other vector to compute the angle from.
         * 
         * @returns The value of the angle in radians as a float.
         */
        float angleBetween(const Vector2& other);

        /**
         * @brief Returns a normalized version of this vector.
         * 
         * This method doesn't modify the internal state of the object.
         * 
         * @returns The current vector normalized returned as a @c Vector2 object
         */
        Vector2 normalized() const;

        /**
         * @brief Returns a vector that is rotated  with an angle.
         * 
         * The rotation is performed in trigonometric sense (counterclockwise).
         * This method doesn't modify the internal state of the current instance object.
         * 
         * @param thetaRadians The angle of rotation in radians.
         * 
         * @returns The result of the rotation as a @c Vector2 object.
         */
        Vector2 rotatedBy(float thetaRadians) const;

        /**
         *  @brief Returns a scaled version of the current instance object
         * 
         * For trimming a vector, provide a subunitar factor. 
         * 
         * @param factor Floating value scaling factor.
         * 
         * @returns A scaled version of the current vector.
         */
        Vector2 scaledBy(float factor) const;

        /**
         * @brief Checks for equality between two vectors.
         * 
         * Two vectors are equal if they point to the same coordinates.
         * The equality of floats is made with an epsilon error value of 1e-6.
        */
        bool isEqual(const Vector2& other) const;
        
        bool isLessThan(const Vector2& other) const;
        bool isGreaterThan(const Vector2& other) const;
        bool isNull() const;

        // Object modifier methods
        Vector2& moveTo(const float x,const float y);
        Vector2& normalize();
        Vector2& rotateBy(float radians);
        Vector2& scaleBy(float scalar);
        Vector2& add(const Vector2& other);
        Vector2& subtract(const Vector2& other);

        /**
         * @brief Computes the non-existen cache fields.
         */
        Vector2& precompute();

        // ==============================
        //      Operators
        // ==============================

        bool operator ==(const Vector2& other) const;
        bool operator !=(const Vector2& other) const;
        bool operator <(const Vector2& other) const;
        bool operator >(const Vector2& other) const;
        bool operator <=(const Vector2& other) const;
        bool operator >=(const Vector2& other) const;

        Vector2 operator -() const;
        Vector2 operator +() const;

        Vector2 operator +(const Vector2& other) const;
        Vector2 operator -(const Vector2& other) const;
        Vector2 operator *(const float scalar) const;
        Vector2 operator /(const float scalar) const;
        
        Vector2& operator =(const Vector2& src);
        Vector2& operator +=(const Vector2& other);
        Vector2& operator -=(const Vector2& other);
        Vector2& operator *=(const float scalar);
        Vector2& operator /=(const float scalar);

    public:


        // ==============================
        //      Private members
        // ==============================
    private:
        struct Cache {
            using OptionalFloat = std::optional<float>;
            mutable OptionalFloat lenght;
            mutable OptionalFloat sinTheta;
            mutable OptionalFloat cosTheta;

            Cache& invalidate()
            {
                lenght.reset();
                sinTheta.reset();
                cosTheta.reset();
                return *this;
            }
        } mutable cache;
        
    };
}