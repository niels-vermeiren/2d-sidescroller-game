//
// Created by niels on 08.06.21.
//

#include "ParticlePool.h"

void ParticlePool::addParticle(Entity *entity) {
    for(Entity * particle : this->particles) {
        if (!particle->isShouldDraw()) {
            particle->clone(entity->getDirection(), entity->getRect());
            return;
        }
    }
    particles.push_back(entity);
}

std::vector<Entity *> ParticlePool::getParticles() {
    return particles;
}

void ParticlePool::clear() {
    for(Entity * particle : this->particles) {
        if (particle->isShouldDraw()) {
            return;
        }
    }
    particles.clear();
}

EntityManager *ParticlePool::getParticleManager() {
   auto * mgr = new EntityManager();
    for(Entity * particle : this->particles) {
        mgr->addEntity(particle);
    }
    return mgr;
}
