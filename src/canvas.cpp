//
// Created by danilov on 2.7.16..
//

#include "canvas.h"

Canvas::Canvas(Window *window)
{
    this->window = window;
    this->setCanvasSize(0, 0, this->window->getWidth(), this->window->getHeight());
}

void Canvas::setCanvasSize(GLint x, GLint y, GLsizei width, GLsizei height)
{
    glViewport(x, y, width, height);
}
