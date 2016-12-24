//
// Created by danilov on 26.6.16..
//

#ifndef MERGESORT_OPENGL_PILLAR_H
#define MERGESORT_OPENGL_PILLAR_H

#include <GL/glew.h>

#define PILLAR_MAX_NUMBER_OF_PILLARS    100
#define PILLAR_MAX_HEIGHT               400

class Pillar
{
public:
    Pillar(float height, int num);

    void draw(GLfloat red, GLfloat green, GLfloat blue);

    inline GLfloat getHeight(void)
    { return this->height; };

    inline void setHeight(GLfloat height)
    { this->height = height; };

    virtual ~Pillar() {};
protected:
private:
    GLfloat xPos;
    GLfloat yPos;
    GLfloat height;
    GLfloat width;
};


#endif //MERGESORT_OPENGL_PILLAR_H
