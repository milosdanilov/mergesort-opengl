//
// Created by danilov on 2.7.16..
//

#include "canvas.h"

Canvas::Canvas(Window *window)
{
    this->window = window;

    this->setCanvasSize(0, 0, this->window->getWidth(), this->window->getHeight());
    this->setCanvasRangesOblique(0.0, this->window->getWidth(), this->window->getHeight(), 0.0);
}

void Canvas::setCanvasSize(GLint x, GLint y, GLsizei width, GLsizei height)
{
    glViewport(x, y, width, height);
}

void Canvas::setCanvasRangesOblique(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top)
{
    glOrtho(left, right, bottom, top, -1.0, 1.0);
}

void Canvas::clear()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // set background color
    glClear(GL_COLOR_BUFFER_BIT);
}

void Canvas::update()
{
    this->window->refresh();
    this->window->inputHandle();
}