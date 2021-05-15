#ifndef CAMERA_H
#define CAMERA_H

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#include "Ray.h"

class Camera {
public:
    Camera() : origin(Vec3(0.0, 0.0, 0.0)),
                lowerLeftCorner(Vec3(-2.0, -1.0, -1.0)),
                horizontal(Vec3(4.0, 0.0, 0.0)),
                vertical(Vec3(0.0, 2.0, 0.0))
    {}

    Camera(Vec3 lookFrom, Vec3 lookAt, Vec3 vUp, float vfov, float aspect) {
        // vfov is top to bottom in degrees
        Vec3 u, v, w;
        float theta = vfov * M_PI / 180;
        float halfHeight = tan(theta/2);
        float halfWidth = aspect * halfHeight;
        origin = lookFrom;
        w = unitVector(lookFrom - lookAt);
        u = unitVector(cross(vUp, w));
        v = cross(w, u);

        lowerLeftCorner = origin - halfWidth * u - halfHeight * v - w;
        horizontal = 2 * halfWidth * u;
        vertical = 2 * halfHeight * v;
    }

    Ray getRay(float s, float t) {
        return Ray(origin, lowerLeftCorner + s*horizontal + t*vertical - origin);
    }

    Vec3 origin;
    Vec3 lowerLeftCorner;
    Vec3 horizontal;
    Vec3 vertical;
};

#endif