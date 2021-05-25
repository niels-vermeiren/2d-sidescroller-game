//
// Created by niels on 4/21/21.
//

#include "Observable.h"

Observable::Observable() = default;

void Observable::addObserver(EntityObserver *observer) {
    this->observers.push_back(observer);
}

Observable::~Observable() {
    for(EntityObserver * observer: this->observers) delete observer;
}
