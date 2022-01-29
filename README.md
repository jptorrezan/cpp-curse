# Particles Swarm Explosion

## Compilation

The compilator used is the g++.
To compile this project is necessary the use of the flag "-lSDL2" because the library SDL2 is used in this project. The reference link can be found [here](https://www.libsdl.org/).
The project have a Makefile, then to compile it you just need to use the next terminal comand:
```console
foo@bar:~$ make all
```

## The project

The projects consists in a window with an particles animation, moving in the screen and changing their colors. Using the SDL2 to make the screen and render the image. There are 3 library files made for this project, Particle.h, Swarm.h and Screen.h the first is the logic behind each Particle that composes the Swarm, this library determines their location in the screen in a way that doenst depends of a fixed screen size, varying from -1 to 1 in the axis X and Y, and 0 corresponds to the center of the screen. Swarm.h have an object with a vector of Particles to keep the encapsulation. Screen.h have an object too, this object group all the necessary screen functions.

## Extra information

This project was developed in a c++ course by caveofprograming.com.