//
// Created by niels on 21.06.21.
//

#include "Level.h"
int Level::currentLevel = 1;
LevelLoader *  Level::level1;
LevelLoader *  Level::level2;
LevelLoader *  Level::level3;
LevelLoader *  Level::testlevel;
Level::Level() {
    level1 = new LevelLoader();
    level2 = new LevelLoader();
    level3 = new LevelLoader();
    testlevel = new LevelLoader();
}

void Level::load(SDL_mutex *mutex, std::string level) {
    LevelLoader * loader = getLevel(level);
    loader->load(level, mutex);
}

void Level::draw() {
    LevelLoader * level = getLevel();
    level->draw();
}

void Level::update() {
    LevelLoader * level = getLevel();
    level->update();
}

void Level::handleCollisions() {
    LevelLoader * level = getLevel();
    level->handleCollisions();
}

void Level::loadTextures(std::string level) {
    LevelLoader * loader = getLevel(level);
    loader->loadTextures(level);
}

void Level::reset() {
    LevelLoader * level = getLevel();
    level->reset();
}

void Level::levelUp() {
    currentLevel++;
}

void Level::levelDown() {
    currentLevel--;
    if(currentLevel < 1) currentLevel = 1;
}

void Level::loadShared(SDL_mutex * mutex, std::string level) {
    level1->loadShared(mutex);
    level2->loadShared(mutex);
    level3->loadShared(mutex);
}

LevelLoader *Level::getLevel(std::string level) {
    if(level == "") {
        switch(currentLevel) {
            case 1: return level1;
            case 2: return level2;
            case 3: return level3;
            case 4: return testlevel;
        }
    } else {
        if(level == LevelLoader::LEVEL_1) return level1;
        if(level == LevelLoader::LEVEL_2) return level2;
        if(level == LevelLoader::LEVEL_3) return level3;
        if(level == LevelLoader::DEV_LEVEL) return testlevel;
    }
    return nullptr;
}
