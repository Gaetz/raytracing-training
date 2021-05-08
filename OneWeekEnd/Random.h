#ifndef RANDOM_H
#define RANDOM_H

#include <functional>
#include <random>

inline double randomDouble() {
    static std::uniform_real_distribution<double> distribution(0.0, 1.0);
    static std::mt19937 generator;
    static std::function<double()> randGenerator = std::bind(distribution, generator);
    return randGenerator();
}

#endif // RANDOM_H