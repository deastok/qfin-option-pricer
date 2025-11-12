#include <iostream>
#include "option_pricing/black_scholes.hpp"

int main() {
    std::cout << "qfin-option-pricer CLI\n";
    std::cout << "Sample European option pricing (Black-Scholes)\n\n";

    const double spot = 100.0;
    const double strike = 105.0;
    const double rate = 0.05;          // 5% annual rate
    const double volatility = 0.20;    // 20% annual volatility
    const double time_to_expiry = 1.0; // 1 year

    const double call_price = option_pricing::black_scholes_call(
        spot, strike, rate, volatility, time_to_expiry
    );

    const double put_price = option_pricing::black_scholes_put(
        spot, strike, rate, volatility, time_to_expiry
    );

    std::cout << "Inputs:\n";
    std::cout << " Spot (S):           " << spot << "\n";
    std::cout << " Strike (K):         " << strike << "\n";
    std::cout << " Rate (r):           " << rate << "\n";
    std::cout << " Volatility (sigma): " << volatility << "\n";
    std::cout << " Time to expiry (T): " << time_to_expiry << " years\n\n";

    std::cout << "Outputs (Black-Scholes):\n";
    std::cout << " Call price: " << call_price << "\n";
    std::cout << " Put price:  " << put_price << "\n";

    return 0;
}