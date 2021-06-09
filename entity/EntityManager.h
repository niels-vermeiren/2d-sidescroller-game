//
// Created by niels on 4/12/21.
//

#ifndef INC_2DSIDESCROLLER_ENTITYMANAGER_H
#define INC_2DSIDESCROLLER_ENTITYMANAGER_H


#include "Platform.h"
#include <list>
#include "../entity/EntityManager.h"

class EntityManager {
public:
    EntityManager(){};
    explicit EntityManager(std::list<Entity *> entities);
    void draw(Renderer renderer);
    void update();
    void addEntity(Entity * entity);
    std::list<Entity *> getEntities() const;
    void reset();
    ~EntityManager();

private:
    std::list<Entity *> entities;
};


#endif //INC_2DSIDESCROLLER_ENTITYMANAGER_H
