#include <iostream>
#include <fstream>
#include <limits>
#include <array>

#include "HittableList.h"
#include "Sphere.h"
#include "Camera.h"
#include "Random.h"
#include "Lambertian.h"
#include "Metal.h"
#include "Dielectric.h"

using std::array;

float MAX_FLOAT = std::numeric_limits<float>::max();

Vec3 color(const Ray &r, Hittable *world, int depth) {
    HitRecord rec;
    if (world->hit(r, 0.001, MAX_FLOAT, rec)) {
        Ray scattered;
        Vec3 attenuation;
        if(depth < 50 && rec.material->scatter(r, rec, attenuation, scattered)) {
            return attenuation * color(scattered, world, depth+1);
        } else {
            return Vec3(0, 0, 0);
        }
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

    Vec3 lookFrom { -1, 2, 3 };
    Vec3 lookAt { -1, 0, 0 };
    float distToFocus = (lookFrom - lookAt).length();
    float aperture = 0.1;

    Hittable* list[5];
    list[0] = new Sphere(Vec3(0, 0, -1), 0.5, new Lambertian(Vec3(0.8, 0.3, 0.3)));
    list[1] = new Sphere(Vec3(0, -100.5, -1), 100, new Lambertian(Vec3(0.8, 0.8, 0.0)));
    list[2] = new Sphere(Vec3(1, 0, -1), 0.5, new Metal(Vec3(0.8, 0.6, 0.2), 0.3f));
    list[3] = new Sphere(Vec3(-1, 0, -1), 0.5, new Dielectric(1.5f));
    list[4] = new Sphere(Vec3(-1, 0, -1), -0.45, new Dielectric(1.5f));
    Hittable* world = new HittableList(list, 5);
    Camera camera { lookFrom, lookAt, Vec3(0, 1, 0), 20, float(nx) / float(ny), aperture, distToFocus };

    for (int j = ny - 1; j >= 0; j--) {
        for (int i = 0; i < nx; i++) {

            Vec3 col(0, 0, 0);
            // Multi-sampling for anti aliasing
            for(int s = 0; s < ns; s++) {
                float u = float(i + randomDouble()) / float(nx);
                float v = float(j + randomDouble()) / float(ny);
                Ray r = camera.getRay(u, v);
                col += color(r, world, 0);
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

    // Clean
    for(auto hittable : list) {
        delete hittable;
    }
    output.close();
    return 0;
}
