#include "geometry/internal/common.hpp"
#include "geometry/utils.hpp"
#include "geometry/functions.hpp"


constexpr bool geometry::floatEq(float f1, float f2)
{
    return geometry::abs(f1 - f2) < FLOAT_EPSILON;
}