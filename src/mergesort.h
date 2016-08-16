//
// Created by danilov on 25.6.16..
//

#ifndef MERGESORT_OPENGL_MERGESORT_H
#define MERGESORT_OPENGL_MERGESORT_H

#include <vector>
#include "pillar.h"
#include "canvas.h"

class Mergesort
{
public:
    Mergesort(Canvas *canvas, std::vector<Pillar*> *pillars)
    {
        this->canvas = canvas;
        this->pillars = pillars;
    };

    void draw(void);

    virtual ~Mergesort() {};

    std::vector<Pillar*> sort();
protected:
    std::vector<Pillar*> merge(const std::vector<Pillar*> &left, const std::vector<Pillar*> &right);
    std::vector<Pillar*> mergeSort(const std::vector<Pillar*> &pillars);

private:
    Canvas *canvas;
    std::vector<Pillar*> *pillars;
};

#endif //MERGESORT_OPENGL_MERGESORT_H
