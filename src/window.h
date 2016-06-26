//
// Created by danilov on 25.6.16..
//

#ifndef MERGESORT_OPENGL_WINDOW_H
#define MERGESORT_OPENGL_WINDOW_H


#include <string>
#include <SDL2/SDL.h>

class Window
{
public:
    Window(int width, int height, const std::string &title);

    void clear(void);

    void refresh(void);

    void set2DPerspective(void);

    void inputHandle(void);

    inline bool isClosed(void)
    { return this->closed; };

    virtual ~Window(void);

protected:

private:
    bool closed;

    int width;
    int height;

    SDL_Window *sdlWindow;
    SDL_GLContext glContext;

    inline void close(void)
    { this->closed = true; }

    inline void open(void)
    { this->closed = false; }
};


#endif //MERGESORT_OPENGL_WINDOW_H
