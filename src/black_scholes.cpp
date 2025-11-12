#include <cmath>
#include "option_pricing/black_scholes.hpp"

namespace {

// Standard normal PDF
double normal_pdf(const double x) {
    constexpr double inv_sqrt_2pi = 0.3989422804014327;
    return inv_sqrt_2pi * std::exp(-0.5 * x * x);
}

// Standard normal CDF using std::erf
double normal_cdf(const double x) {
    return 0.5 * (1.0 + std::erf(x / std::sqrt(2.0)));
}

}

namespace option_pricing {

    double black_scholes_call(
        double spot,
        double strike,
        double rate,
        double volatility,
        double time_to_expiry
        ) {
            (void)spot;
            (void)strike;
            (void)rate;
            (void)volatility;
            (void)time_to_expiry;
            return 0.0;
        }

    double black_scholes_put(
        double spot,
        double strike,
        double rate,
        double volatility,
        double time_to_expiry
    ) {
        (void)spot;
        (void)strike;
        (void)rate;
        (void)volatility;
        (void)time_to_expiry;
        return 0.0;
    }

}