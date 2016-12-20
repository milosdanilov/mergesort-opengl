//
// Created by danilov on 25.6.16..
//

#include <GL/glew.h>
#include <iostream>
#include "window.h"

#define SDL_SWAP_INTERVAL_IMMEDIATE     0
#define SDL_SWAP_INTERVAL_SYNC          1

Window::Window(int width, int height, const std::string &title)
{
    this->width = width;
    this->height = height;

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


    this->open();
    this->refresh();
}

void Window::refresh()
{
    SDL_GL_SwapWindow(this->sdlWindow);
    SDL_GL_SetSwapInterval(SDL_SWAP_INTERVAL_SYNC);
}

void Window::inputHandle()
{
    if (this->isClosed())
    {
        SDL_Quit();
    }

    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
                this->close();
                break;
            default:
                break;
        }
    }
}

Window::~Window(void)
{
    std::cout << "closing window" << std::endl;

    SDL_GL_DeleteContext(this->glContext);

    SDL_DestroyWindow(this->sdlWindow);
    SDL_Quit();
}
