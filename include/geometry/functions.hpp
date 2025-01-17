#pragma once

namespace geometry {

    template <typename Numerical>
    constexpr Numerical abs(Numerical number)
    {
        return (number > 0) ? number : -number;
    }
}