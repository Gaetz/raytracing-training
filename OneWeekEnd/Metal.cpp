#include "Metal.h"
#include "Random.h"

bool Metal::scatter(const Ray& rIn, const HitRecord& rec, Vec3& attenuation, Ray& scattered) const {
    Vec3 reflected = reflect(unitVector(rIn.direction()), rec.normal);
    scattered = Ray(rec.p, reflected + fuzziness * randomInUnitSphere());
    attenuation = albedo;
    return dot(scattered.direction(), rec.normal) > 0;
}