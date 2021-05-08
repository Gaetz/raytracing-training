#ifndef METAL_H
#define METAL_H

#include "Material.h"

class Metal : public Material {
public:
    Metal(const Vec3& albedoP) : albedo(albedoP) {}
    bool scatter(const Ray& rIn, const HitRecord& rec, Vec3& attenuation, Ray& scattered) const override;

    Vec3 albedo;
};

#endif