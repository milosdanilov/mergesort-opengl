#include <iostream>
#include <vector>
#include "mergesort.h"

using namespace std;

int main() {

    vector<float> unsortedList;
    unsortedList.reserve(100);

    for (int i = 0; i < 100; i++)
    {
        float height = (float)(rand() % (600 - 200));
        unsortedList.push_back(height);
    }

    Window myWindow(800, 600, "Mergesort");

    Canvas canvas(&myWindow);

    std::vector<Pillar*> pillars;
    for (unsigned int i = 0; i < unsortedList.size(); i++)
    {
        Pillar *pillar = new Pillar(unsortedList.at(i));
        pillars.push_back(pillar);
    }

    Mergesort mergesort(&canvas, &pillars);
    pillars = mergesort.sort(pillars);

    while (! myWindow.isClosed())
    {
        myWindow.inputHandle();
    }

    return 0;
}