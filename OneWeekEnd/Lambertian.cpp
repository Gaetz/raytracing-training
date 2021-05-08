#include "Lambertian.h"
#include "Random.h"

bool Lambertian::scatter(const Ray& rIn, const HitRecord& rec, Vec3& attenuation, Ray& scattered) const {
    // Diffuse: light bounces randomly until it is absorbed. This create shadows.
    Vec3 target = rec.p + rec.normal + randomInUnitSphere();
    scattered = Ray(rec.p, target - rec.p);
    attenuation = albedo;
    return true;
}