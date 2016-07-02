//
// Created by danilov on 2.7.16..
//

#include "canvas.h"

void Canvas::setCanvasRanges(GLint x, GLint y, GLsizei width, GLsizei height)
{
    glViewport(x, y, width, height);
}