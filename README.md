# qfin-option-pricer

A C++ lab for exploring quant finance through option pricing.

Current implementations:
- Standard normal distribution helpers (PDF / CDF)
- Black-Scholes closed-form pricing for European call and put options
- A sample CLI that prints a hard-coded European option scenario
- Basic sanity tests
- CMake build

---

## Build Instructions

### Prereqs
- C++20-compatible compiler (`g++`, `clang++`, or MSVC)
- CMake $\ge$ 4.0
- Git


```
mkdir -p build
cd build
cmake ..
cmake --build .
```

---

## Future
- Interactive CLI
- Greeks
- Implied volatility
- Monte Carlo pricing