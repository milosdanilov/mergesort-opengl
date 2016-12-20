//
// Created by danilov on 26.6.16..
//

#include "pillar.h"


Pillar::Pillar(float height, int num)
{
    this->height = height;
    this->width = (800 - 20.0f - this->maxNumOfPillars * this->spaceBetweenPillars) / this->maxNumOfPillars;

    this->xPos = 10.0f + num * (this->width + this->spaceBetweenPillars);
//    this->yPos = 600 - 100.0f;
    this->yPos = 600;
}

void Pillar::draw(GLfloat red, GLfloat green, GLfloat blue)
{
    glColor3f(red, green, blue);

    glBegin(GL_TRIANGLE_FAN);

    glVertex2f(this->xPos, this->yPos);
    glVertex2f(this->xPos + this->width, this->yPos);
//    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(this->xPos + this->width, this->yPos - this->height);
    glVertex2f(this->xPos, this->yPos - this->height);

    glEnd();
}