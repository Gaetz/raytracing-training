#ifndef DIELECTRIC_H
#define DIELECTRIC_H

#include "Material.h"

class Dielectric : public Material {
public:
    Dielectric(float refractionIndexP) : refractionIndex(refractionIndexP) {}

    bool scatter(const Ray& rIn, const HitRecord& rec, Vec3& attenuation, Ray& scattered) const override;

    float refractionIndex;
};

#endif