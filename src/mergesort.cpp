//
// Created by danilov on 25.6.16..
//

#include "mergesort.h"

std::vector<Pillar*> Mergesort::sort()
{
    // TODO - find a clean way to pass a vector reference of pointers
    return this->mergeSort(*this->pillars);
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
//            glColor3f(1.0f, 0.0f, 0.0f);
//
//            glBegin(GL_TRIANGLE_FAN);
//
//            glVertex2f(left.at(leftIndex)->xPos, left.at(leftIndex)->yPos);
//            glVertex2f(left.at(leftIndex)->xPos + left.at(leftIndex)->width, left.at(leftIndex)->yPos);
//            glVertex2f(left.at(leftIndex)->xPos + left.at(leftIndex)->width, left.at(leftIndex)->yPos - left.at(leftIndex)->height);
//            glVertex2f(left.at(leftIndex)->xPos, left.at(leftIndex)->yPos - left.at(leftIndex)->height);
//
//            glEnd();
//
//            this->canvas->update();
//
//            this->drawPillars();

            heights.push_back(left.at(leftIndex)->getHeight());
            leftIndex++;
        }
        else
        {
//            glColor3f(1.0f, 0.0f, 0.0f);
//
//            glBegin(GL_TRIANGLE_FAN);
//
//            glVertex2f(right.at(rightIndex)->xPos, right.at(rightIndex)->yPos);
//            glVertex2f(right.at(rightIndex)->xPos + right.at(rightIndex)->width, right.at(rightIndex)->yPos);
//            glVertex2f(right.at(rightIndex)->xPos + right.at(rightIndex)->width, right.at(rightIndex)->yPos - right.at(rightIndex)->height);
//            glVertex2f(right.at(rightIndex)->xPos, right.at(rightIndex)->yPos - right.at(rightIndex)->height);
//
//            glEnd();
//
//            this->canvas->update();
//
//            this->drawPillars();

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

    for (unsigned int i = 0; i < result.size(); i++)
    {
        result.at(i)->setHeight(heights.at(i));

        this->draw();
    }

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

void Mergesort::draw()
{
    this->canvas->clear();

    for (unsigned int i = 0; i < this->pillars->size(); i++)
    {
        pillars->at(i)->draw();
    }

    this->canvas->update();
}