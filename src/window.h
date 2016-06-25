//
// Created by danilov on 25.6.16..
//

#ifndef MERGESORT_OPENGL_WINDOW_H
#define MERGESORT_OPENGL_WINDOW_H


#include <string>

class Window
{
public:
    Window(unsigned short width, unsigned short height, const std::string &title);

    void clear(void);

    void refresh(void);

    inline bool isClosed(void)
    { return this->closed; };

    virtual ~Window(void);

protected:
private:
    bool closed;
    SDL_Window *sdlWindow;
};


#endif //MERGESORT_OPENGL_WINDOW_H
