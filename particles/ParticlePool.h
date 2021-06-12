//
// Created by niels on 08.06.21.
//

#ifndef INC_2DSIDESCROLLER_PARTICLEPOOL_H
#define INC_2DSIDESCROLLER_PARTICLEPOOL_H


#include <vector>
#include "../entity/Entity.h"
#include "../entity/EntityManager.h"
#include "../entity/PlayerBullet.h"
#include "../observer/EntityObserver.h"

template<typename T>
class ParticlePool : public EntityObserver {

public:
    ParticlePool(){

    }

    void updatePlayerPos(int playerX, int playerY) override {
        for(auto * particle:this->particles) {
            Entity * entity = dynamic_cast<Entity *>(particle);
            if(entity->shouldBeDrawn() && entity->isVisible()) {
                entity->updatePlayerPos(playerX, playerY);
            }
        }
    };

    void addParticle(T t) {
        particles.push_back(t);
    }

    T getFreeParticle() {
        for (auto * particle:this->particles) {
            if(!particle->shouldBeDrawn() || !particle->isVisible()){
                return particle;
            }
        }
        return nullptr;
    }

    std::vector<T> getParticles() {
        return particles;
    }
    EntityManager * getParticleManager() {
        auto * mgr = new EntityManager();
        for(auto * particle : this->particles) {
            mgr->addEntity(dynamic_cast<Entity *>(particle));
        }
        return mgr;
    }

    void clear() {
        int i = PLAYER_BULLET_MIN_POOLSIZE ;
        while(i < particles.size()) {
            auto * particle = particles[i];
            if( !particle->shouldBeDrawn() || !particle->isVisible()){
                particles.erase(particles.begin()+i);
            } else {
                i++;
            }
        }
    }

private:
    std::vector<T> particles;
};


#endif //INC_2DSIDESCROLLER_PARTICLEPOOL_H
