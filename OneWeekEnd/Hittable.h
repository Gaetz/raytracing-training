//
// Created by gaetz on 14/02/2020.
//

#ifndef HITTABLE_H
#define HITTABLE_H

#include "Ray.h"

struct HitRecord {
    float t;
    Vec3 p;
    Vec3 normal;
};

class Hittable {
public:
    virtual bool hit(
            const Ray &r,
            float tMin,
            float tMax,
            HitRecord &rec
    ) const = 0;
};

#endif //HITTABLE_H
