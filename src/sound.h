//
// Created by danilov on 20.12.16..
//

#ifndef MERGESORT_OPENGL_SOUND_H
#define MERGESORT_OPENGL_SOUND_H

#include <string>
#include <SDL2/SDL.h>

typedef struct
{
    Uint8 *pos;
    Uint32  length;
} AudioData;

class Sound
{
public:
    Sound(const std::string &path);
    void play(void);
    virtual ~Sound(void);
private:
    SDL_AudioSpec wavSpec;
    Uint8 *wavStart;
    Uint32 wavLength;

    SDL_AudioDeviceID audioDevice;

    AudioData audio;
};

#endif //MERGESORT_OPENGL_SOUND_H
