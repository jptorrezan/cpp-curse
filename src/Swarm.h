#ifndef SWARM_H_
#define SWARM_H_

#include "Particle.h"

class Swarm{
public:
    const static int N_PARTICLES = 5000;
private:
   Particle* m_pParticles;
   int lastTime;

public:
    Swarm();
    virtual ~Swarm();
    const Particle* const getPaticles(){ return m_pParticles; }
    void update(int elapsed_time);

};




#endif