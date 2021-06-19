//
// Created by niels on 6/2/21.
//

#include "SkeletonAI.h"

SkeletonAI::SkeletonAI(Skeleton *skeleton, EntityManager *walls, Player * player) {
    playerX = 0, playerY = 0;
    this->skeleton = skeleton;
    this->player = player;
    //Get wall under skeleton
    for(Entity * entity : walls->getEntities()) {
        bool wallIsUnderEnemy = entity->minY() >= skeleton->maxY() && entity->minX() < skeleton->maxX() && entity->maxX() > skeleton->minX();

        if(wallIsUnderEnemy) {
            this->wall = entity;
            break;
        }
    }
    skeleton->setState(new MoveLeftState());
}

void SkeletonAI::update() {
    if(skeleton->getState()->getState() == DEAD) return;

    attackClosePlayer();
    changeDirectionWhenOnEdgeWall();
}

void SkeletonAI::updatePlayerPos(int x, int y) {
    this->playerX = x;
    this->playerY = y;
}

void SkeletonAI::attackClosePlayer() {
    tick++;

    if(tick % SKELETON_TIME_BETWEEN_ATTACKS == 0) hasAttacked = false;

    //If player is not on same height as enemy, skeleton is not attacking or skeleton has already attacked, do nothing
    if(playerY < skeleton->getCollisionBox()->y || playerY > skeleton->getCollisionBox()->y +
                                                             skeleton->getCollisionBox()->h) return;

    if(player->getCollisionBox()->x + player->getCollisionBox()->w < wall->minX() || player->getCollisionBox()->x > wall->maxX()) return;

    walkTowardsPlayerInRange();
    changeDirectionWhenOnEdgeWall();
    if(!hasAttacked) attack();
}

bool SkeletonAI::playerWithinAttackingRange() {
    bool leftSide = player->getCollisionBox()->x + player->getCollisionBox()->w + player->getDirection().x < skeleton->getCollisionBox()->x + skeleton->getDirection().x + (player->getDirection().x == 0?SKELETON_ATTACK_MIN_PLAYER_DISTANCE-70:SKELETON_ATTACK_MIN_PLAYER_DISTANCE) && player->getCollisionBox()->x + player->getCollisionBox()->w + player->getDirection().x > skeleton->getCollisionBox()->x + + skeleton->getDirection().x;
    bool rightSide = player->getCollisionBox()->x + player->getDirection().x > skeleton->getCollisionBox()->x + skeleton->getCollisionBox()->w + skeleton->getDirection().x - (player->getDirection().x == 0?SKELETON_ATTACK_MIN_PLAYER_DISTANCE-70:SKELETON_ATTACK_MIN_PLAYER_DISTANCE)
                     && player->getCollisionBox()->x + player->getDirection().x <  skeleton->getCollisionBox()->x + skeleton->getCollisionBox()->w + skeleton->getDirection().x;
    return leftSide || rightSide;
}


void SkeletonAI::walkTowardsPlayerInRange() {

    bool withinLeftRange = player->getCollisionBox()->x + player->getCollisionBox()->w + player->getDirection().x >
                           skeleton->getCollisionBox()->x - SKELETON_CHARGE_MIN_PLAYER_DISTANCE &&
                           player->getCollisionBox()->x + player->getCollisionBox()->w < skeleton->getCollisionBox()->x;

    bool withinRightRange = player->getCollisionBox()->x + player->getDirection().x + player->getDirection().x<
                            skeleton->getCollisionBox()->x + skeleton->getCollisionBox()->w + SKELETON_CHARGE_MIN_PLAYER_DISTANCE &&
                           player->getCollisionBox()->x > skeleton->getCollisionBox()->x + skeleton->getCollisionBox()->w;

    if ((withinLeftRange || withinRightRange) && skeleton->getState()->getState() != ATTACK) {
        if(withinLeftRange && !onBoundsLeftSide()) skeleton->setState(new MoveLeftState());
        if(withinRightRange && !onBoundsRightSide()) skeleton->setState(new MoveRightState());

    }
}

void SkeletonAI::changeDirectionWhenOnEdgeWall() {
    //Don't fall off of platform, turn around
    if(this->onBoundsRightSide()) {
        skeleton->setState(new MoveLeftState());
    }
    if(this->onBoundsLeftSide()) {
        skeleton->setState(new MoveRightState());
    }
}

bool SkeletonAI::onBoundsLeftSide() {
    bool onBoundsLeftSide = skeleton->getCollisionBox()->x - skeleton->getDirection().x < wall->minX();
    return onBoundsLeftSide;
}

bool SkeletonAI::onBoundsRightSide() {
    bool onBoundsRightSide = skeleton->getCollisionBox()->x + skeleton->getCollisionBox()->w + skeleton->getDirection().x > wall->maxX();
    return onBoundsRightSide;
}

void SkeletonAI::attack() {
    if(playerWithinAttackingRange() && skeleton->getState()->getState() != ATTACK) {
        player->setFacingLeft(playerX < skeleton->getCollisionBox()->x + skeleton->getCollisionBox()->w/2);
        skeleton->getSprite()->resetAnimation();
        skeleton->setState(new AttackingState());
        hasAttacked = true;
    } else
    if (playerX < skeleton->getCollisionBox()->x + skeleton->getCollisionBox()->w && playerX > skeleton->getCollisionBox()->x && skeleton->getState()->getState() != ATTACK) {
        player->setFacingLeft(playerX < skeleton->getCollisionBox()->x + skeleton->getCollisionBox()->w/2);
        skeleton->setState(new AttackingState());
        skeleton->getSprite()->resetAnimation();
        hasAttacked = true;
    }

}
