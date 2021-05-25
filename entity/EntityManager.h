//
// Created by niels on 4/12/21.
//

#ifndef INC_2DSIDESCROLLER_ENTITYMANAGER_H
#define INC_2DSIDESCROLLER_ENTITYMANAGER_H


#include "Platform.h"
#include <list>

class EntityManager {
public:
    explicit EntityManager(std::list<Entity *> entities);
    EntityManager();
    ~EntityManager();
    void addEntity(Entity * entity);
    void update();
    void draw(Renderer renderer);
    std::list<Entity *> getEntities() const;

private:
    std::list<Entity *> entities;
};


#endif //INC_2DSIDESCROLLER_ENTITYMANAGER_H
