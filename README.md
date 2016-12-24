# <!-- Ascending Sorting icon by Icons8 --><img class="icon icons8-Ascending-Sorting" src="data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAADQAAAA0CAYAAADFeBvrAAACKElEQVRoQ+2Z/TUEMRTF71aAClABKkAFdIAK6AAdUAEqcFSwtgJUgApQAec6M3t2s0nmJZO3k8xO/p7Zeb/3efN2hJ6dUc94MADlHlFG6ADAHYAth7EfAM4APOcOQ/sI9O6BqRkItV0K0K/Q0CLqjUYOQMKIdvJYLyP0DWCtwZ2fgsbRSUTMj9Zt+x7ApsMiwpyW1Laz8KzHCM7Ho2pe8jHOwwcAzKyFU0Ir/gKwblj+BOC4RKBdAC8WwxmdjRKBKMvGjnS0ZpdEy7nSexkaLwpIouV8UJoaLwpIKn1cUJqNZaWA9gC82gZrqRE6tA37EC3XRcpRofDyaTtOIImWc8Foa7wrAJehQCw8n5bzwWhrvCignLXcSgFdAyDw3NGcISki74tQkUA3AM4dnnECNe3lQj2dUuPx7rMfCtRGy2lrPB/QZObSN7UjxWBNNXBZL2Y0eB8yL3f19zg/TekzyQmIqeraa0jTPisgXqkfpZa71ENOEaKNVCwnkVC3AC4I1EbLaWg81sVOINS0QUj2coG/jbZ7PDYBQknr6a3qdv9rrVyVArsbW3bTRven2uhOd3S5AtHZTVCEoSiYa905A/mgrDA5p9xs3ZqRYs3wHrawT6iBUms5nxyK/a+W+222dB7OK+teuwbS0HLaGs/ZeTUHayqNFzQ2BqAgd9kfVu2svYyQhpbT0Hii5NDQcj4Y7T1etlpOFA3bQ6oFGm1VixcHoBbOW8qrf69AdLWZbaT5AAAAAElFTkSuQmCC" width="48" height="48"> mergesort-opengl

This project visually presents the Mergesort sorting algorithm.
Uses OpenGL for rendering, SLD2 and Audiore libs for window and sound respectively.

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
