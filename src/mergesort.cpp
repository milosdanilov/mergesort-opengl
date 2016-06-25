//
// Created by danilov on 25.6.16..
//

#include "mergesort.h"

void Mergesort::sort() { }

std::vector<int> Mergesort::merge(const std::vector<int> &left, const std::vector<int> &right)
{
    unsigned int leftIndex = 0;
    unsigned int rightIndex = 0;

    std::vector<int> result;

    while (leftIndex < left.size() && rightIndex < right.size())
    {
        if (left.at(leftIndex) <= right.at(rightIndex))
        {
            result.push_back(left.at(leftIndex));
            leftIndex++;
        }
        else
        {
            result.push_back(right.at(rightIndex));
            rightIndex++;
        }
    }

    while (leftIndex < left.size())
    {
        result.push_back(left.at(leftIndex));
        leftIndex++;
    }

    while (rightIndex < right.size())
    {
        result.push_back(right.at(rightIndex));
        rightIndex++;
    }

    return result;
}

void Mergesort::mergeSort() { }