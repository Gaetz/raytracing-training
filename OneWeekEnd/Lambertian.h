#ifndef LAMBERTIAN_H
#define LAMBERTIAN_H

#include "Material.h"

class Lambertian : public Material {
public:
    Lambertian(const Vec3& albedoP) : albedo(albedoP) {}
    bool scatter(const Ray& rIn, const HitRecord& rec, Vec3& attenuation, Ray& scattered) const override;

    Vec3 albedo;
};

#endif