#include <iostream>
#include <vector>

#include "mergesort.h"
#include "sound.h"

using namespace std;

int main(void) {

    srand((unsigned int)time(NULL));

    Window myWindow(800, 600, "Mergesort");
    Canvas canvas(&myWindow);
    Sound sound("./sound.wav");

    std::vector<Pillar*> pillars;
    pillars.reserve(PILLAR_MAX_NUMBER_OF_PILLARS);

    for (unsigned int i = 0; i < PILLAR_MAX_NUMBER_OF_PILLARS; i++)
    {
        float height = (float)(rand() % PILLAR_MAX_HEIGHT);

        Pillar *pillar = new Pillar(height, i);
        pillars.push_back(pillar);
    }

    Mergesort mergesort(&canvas, pillars, &sound);
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