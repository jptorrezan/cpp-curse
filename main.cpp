#include <iostream>
#include <SDL2/SDL.h>
#include <iomanip>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#include "src/Screen.h"
#include "src/Swarm.h"

using namespace std;

#define HEX_SIZE 8
#define SIN_ATUALIZATION_TAX 0.0001

int main(){
    srand(time(NULL));

    
    Screen screen;

    if(!screen.init()){
        cout << "Screen init fails." << endl;
        return 2;
    }
    
    Swarm swarm;

    bool quit = false;
    while(!quit){
        int elapsedTime = SDL_GetTicks();

        unsigned char green = (1+sin(elapsedTime*SIN_ATUALIZATION_TAX))*128;
        unsigned char red = (1+cos(elapsedTime*2*SIN_ATUALIZATION_TAX))*128;
        unsigned char blue = (1+sin(elapsedTime*3*SIN_ATUALIZATION_TAX))*128;
        //Update particles
        //Draw particles
        //Check for msg/events

        const Particle * const pParticles = swarm.getPaticles();
        int x, y;
        swarm.update();
        for(int i = 0; i < Swarm::N_PARTICLES; i++){
            Particle particle = pParticles[i];
            x = (particle.m_x + 1)*Screen::SCREEN_WIDTH/2;
            y = (particle.m_y + 1)*Screen::SCREEN_HEIGHT/2;

            screen.setPixel(x, y, red,green,blue);
        }
        screen.update();
        screen.clear();
        if(!screen.processEvents()){
            break;
        }
    }

    screen.close();
    return 0;

}