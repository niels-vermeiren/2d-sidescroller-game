//
// Created by niels on 12.06.21.
//

#include <iostream>
#include "PlayerStats.h"

float PlayerStats::getHealth() const {
    return this->health;
}

int PlayerStats::getCoins() const {
    return this->coins;
}

PlayerStats  &PlayerStats::getInstance() {
    static PlayerStats INSTANCE;
    return INSTANCE;
}

void PlayerStats::takeDamage(float damage) {
    this->health -= damage;
}

void PlayerStats::addCoin(int amount) {
    this->coins += amount;
}

void PlayerStats::setHealth(float health) {
    this->health = health;
}

void PlayerStats::setCoins(int coins) {
    this->coins = coins;
}

PlayerStats::PlayerStats() {
    this->health = 100;
    this->coins = 0;
}
