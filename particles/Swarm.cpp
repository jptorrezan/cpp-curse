#include "Swarm.h"

Swarm::Swarm(){

    m_pParticles = new Particle[N_PARTICLES];
}

Swarm::~Swarm(){
    delete m_pParticles;
}