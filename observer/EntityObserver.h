//
// Created by niels on 4/21/21.
//

#ifndef INC_2DSIDESCROLLER_ENTITYOBSERVER_H
#define INC_2DSIDESCROLLER_ENTITYOBSERVER_H

#include <iostream>
class EntityObserver {
public:
    virtual void updatePlayerPos(int playerX, int playerY) {
    };
};

#endif //INC_2DSIDESCROLLER_ENTITYOBSERVER_H
