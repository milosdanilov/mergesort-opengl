#include <iostream>
#include <vector>
#include "mergesort.h"
#include "window.h"

using namespace std;

int main() {

    vector<int> unsortedList = {38, 27, 43, 3, 9, 82, 10};
    vector<int> sortedList;

    cout << "START" << endl;

    for (unsigned int i = 0; i < unsortedList.size(); i++)
    {
        cout << unsortedList.at(i) << " ";
    }
    cout << endl;

    Mergesort mergesort;
    sortedList = mergesort.sort(unsortedList);

    for (unsigned int i = 0; i < sortedList.size(); i++)
    {
        cout << sortedList.at(i) << " ";
    }
    cout << endl;

    cout << "END" << endl;

    Window myWindow(800, 600, "Mergesort");

    while (! myWindow.isClosed())
    {
        myWindow.draw();
        myWindow.inputHandle();
    }

    return 0;
}