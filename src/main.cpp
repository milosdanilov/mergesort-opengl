#include <iostream>
#include <vector>
#include "mergesort.h"
#include "window.h"
#include "pillar.h"

using namespace std;

int main() {

    vector<float> unsortedList;
    unsortedList.reserve(100);

    for (int i = 0; i < 100; i++)
    {
        float height = (float)(rand() % (600 - 200));
        unsortedList.push_back(height);
    }

    vector<int> sortedList;

//    cout << "START" << endl;
//
//    for (unsigned int i = 0; i < unsortedList.size(); i++)
//    {
//        cout << unsortedList.at(i) << " ";
//    }
//    cout << endl;
//
//    for (unsigned int i = 0; i < sortedList.size(); i++)
//    {
//        cout << sortedList.at(i) << " ";
//    }
//    cout << endl;
//
//    cout << "END" << endl;

    Window myWindow(800, 600, "Mergesort");
    myWindow.set2DPerspective();

    std::vector<Pillar*> pillars;
    for (unsigned int i = 0; i < unsortedList.size(); i++)
    {
        Pillar *pillar = new Pillar(unsortedList.at(i));
        pillars.push_back(pillar);
    }

    Mergesort mergesort(&myWindow);
    pillars = mergesort.sort(pillars);

    while (! myWindow.isClosed())
    {
//        myWindow.clear();
//
//        for (unsigned int i = 0; i < unsortedList.size(); i++)
//        {
//            pillars.at(i)->draw();
//        }
//
//        myWindow.refresh();

        myWindow.inputHandle();
    }

    return 0;
}