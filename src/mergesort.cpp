//
// Created by danilov on 25.6.16..
//

#include "mergesort.h"

std::vector<Pillar*> Mergesort::sort(const std::vector<Pillar*> &pillars)
{
    return this->mergeSort(pillars);
}

std::vector<Pillar*> Mergesort::merge(const std::vector<Pillar*> &left, const std::vector<Pillar*> &right)
{
    unsigned int leftIndex = 0;
    unsigned int rightIndex = 0;

    std::vector<Pillar*> result;

    result.reserve(left.size() + right.size());
    result.insert(result.end(), left.begin(), left.end());
    result.insert(result.end(), right.begin(), right.end());

    std::vector<GLfloat> heights;

    while (leftIndex < left.size() && rightIndex < right.size())
    {
        if (left.at(leftIndex)->getHeight() <= right.at(rightIndex)->getHeight())
        {
            heights.push_back(left.at(leftIndex)->getHeight());
            leftIndex++;
        }
        else
        {
            heights.push_back(right.at(rightIndex)->getHeight());
            rightIndex++;
        }
    }

    while (leftIndex < left.size())
    {
        heights.push_back(left.at(leftIndex)->getHeight());
        leftIndex++;
    }

    while (rightIndex < right.size())
    {
        heights.push_back(right.at(rightIndex)->getHeight());
        rightIndex++;
    }

    this->canvas->clear();

    for (int i = 0; i < heights.size(); i++)
    {
        result.at(i)->setHeight(heights.at(i));
        result.at(i)->draw();
    }

    this->canvas->update();

    return result;
}

std::vector<Pillar*> Mergesort::mergeSort(const std::vector<Pillar*> &pillars)
{
    if (pillars.size() <= 1)
        return pillars;

    std::vector<Pillar*> left;
    std::vector<Pillar*> right;

    unsigned long middle = pillars.size() / 2;

    for (unsigned long i = 0; i < middle; i++)
    {
        left.push_back(pillars.at(i));
    }

    for (unsigned long i = middle; i < pillars.size(); i++)
    {
        right.push_back(pillars.at(i));
    }

    left = this->mergeSort(left);
    right = this->mergeSort(right);

    return this->merge(left, right);
}
