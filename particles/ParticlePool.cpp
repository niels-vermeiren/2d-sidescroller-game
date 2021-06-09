//
// Created by niels on 08.06.21.
//

#include "ParticlePool.h"

void ParticlePool::addParticle(Entity *entity) {
    particles.push_back(entity);
}

std::vector<Entity *> ParticlePool::getParticles() {
    return particles;
}

EntityManager *ParticlePool::getParticleManager() {
    auto * mgr = new EntityManager();
    for(Entity * particle : this->particles) {
        mgr->addEntity(particle);
    }
    return mgr;
}

void ParticlePool::clear() {
    int i= 0;
    while(i!=this->particles.size()) {
        Entity *particle = this->particles[i];
        if (!particle->shouldBeDrawn()) {
            particles.erase(particles.begin() + i);
        } else i++;
    }
}
