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




int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}