#include <cassert>
#include <iostream>
#include "option_pricing/black_scholes.hpp"

int main() {
    const double spot = 100.0;
    const double strike = 105.0;
    const double rate = 0.05;
    const double volatility = 0.20;
    const double time_to_expiry = 1.0;

    const double call_price = option_pricing::black_scholes_call(
        spot, strike, rate, volatility, time_to_expiry
    );

    const double put_price = option_pricing::black_scholes_put(
        spot, strike, rate, volatility, time_to_expiry
    );

    // sanity checks
    assert(call_price > 0.0);
    assert(put_price > 0.0);
    assert(call_price < spot + 1e-6);
    assert(put_price < strike + 1e-6);

    std::cout << "[TEST] Black-Scholes sanity checks passed.\n";
    return 0;
}