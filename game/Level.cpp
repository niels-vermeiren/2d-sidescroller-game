//
// Created by niels on 21.06.21.
//

#include "Level.h"
int Level::currentLevel = 1;
LevelLoader *  Level::level1;
LevelLoader *  Level::level2;
LevelLoader *  Level::testlevel;
Level::Level() {
    level1 = new LevelLoader();
    level2 = new LevelLoader();
    testlevel = new LevelLoader();
}

void Level::load(SDL_mutex *mutex) {

    level1->load(LevelLoader::LEVEL_1, mutex);
    level2->load(LevelLoader::LEVEL_2, mutex);
    testlevel->load(LevelLoader::DEV_LEVEL, mutex);
}

void Level::draw() {
    LevelLoader * level = currentLevel == 1?level1:currentLevel == 3?testlevel:level2;
    level->draw();
}

void Level::update() {
    LevelLoader * level = currentLevel == 1?level1:currentLevel == 3?testlevel:level2;
    level->update();
}

void Level::handleCollisions() {
    LevelLoader * level = currentLevel == 1?level1:currentLevel == 3?testlevel:level2;
    level->handleCollisions();
}

void Level::loadTextures() {
    level1->loadTextures(LevelLoader::LEVEL_1);
    level2->loadTextures(LevelLoader::LEVEL_2);
    testlevel->loadTextures(LevelLoader::DEV_LEVEL);
}

void Level::reset() {
    LevelLoader * level = currentLevel == 1?level1:currentLevel == 3?testlevel:level2;
    level->reset();
}

void Level::levelUp() {
    currentLevel++;
}

void Level::levelDown() {
    currentLevel--;
    if(currentLevel < 1) currentLevel = 1;
}