//
// Created by niels on 08.06.21.
//

#ifndef INC_2DSIDESCROLLER_PARTICLEPOOL_H
#define INC_2DSIDESCROLLER_PARTICLEPOOL_H


#include <vector>
#include "../entity/Entity.h"
#include "../entity/EntityManager.h"

class ParticlePool {

public:
    void addParticle(Entity * entity);
    std::vector<Entity *> getParticles();
    EntityManager * getParticleManager();
    void clear();

private:
    std::vector<Entity *> particles;
};


#endif //INC_2DSIDESCROLLER_PARTICLEPOOL_H
