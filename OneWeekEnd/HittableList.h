//
// Created by gaetz on 14/02/2020.
//

#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H

#include "Hittable.h"

class HittableList : public Hittable {
public:
    HittableList() {}

    HittableList(Hittable **l, int n) {
        list = l;
        listSize = n;
    }

    virtual bool hit(const Ray &r, float tMin, float tMax, HitRecord &rec) const;

    Hittable **list;
    int listSize;
};


#endif //HITTABLE_LIST_H
