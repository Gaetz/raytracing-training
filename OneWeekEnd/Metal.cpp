#include "Metal.h"

bool Metal::scatter(const Ray& rIn, const HitRecord& rec, Vec3& attenuation, Ray& scattered) const {
    Vec3 reflected = reflect(unitVector(rIn.direction()), rec.normal);
    scattered = Ray(rec.p, reflected);
    attenuation = albedo;
    return dot(scattered.direction(), rec.normal) > 0;
}