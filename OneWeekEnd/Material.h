#ifndef MATERIAL_H
#define MATERIAL_H

#include "Ray.h"
#include "Hittable.h"

class Material {
public:
    virtual bool scatter(const Ray& rIn, const HitRecord& rec, Vec3& attenuation, Ray& scattered) const = 0;
};


#endif