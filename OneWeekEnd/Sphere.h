#ifndef SPHERE_H
#define SPHERE_H

#include "Hittable.h"

class Material;

class Sphere : public Hittable {
public:
    Sphere() {}
    virtual ~Sphere();

    Sphere(Vec3 cen, float r, Material* mat) : center(cen), radius(r), material(mat) {};

    virtual bool hit(const Ray &r, float tmin, float tmax, HitRecord &rec) const;

    Vec3 center;
    float radius;
    Material* material;
};

#endif //SPHERE_H
