//
// Created by niels on 4/12/21.
//

#include "EntityManager.h"

EntityManager::EntityManager(const std::list<Entity *> entities) {
    this->entities = entities;
}

void EntityManager::draw(Renderer renderer) {
    for(Entity * entity : entities) {
        entity->draw(renderer);
    }
}

EntityManager::~EntityManager() {
    for(Entity * entity : entities) {
        delete entity;
    }
}

std::list<Entity *> EntityManager::getEntities() const {
    return entities;
}

void EntityManager::update() {
    for(Entity * entity: entities) {
        entity->update();
    }
}

void EntityManager::addEntity(Entity * entity) {
    this->entities.push_back(entity);
}

EntityManager::EntityManager() {

}
