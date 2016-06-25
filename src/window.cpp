//
// Created by danilov on 25.6.16..
//

#include <GL/glew.h>
#include <iostream>
#include "window.h"

Window::Window(unsigned short width, unsigned short height, const std::string &title) {

    SDL_Init(SDL_INIT_VIDEO);

    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    this->sdlWindow = SDL_CreateWindow(title.c_str(),
                                       SDL_WINDOWPOS_CENTERED,
                                       SDL_WINDOWPOS_CENTERED,
                                       width,
                                       height,
                                       SDL_WINDOW_OPENGL
    );

    this->glContext = SDL_GL_CreateContext(this->sdlWindow);

    GLenum status = glewInit();
    if (status != GLEW_OK)
    {
        std::cerr << "Failed to initialize GLEW !" << std::endl;
    }


    this->closed = false;
}

Window::~Window(void) {

    this->closed = true;

    SDL_DestroyWindow(this->sdlWindow);
    SDL_Quit();

    delete this;
}
