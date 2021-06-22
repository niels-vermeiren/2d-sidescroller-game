//
// Created by niels on 21.06.21.
//

#include "Level.h"
int Level::currentLevel = 1;
LevelLoader *  Level::level1;
LevelLoader *  Level::level2;
Level::Level() {
    level1 = new LevelLoader();
    level2 = new LevelLoader();
}

void Level::load(SDL_mutex *mutex) {

    level1->load(LevelLoader::LEVEL_1, mutex);
    level2->load(LevelLoader::LEVEL_2, mutex);
}

void Level::draw() {
    LevelLoader * level = currentLevel == 1?level1:level2;
    level->draw();
}

void Level::update() {
    LevelLoader * level = currentLevel == 1?level1:level2;
    level->update();
}

void Level::handleCollisions() {
    LevelLoader * level = currentLevel == 1?level1:level2;
    level->handleCollisions();
}

void Level::loadTextures() {
    level1->loadTextures(LevelLoader::LEVEL_1);
    level2->loadTextures(LevelLoader::LEVEL_2);
}

void Level::reset() {
    LevelLoader * level = currentLevel == 1?level1:level2;
    level->reset();
}

void Level::levelUp() {
    currentLevel++;
}

void Level::levelDown() {
    currentLevel--;
    if(currentLevel < 1) currentLevel = 1;
}