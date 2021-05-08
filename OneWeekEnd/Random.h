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

inline Vec3 randomInUnitSphere() {
    Vec3 p;
    do {
        p = 2.0 * Vec3(randomDouble(), randomDouble(), randomDouble()) - Vec3(1, 1, 1);
    } while (p.squaredLength() >= 1.0);
    return p;
}

#endif // RANDOM_H