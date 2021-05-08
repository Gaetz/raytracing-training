#include "Sphere.h"
#include "Material.h"

Sphere::~Sphere() {
    delete material;
}

bool Sphere::hit(const Ray &r, float tMin, float tMax, HitRecord &rec) const {
    Vec3 oc = r.origin() - center;
    float a = dot(r.direction(), r.direction());
    float b = dot(oc, r.direction());
    float c = dot(oc, oc) - radius * radius;
    float discriminant = b * b - a * c;
    if (discriminant > 0) {
        float temp = (-b - sqrt(discriminant)) / a;
        if (temp < tMax && temp > tMin) {
            rec.t = temp;
            rec.p = r.pointAtParameter(rec.t);
            rec.normal = (rec.p - center) / radius;
            rec.material = material;
            return true;
        }
        temp = (-b + sqrt(discriminant)) / a;
        if (temp < tMax && temp > tMin) {
            rec.t = temp;
            rec.p = r.pointAtParameter(rec.t);
            rec.normal = (rec.p - center) / radius;
            rec.material = material;
            return true;
        }
    }
    return false;
}