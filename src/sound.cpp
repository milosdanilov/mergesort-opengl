//
// Created by danilov on 20.12.16..
//

#include "sound.h"
#include <iostream>

static void myAudioCallback(void *data, Uint8 *stream, int streamLength)
{
    AudioData *audio = (AudioData*)data;

    if (audio->length == 0)
    {
        return;
    }

    Uint32 length = streamLength > audio->length
                    ? audio->length
                    : (Uint32)streamLength;

    SDL_memcpy(stream, audio->pos, length);

    audio->pos += length;
    audio->length -= length;
}

Sound::Sound(const std::string &path)
{
    SDL_Init(SDL_INIT_AUDIO);

    if (SDL_LoadWAV(path.c_str(), &this->wavSpec, &this->wavStart, &this->wavLength) == NULL)
    {
        std::cerr << "Error: " << path << " could not be loaded as an audio file!" << std::endl;
        return;
    }

    this->audio.pos = wavStart;
    this->audio.length = wavLength;

    this->wavSpec.callback = myAudioCallback;
    this->wavSpec.userdata = &audio;

    this->audioDevice = SDL_OpenAudioDevice(
            NULL, 0, &this->wavSpec, NULL, SDL_AUDIO_ALLOW_ANY_CHANGE
    );
    if (this->audioDevice == 0)
    {
        std::cerr << "Error: " << SDL_GetError() << std::endl;
        return;
    }
}

void Sound::play()
{
    SDL_PauseAudioDevice(this->audioDevice, 0);
}

Sound::~Sound()
{
    SDL_CloseAudioDevice(this->audioDevice);
    SDL_FreeWAV(this->wavStart);
}
