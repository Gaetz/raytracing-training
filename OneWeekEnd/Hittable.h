#ifndef HITTABLE_H
#define HITTABLE_H

#include "Ray.h"

class Material;

struct HitRecord {
    float t;
    Vec3 p;
    Vec3 normal;
    Material* material;
};

class Hittable {
public:
    virtual bool hit(
            const Ray& r,
            float tMin,
            float tMax,
            HitRecord& rec
    ) const = 0;
};

#endif //HITTABLE_H
