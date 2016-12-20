//
// Created by danilov on 26.6.16..
//

#include "pillar.h"

#define PILLAR_BOTTOM_OFFSET  100.0f
#define PILLAR_LEFT_OFFSET     10.0f
#define PILLAR_SPACE_BETWEEN    1.0f

Pillar::Pillar(float height, int num)
{
    this->height = height;
    this->width = (800 - 20.0f - PILLAR_MAX_NUMBER_OF_PILLARS * PILLAR_SPACE_BETWEEN) / PILLAR_MAX_NUMBER_OF_PILLARS;

    this->xPos = PILLAR_LEFT_OFFSET + num * (this->width + PILLAR_SPACE_BETWEEN);
    this->yPos = 600 - PILLAR_BOTTOM_OFFSET;
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