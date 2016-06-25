//
// Created by danilov on 25.6.16..
//

#include <SDL2/SDL.h>
#include "window.h"

Window::Window(unsigned short width, unsigned short height, const std::string &title) {

    SDL_Init(SDL_INIT_VIDEO);

    this->sdlWindow = SDL_CreateWindow(title.c_str(),
                                       SDL_WINDOWPOS_CENTERED,
                                       SDL_WINDOWPOS_CENTERED,
                                       width,
                                       height,
                                       SDL_WINDOW_OPENGL
    );

    this->closed = false;
}

Window::~Window(void) {

    this->closed = true;

    SDL_DestroyWindow(this->sdlWindow);
    SDL_Quit();

    delete this;
}
