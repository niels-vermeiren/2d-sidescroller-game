//
// Created by niels on 4/11/21.
//

#include "InputManager.h"
std::map<int, bool> InputManager::keys;
std::map<int, bool> InputManager::old_keys;

bool InputManager::keyDown(Uint8 key) {
    return keys[key];
}

bool InputManager::keyUp(Uint8 key) {
    return !keys[key];
}

void InputManager::renew() {
    old_keys = keys;
}

bool InputManager::keyPressed(Uint8 key) {
    return !old_keys[key] && keys[key];
}

void InputManager::setKeyUp(Uint8 key) {
    keys[key] = false;
}

void InputManager::setKeyDown(Uint8 key) {
    keys[key] = true;
}

