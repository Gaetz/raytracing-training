//
// Created by gaetz on 14/02/2020.
//

#ifndef SPHERE_H
#define SPHERE_H

#include "Hittable.h"

class Sphere : public Hittable {
public:
    Sphere() {}

    Sphere(Vec3 cen, float r) : center(cen), radius(r) {};

    virtual bool hit(const Ray &r, float tmin, float tmax, HitRecord &rec) const;

    Vec3 center;
    float radius;
};

#endif //SPHERE_H
