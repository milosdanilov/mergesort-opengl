//
// Created by danilov on 20.12.16..
//

#include "sound.h"

#include <iostream>

Sound::Sound(const std::string &path)
{
    this->device = OpenDevice();

    if (!this->device) {
        std::cerr << "OpenDevice() failed" << std::endl;
        return;
    }

    this->stream = OpenSound(this->device, "./sound.wav", false);

    if (!this->stream) {
        std::cerr << "OpenSound() failed" << std::endl;
        return;
    }
}

void Sound::playAtPitch(float pitch)
{
    this->stream->reset();
    this->stream->setPitchShift(pitch);
    this->stream->play();
}
