#include "geometry/Vector2.hpp"
#include <gtest/gtest.h>
#include <cmath>

#ifndef M_PI_2
#define M_PI_2 1.5707963267948966192313216916398f
#endif

TEST(Vector2Tests, NormalizationTest)
{
    geometry::Vector2 v(60.0f, 78.0f);

    ASSERT_FLOAT_EQ(v.normalized().lenght(), 1.0f);

    v.normalize();
    ASSERT_FLOAT_EQ(v.lenght(), 1.0f);
}

TEST(Vector2Tests, NormalizationOfNullVectorTest)
{
    geometry::Vector2 v(0.0f, 0.0f);

    // Normalizing a null vector (dividing by zero). 
    v.normalize();

    // Making sure that lenght() method doesnt raise an error on a null vector.
    ASSERT_FLOAT_EQ(v.x, 0.0f);
    ASSERT_FLOAT_EQ(v.y, 0.0f);

    ASSERT_FLOAT_EQ(v.lenght(), 0.0f);
}

TEST(Vector2Tests, NormalizationOfNullVectorUsingNormalizedTest)
{
    geometry::Vector2 v(0.0f, 0.0f);

    // The normalized method called on a null vector should return a null vector too, not raising an error
    auto assertVect = v.normalized();

    ASSERT_FLOAT_EQ(assertVect.x, 0.0f);
    ASSERT_FLOAT_EQ(assertVect.y, 0.0f);
    ASSERT_FLOAT_EQ(assertVect.lenght(), 0.0f);
}

TEST(Vector2Tests, AngleBetween2VectorsTest)
{
    // We chose 2 perpendicular vectors.
    geometry::Vector2 v1(0.0, 1.0), v2(1.0, 0.0);

    ASSERT_FLOAT_EQ(M_PI_2, v1.angleBetween(v2));
}

TEST(Vector2Tests, DotProductTest)
{
    geometry::Vector2 v1(3, 4), v2(1, 2);

    // Dot product is 3 * 1 + 4 * 2 = 11
    float rez1 = v1.dot(v2);
    float rez2 = v2.dot(v1);

    // Expected: rez1 == rez2 == 11
    ASSERT_FLOAT_EQ(rez1, rez2); // dot product is comutative
    ASSERT_FLOAT_EQ(rez1, 11.0f);
}

TEST(Vector2Tests, SinAndCosOfNullVect)
{
    geometry::Vector2 v1(0.0f, 0.0f);

    ASSERT_THROW(v1.sinTheta(), std::runtime_error);
    ASSERT_THROW(v1.cosTheta(), std::runtime_error);
}

TEST(Vector2Tests, AngleBetweenNullVect)
{
    geometry::Vector2 nullvect(0.0f, 0.0f), randomvect(65.3f, 8.2f);

    ASSERT_ANY_THROW(nullvect.angleBetween(randomvect));

    ASSERT_ANY_THROW(randomvect.angleBetween(nullvect));
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}