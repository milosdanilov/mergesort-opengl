# mergesort-opengl

This project visually presents the Mergesort sorting algorithm.
Uses OpenGL for rendering, SLD2 and Audiore libs for window and sound respectively.

![mergesort-animated](mergesort.gif)

## Installation
```
$ git clone <this repo>

$ cmake .
$ make
```

## Running
Because Audiore uses PulseAudio OSS to play sounds, running program on it's own will not start on Ubuntu, because of the removed /dev/dsp.
For programs that still use OSS-style /dev/dsp, you can emulate it with padsp:
```
$ padsp ./Mergesort_OpenGL
```

This is a quick-fix, until i find some better solution.
