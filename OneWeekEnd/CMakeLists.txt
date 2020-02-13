cmake_minimum_required(VERSION 3.15)
project(OneWeekEnd)

set(CMAKE_CXX_STANDARD 14)

add_executable(OneWeekEnd main.cpp Vec3.h Ray.h Hittable.h Sphere.cpp Sphere.h HittableList.cpp HittableList.h)