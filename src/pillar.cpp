//
// Created by danilov on 26.6.16..
//

#include "pillar.h"

short Pillar::numOfPillars = 0;

Pillar::Pillar(float height)
{
    this->height = height;
    this->width = (800 - 20.0f - this->maxNumOfPillars * this->spaceBetweenPillars) / this->maxNumOfPillars;

    this->xPos = 10.0f + numOfPillars * (this->width + this->spaceBetweenPillars);
    this->yPos = 600 - 100.0f;

    numOfPillars++;
}

void Pillar::draw()
{
    glColor3f(0.0f, 0.0f, 1.0f);

    glBegin(GL_TRIANGLE_FAN);

    glVertex2f(this->xPos, this->yPos);
    glVertex2f(this->xPos + this->width, this->yPos);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(this->xPos + this->width, this->yPos - this->height);
    glVertex2f(this->xPos, this->yPos - this->height);

    glEnd();
}