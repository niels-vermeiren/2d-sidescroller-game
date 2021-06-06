//
// Created by niels on 06.06.21.
//

#ifndef INC_2DSIDESCROLLER_MAGEAI_H
#define INC_2DSIDESCROLLER_MAGEAI_H


#include "EntityAI.h"
#include "../entity/EntityManager.h"
#include "../entity/Mage.h"

class MageAI : public EntityAI {
public:
    MageAI(Mage * mage, EntityManager * walls);
    void update() override;
    void updatePlayerPos(int playerX, int playerY) override;
private:
    void changeDirectionWhenOnEdgeWall();
    Mage * mage;
    Entity * wall;
    int playerX{};
    int playerY{};
};


#endif //INC_2DSIDESCROLLER_MAGEAI_H
