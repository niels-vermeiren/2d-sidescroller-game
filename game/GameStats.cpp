//
// Created by niels on 08.12.21.
//

#include "GameStats.h"

int GameStats::getCoins() const {
    return coins;
}

void GameStats::setCoins(int coins) {
    GameStats::coins = coins;
}

int GameStats::getDeaths() const {
    return deaths;
}

void GameStats::setDeaths(int deaths) {
    GameStats::deaths = deaths;
}


GameStats &GameStats::getInstance() {
    static GameStats INSTANCE;
    return INSTANCE;
}

void GameStats::addCoins(int coins) {
    this->coins += coins;
}

void GameStats::addDeath() {
    this->deaths += 1;
}
