#include "Dielectric.h"
#include "Random.h"

bool Dielectric::scatter(const Ray& rIn, const HitRecord& rec, Vec3& attenuation, Ray& scattered) const {
    Vec3 outwardNormal;
    Vec3 reflected = reflect(rIn.direction(), rec.normal);
    float niOverNt;
    attenuation = Vec3(1.0, 1.0, 1.0);
    Vec3 refracted;
    float reflectProbability;
    float cosine;

    if(dot(rIn.direction(), rec.normal) > 0) {
        outwardNormal = -rec.normal;
        niOverNt = refractionIndex;
        cosine = refractionIndex * dot(rIn.direction(), rec.normal) / rIn.direction().length();
    } else {
        outwardNormal = rec.normal;
        niOverNt =  1.0 / refractionIndex;
        cosine = -dot(rIn.direction(), rec.normal) / rIn.direction().length();
    }

    if(refract(rIn.direction(), outwardNormal, niOverNt, refracted)) {
        reflectProbability = schlick(cosine, refractionIndex);
    } else {
        reflectProbability = 1.0;
    }

    if(randomDouble() < reflectProbability) {
        scattered = Ray(rec.p, reflected);
    } else {
        scattered = Ray(rec.p, refracted);
    }

    return true;
}