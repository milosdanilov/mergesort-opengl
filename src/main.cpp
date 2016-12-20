#include <iostream>
#include <vector>

#include "mergesort.h"

using namespace std;

int main(void) {

    srand((unsigned int)time(NULL));

    Window myWindow(800, 600, "Mergesort");

    Canvas canvas(&myWindow);

    std::vector<Pillar*> pillars;
    pillars.reserve(100);
    for (unsigned int i = 0; i < 100; i++)
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