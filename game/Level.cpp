//
// Created by niels on 21.06.21.
//

#include "Level.h"
#include "GameStats.h"

int Level::currentLevel = 1;
LevelLoader *  Level::level1;
LevelLoader *  Level::level2;
LevelLoader *  Level::level3;
LevelLoader *  Level::level4;
LevelLoader *  Level::testlevel;
Level::Level() {
    level1 = new LevelLoader();
    level2 = new LevelLoader();
    level3 = new LevelLoader();
    level4 = new LevelLoader();
    testlevel = new LevelLoader();
}

void Level::load(std::string level) {
    LevelLoader * loader = getLevel(level);
    loader->load(level);
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
    GameStats::getInstance().addCoins(PlayerStats::getInstance().getCoins());
    currentLevel++;
}

void Level::levelDown() {
    currentLevel--;
    if(currentLevel < 1) currentLevel = 1;
}

LevelLoader *Level::getLevel(std::string level) {
    if(level.empty()) {
        switch(currentLevel) {
            case 1: return level1;
            case 2: return level2;
            case 3: return level3;
            case 4: return level4;
            case 5: return testlevel;
            default: return testlevel;
        }
    } else {
        if(level == LevelLoader::LEVEL_1) return level1;
        if(level == LevelLoader::LEVEL_2) return level2;
        if(level == LevelLoader::LEVEL_3) return level3;
        if(level == LevelLoader::LEVEL_4) return level4;
        if(level == LevelLoader::DEV_LEVEL) return testlevel;
    }
    return nullptr;
}

int Level::getCurrentLevel() {
    return currentLevel;
}

Level *Level::getInstance() {
    static Level * INSTANCE = new Level();
    return INSTANCE;
}