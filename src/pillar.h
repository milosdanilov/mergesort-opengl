//
// Created by danilov on 26.6.16..
//

#ifndef MERGESORT_OPENGL_PILLAR_H
#define MERGESORT_OPENGL_PILLAR_H


#include <GL/glew.h>

class Pillar
{
public:
    Pillar(float height);

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

    static const short maxNumOfPillars = 100;
    static constexpr GLfloat spaceBetweenPillars = 0.0f;

    static short numOfPillars;
};


#endif //MERGESORT_OPENGL_PILLAR_H
