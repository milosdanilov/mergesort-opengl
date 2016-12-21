#include <iostream>
#include <vector>
//#include <audiere.h>

#include "mergesort.h"
//#include "sound.h"

using namespace std;
//using namespace audiere;

int main(void) {
//
//    Sound sound("./sound.wav");
//    sound.setPitchShift(24000);
//    sound.play();

//    AudioDevicePtr device(OpenDevice(NULL));
//
//    if (!device) {
//        std::cerr << "OpenDevice() failed" << std::endl;
//        return EXIT_FAILURE;
//    }
//
//    OutputStreamPtr stream(OpenSound(device, "./sound.wav", false));
//
//    if (!stream) {
//        std::cerr << "OpenSound() failed" << std::endl;
//        return EXIT_FAILURE;
//    }
//
//    stream->play();

    srand((unsigned int)time(NULL));

    Window myWindow(800, 600, "Mergesort");

    Canvas canvas(&myWindow);

    std::vector<Pillar*> pillars;
    pillars.reserve(PILLAR_MAX_NUMBER_OF_PILLARS);
    for (unsigned int i = 0; i < PILLAR_MAX_NUMBER_OF_PILLARS; i++)
    {
        float height = (float)(rand() % (600 - 200));

        Pillar *pillar = new Pillar(height, i);
        pillars.push_back(pillar);
    }

    Mergesort mergesort(&canvas, &pillars);
    pillars = mergesort.sort();

    while (! myWindow.isClosed())
    {
        // TODO - implement state machine drawing ?
        mergesort.draw();
        myWindow.inputHandle();
    }

    for (unsigned int i = 0; i < pillars.size(); i++)
    {
        delete(pillars.at(i));
    }
    pillars.clear();

    return 0;
}