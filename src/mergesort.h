//
// Created by danilov on 25.6.16..
//

#ifndef MERGESORT_OPENGL_MERGESORT_H
#define MERGESORT_OPENGL_MERGESORT_H

#include <vector>

class Mergesort
{
public:
    Mergesort() {};
    virtual ~Mergesort() {};

    void sort();
protected:
    std::vector<int> merge(const std::vector<int> &left, const std::vector<int> &right);
    void mergeSort();
private:

};

#endif //MERGESORT_OPENGL_MERGESORT_H