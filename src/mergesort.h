//
// Created by danilov on 25.6.16..
//

#ifndef MERGESORT_OPENGL_MERGESORT_H
#define MERGESORT_OPENGL_MERGESORT_H

#include <vector>
#include "pillar.h"

class Mergesort
{
public:
    Mergesort() {};
    virtual ~Mergesort() {};

    std::vector<Pillar*> sort(const std::vector<Pillar*> &pillars);
protected:
    std::vector<Pillar*> merge(const std::vector<Pillar*> &left, const std::vector<Pillar*> &right);
    std::vector<Pillar*> mergeSort(const std::vector<Pillar*> &pillars);
private:

};

#endif //MERGESORT_OPENGL_MERGESORT_H
