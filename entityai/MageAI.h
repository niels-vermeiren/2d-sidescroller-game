//
// Created by niels on 06.06.21.
//

#ifndef INC_2DSIDESCROLLER_MAGEAI_H
#define INC_2DSIDESCROLLER_MAGEAI_H


#include "EntityAI.h"
#include "../entity/EntityManager.h"
#include "../entity/Mage.h"
#include "../magestate/MageAttackState.h"

class MageAI : public EntityAI {
public:
    MageAI(Mage * mage, EntityManager * walls);
    void update() override;
    void updatePlayerPos(int playerX, int playerY) override;
private:
    int tick = 0;
    void changeDirectionWhenOnEdgeWall();
    void facePlayerAndAttack();
    void shoot();
    Mage * mage;
    Entity * wall;
    int playerX{};
    int playerY{};
    MageAttackState * attackState;
};


#endif //INC_2DSIDESCROLLER_MAGEAI_H
