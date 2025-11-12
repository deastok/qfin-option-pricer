#ifndef QFIN_OPTION_PRICER_BLACK_SCHOLES_H
#define QFIN_OPTION_PRICER_BLACK_SCHOLES_H

namespace option_pricing {

    double black_scholes_call(
        double spot,
        double strike,
        double rate,
        double volatility,
        double time_to_expiry
    );

    double black_scholes_put(
        double spot,
        double strike,
        double rate,
        double volatility,
        double time_to_expiry
    );

}

#endif //QFIN_OPTION_PRICER_BLACK_SCHOLES_H