#ifndef SWARM_H_
#define SWARM_H_

#include "Particle.h"

class Swarm{
public:
    const static int N_PARTICLES = 1000;
private:
   Particle* m_pParticles;

public:
    Swarm();
    virtual ~Swarm();
    const Particle* const getPaticles(){ return m_pParticles; }
    void update();

};




#endif