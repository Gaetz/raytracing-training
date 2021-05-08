#include <iostream>
#include <fstream>
#include <limits>
#include <array>

#include "HittableList.h"
#include "Sphere.h"
#include "Camera.h"
#include "Random.h"

using std::array;

float MAX_FLOAT = std::numeric_limits<float>::max();

Vec3 color(const Ray &r, Hittable *world) {
    HitRecord rec;
    if (world->hit(r, 0.001, MAX_FLOAT, rec)) {
        // Diffuse: light bounces randomly until it is absorbed. This create shadows.
        Vec3 target = rec.p + rec.normal + randomInUnitSphere();
        return 0.5 * color(Ray(rec.p, target - rec.p), world);
    } else {
        // Display the sky
        Vec3 unitDirection = unitVector(r.direction());
        float t = 0.5 * (unitDirection.y() + 1.0);
        return (1.0 - t) * Vec3(1.0, 1.0, 1.0) + t * Vec3(0.5, 0.7, 1.0);
    }
}

int main() {
    std::ofstream output;
    output.open("output.ppm");

    int nx = 200;
    int ny = 100;
    int ns = 100;   // Number of samples
    output << "P3\n" << nx << " " << ny << "\n255\n";

    Hittable* list[2];
    list[0] = new Sphere(Vec3(0, 0, -1), 0.5);
    list[1] = new Sphere(Vec3(0, -100.5, -1), 100);
    Hittable* world = new HittableList(list, 2);
    Camera camera;

    for (int j = ny - 1; j >= 0; j--) {
        for (int i = 0; i < nx; i++) {

            Vec3 col(0, 0, 0);
            // Multi-sampling for anti aliasing
            for(int s = 0; s < ns; s++) {
                float u = float(i + randomDouble()) / float(nx);
                float v = float(j + randomDouble()) / float(ny);
                Ray r = camera.getRay(u, v);
                col += color(r, world);
            }
            col /= float(ns);

            // Use Gamma 2
            col = Vec3(sqrt(col[0]), sqrt(col[1]), sqrt(col[2]));

            // Output color in file
            int ir = int(255.99 * col[0]);
            int ig = int(255.99 * col[1]);
            int ib = int(255.99 * col[2]);

            output << ir << " " << ig << " " << ib << "\n";
        }
    }

    output.close();
    return 0;
}
