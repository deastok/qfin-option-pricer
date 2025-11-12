#include <cmath>
#include <algorithm>
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
            if (time_to_expiry <= 0.0 || volatility <= 0.0) {
                const double intrinsic = std::max(spot - strike, 0.0);
                return intrinsic;
            }

        const double sqrtT = std::sqrt(time_to_expiry);
        const double d1 = (std::log(spot / strike)
                           + (rate + 0.5 * volatility * volatility) * time_to_expiry)
                           / (volatility * sqrtT);
        const double d2 = d1 - volatility * sqrtT;

        const double Nd1 = normal_cdf(d1);
        const double Nd2 = normal_cdf(d2);
        const double discount_factor = std::exp(-rate * time_to_expiry);

        return spot * Nd1 - strike * discount_factor * Nd2;
    }

    double black_scholes_put(
        double spot,
        double strike,
        double rate,
        double volatility,
        double time_to_expiry
    ) {
        if (time_to_expiry <= 0.0 || volatility <= 0.0) {
            const double intrinsic = std::max(strike - spot, 0.0);
            return intrinsic;
        }

        const double sqrtT = std::sqrt(time_to_expiry);
        const double d1 = (std::log(spot / strike)
                            + (rate + 0.5 * volatility * volatility) * time_to_expiry)
                            / (volatility * sqrtT);
        const double d2 = d1 - volatility * sqrtT;

        const double discount_factor = std::exp(-rate * time_to_expiry);

        return strike * discount_factor * normal_cdf(-d2)
            - spot * normal_cdf(-d1);
    }

}