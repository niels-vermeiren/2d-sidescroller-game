//
// Created by niels on 6/2/21.
//

#ifndef INC_2DSIDESCROLLER_SKELETONAI_H
#define INC_2DSIDESCROLLER_SKELETONAI_H


#include "EntityAI.h"
#include "../entity/Skeleton.h"
#include "../entity/EntityManager.h"
#include "../entity/Wall.h"
#include "../command/skeleton/SkeletonMoveLeftCommand.h"
#include "../command/skeleton/SkeletonMoveRightCommand.h"
#include "../skeletonstate/MoveLeftState.h"
#include "../skeletonstate/MoveRightState.h"
#include "../playerstate/AttackState.h"
#include "../skeletonstate/AttackingState.h"

class SkeletonAI : public EntityAI {
public:
    SkeletonAI(Skeleton * skeleton, EntityManager * walls, Player * player);
    void update() override;
    void updatePlayerPos(int playerX, int playerY) override;
private:
    void attackClosePlayer();
    void walkTowardsPlayerInRange();
    void changeDirectionWhenOnEdgeWall();
    void attack();
    Skeleton * skeleton;
    Entity * wall;
    Player * player;
    int playerX{};
    int playerY{};
    int tick = 0;
    bool hasAttacked = false;
    bool playerWithinAttackingRange();

    bool onBoundsRightSide();

    bool onBoundsLeftSide();
};


#endif //INC_2DSIDESCROLLER_SKELETONAI_H
