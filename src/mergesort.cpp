//
// Created by danilov on 25.6.16..
//

#include "mergesort.h"

std::vector<int> Mergesort::sort(const std::vector<int> &list)
{
    return this->mergeSort(list);
}

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

std::vector<int> Mergesort::mergeSort(const std::vector<int> &list)
{
    if (list.size() <= 1)
        return list;

    std::vector<int> left;
    std::vector<int> right;

    unsigned long middle = list.size() / 2;

    for (unsigned long i = 0; i < middle; i++)
    {
        left.push_back(list.at(i));
    }

    for (unsigned long i = middle; i < list.size(); i++)
    {
        right.push_back(list.at(i));
    }

    left = this->mergeSort(left);
    right = this->mergeSort(right);

    return this->merge(left, right);
}
