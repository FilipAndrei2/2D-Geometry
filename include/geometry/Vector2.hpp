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
         * This method doesn't modify the internal state of the current instance object.
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
         * This method doesn't modify the internal state of the current instance object.
         * 
         * @param other The vector that will be checked for equality with the current instance object.
         * 
         * @return true If the x and y of the vectors are the same.
         * @return false If the x and y of the vectors are not equal.
         */
        bool isEqual(const Vector2& other) const;
        
        /**
         * @brief Checks if the magnitude of the current instance vector is less than the magnitude of the given parameter vector.
         * 
         * @param other The vector that will be compared by lenght with the current instance object.
         */
        bool isLessThan(const Vector2& other) const;

        /**
         * @brief Checks if the magnitude of the current instance vector is greater than the magnitude of the given parameter vector.
         */
        bool isGreaterThan(const Vector2& other) const;

        /**
         * @brief Checks if the current instance object is the null vector.
         * 
         * @return bool true If the current instance vector is null (0, 0).
         * @return bool false If any coordinate of the current instance vector is not 0.
         */
        bool isNull() const;

        // Object modifier methods

        /**
         * @brief Changes the current vector coordinates.
         * 
         * This method is a setter for x and y.
         * 
         * @param x The new value of x.
         * @param y The new value of y.
         * 
         * @returns Vector2& A refference to the current object.
         */
        Vector2& moveTo(const float x,const float y);

        /**
         * @brief Normalizes the current vector.
         * 
         * Vector normalization is the process of scaling a vector to have a unit length (magnitude of 1) while maintaining its direction.
         * 
         * @returns Vector2& A refference to the current object.
         */
        Vector2& normalize();

        /**
         * @brief Rotates the current vector.
         * 
         * The rotation is performed in trigonometric sense (counterclockwise).
         * 
         * @param angleRadians The angle of the rotation, in radians
         * 
         * @returns Vector2& A reference to the normalized object.
         */
        Vector2& rotateBy(float angleRadians);

        /**
         * @brief Scales the current vector by a given factor.
         * 
         * This method multiplies both components of the vector by the specified scalar,
         * effectively changing its magnitude while maintaining its direction.
         * 
         * @param scalar The factor by which to scale the vector.
         * 
         * @returns Vector2& A reference to the scaled vector.
         */
        Vector2& scaleBy(float scalar);

        /**
         * @brief Adds a vector to the current vector.
         * 
         * This method adds two vectors component by component and stores the result in the current instance object.
         * 
         * @param other The vector that will be added to the current instance vector.
         * 
         * @returns Vector2& A reference to the modified current object.
         */
        Vector2& add(const Vector2& other);

        /**
         * @brief Subtracts a vector from the current vector
         * 
         * This method subtracts the components of a given vector from the components of this vector.
         * 
         * @param other The vector that will be added to the current instance vector.
         * 
         * @returns Vector2& A reference to the modified current object.
         */
        Vector2& subtract(const Vector2& other);

        /**
         * @brief Computes the cache fields that are not memoized.
         * 
         * @returns Vector2& A refference to the current object.
         */
        Vector2& precompute();

        // ==============================
        //      Operators
        // ==============================

        /**
         * @brief Checks for equality between two vectors. 
         * 
         * This operator checks if the components of two vectors are equal.
         * Internally, it uses the isEqual() method to perform the comparison.
         * 
         * @param other The vector to compare with.
         * @return true If the vectors are equal.
         * @return false Otherwise.
         * 
         * @see isEqual() For more details about the equality check.
         */
        bool operator ==(const Vector2& other) const;

        /**
         * @brief Checks for inequality between two vectors.
         * This operator checks if the components of two vectors are not equal.
         * Internally, it uses the isEqual() method to perform the comparison.
         * 
         *  @param other The vector to compare with.
         *  @return true If the vectors are not equal.
         *  @return false Otherwise.
         * 
         * @see isEqual() For more details about the equality check.
         */
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