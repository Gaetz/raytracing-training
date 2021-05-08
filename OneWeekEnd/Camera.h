#ifndef CAMERA_H
#define CAMERA_H

#include "Ray.h"

class Camera {
public:
    Camera() : origin(Vec3(0.0, 0.0, 0.0)),
                lowerLeftCorner(Vec3(-2.0, -1.0, -1.0)),
                horizontal(Vec3(4.0, 0.0, 0.0)),
                vertical(Vec3(0.0, 2.0, 0.0))
    {}

    Ray getRay(float u, float v) {
        return Ray(origin, lowerLeftCorner + u*horizontal + v*vertical - origin);
    }

    Vec3 origin;
    Vec3 lowerLeftCorner;
    Vec3 horizontal;
    Vec3 vertical;
};

#endif