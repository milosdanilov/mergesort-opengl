//
// Created by danilov on 20.12.16..
//

#ifndef MERGESORT_OPENGL_SOUND_H
#define MERGESORT_OPENGL_SOUND_H

#include <string>
#include <audiere.h>

using namespace audiere;

class Sound
{
public:
    Sound(const std::string &path);
    void playAtPitch(float pitch);
    virtual ~Sound(void){};
private:
    AudioDevicePtr device;
    OutputStreamPtr stream;
};

#endif //MERGESORT_OPENGL_SOUND_H
