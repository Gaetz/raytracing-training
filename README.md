# raytracing-training
The goal of this lesson is to code a CPU raytracer. We will use CMake to compile the project and output a .ppm image file.

## Using CMake to compile

On windows, install Cmake latest release, with PATH : https://cmake.org/download/ . It should already be installed at school. You can test it by opening a terminal and type `cmake`.

We will use Visual Studio Code to compile and build. Follow these steps:
- Make sure the C++ and CMake Tools extensions are installed. 
- Create a folder for your project. Open the folder with Visual Code.
- In the folder, create a `main.cpp` file with a simple program.
- Create a `CMakeLists.txt` file at the root of your folder. This file is the CMake configuration It must contains:

```
cmake_minimum_required(VERSION 3.15)
project(ProjectName)

set(CMAKE_CXX_STANDARD 14)

add_executable(ProjectName main.cpp) 
```

- Use Ctrl + Shift + P do open the command palette. Find and execute Cmake: Configure. It will create a `build` folder.
- When configure is done, press F7 to compile.
- Press F5 to ask for execution. Visual Code should tell you you must create a `launch.json` file. Do it choosing C++ Windows, if under windows.
- In the `launch.json` file, change the program line to fit your path. For oinstance: `"program": "build/Debug/ProjectName.exe",`
- You can add other file to compile by completing the add!executable command. For instance: 

```
add_executable(OneWeekEnd main.cpp Vec3.h Ray.h Hittable.h Sphere.cpp Sphere.h HittableList.cpp HittableList.h)
```
- Run F5 again

You have an example project on https://github.com/Gaetz/raytracing-training

## Reading the ppm output

Our raytracing program won't display immediatly the generated image. It will rather create a .ppm file. 

Yo read this file, add the TinyViewer extension in Visual Code.

## Raytracing course

You are supposed to use the first document of this serie. You can go further if you want.

https://drive.google.com/drive/u/1/folders/1BoZR6BBK02JPAn1Fh9BGOIhDSaBw_sSY