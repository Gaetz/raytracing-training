#ifndef CAMERA_H
#define CAMERA_H

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#include "Ray.h"
#include "Random.h"

Vec3 randomInUnitDisk() {
    Vec3 p;
    do {
        p = 2.0 * Vec3(randomDouble(), randomDouble(), 0.0) - Vec3(1, 1, 0);
    } while (dot(p, p) >= 1.0);
    return p;
}

class Camera {
public:
    Camera() : origin(Vec3(0.0, 0.0, 0.0)),
                lowerLeftCorner(Vec3(-2.0, -1.0, -1.0)),
                horizontal(Vec3(4.0, 0.0, 0.0)),
                vertical(Vec3(0.0, 2.0, 0.0))
    {}

    Camera(Vec3 lookFrom, Vec3 lookAt, Vec3 vUp, float vfov, float aspect, float aperture, float focusDistance) {
        // vfov is top to bottom in degrees
        lensRadius = aperture / 2;
        float theta = vfov * M_PI / 180;
        float halfHeight = tan(theta/2);
        float halfWidth = aspect * halfHeight;
        origin = lookFrom;
        w = unitVector(lookFrom - lookAt);
        u = unitVector(cross(vUp, w));
        v = cross(w, u);

        lowerLeftCorner = origin - halfWidth * u - halfHeight * v - focusDistance * w;
        horizontal = 2 * halfWidth * focusDistance * u;
        vertical = 2 * halfHeight * focusDistance * v;
    }

    Ray getRay(float s, float t) {
        Vec3 rd = lensRadius * randomInUnitDisk();
        Vec3 offset = u * rd.x() + v * rd.y();
        return Ray(origin + offset, lowerLeftCorner + s*horizontal + t*vertical - origin - offset);
    }

    Vec3 origin;
    Vec3 lowerLeftCorner;
    Vec3 horizontal;
    Vec3 vertical;
    Vec3 u, v, w;
    float lensRadius;
};

#endif