#include <iostream>
#include <vector>
#include <chrono>
#include <zconf.h>
#include "mergesort.h"

using namespace std;

int main() {

    pid_t pid = getpid();
    std::cout << "PID: " << pid << std::endl;

    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();

    vector<float> unsortedList;
    unsortedList.reserve(100);

    // TODO - add a proper func for seed randomization
    srand ( time(NULL) );
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
    pillars = mergesort.sort();

    std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();

    std::cout << duration << std::endl;

    while (! myWindow.isClosed())
    {
        // Redrawing of the pillars until window closes.
        // This reduces the stress on CPU, why ?
        mergesort.draw();
        myWindow.inputHandle();
    }

    return 0;
}