//
// Created by niels on 5/27/21.
//

#include "PlayerCoinCollisionHandler.h"
#include "../CollisionDetection.h"
#include "../../stats/PlayerStats.h"
#include "../../sound/JukeBox.h"

void PlayerCoinCollisionHandler::handleCollision(Player *p, Entity *entity) {
    if(CollisionDetection::rectangleCircleIntersect(p->getCollisionBox(), entity->getRect())) {
        if(entity->isVisible()) {
            PlayerStats::getInstance().addCoin(COIN_WORTH);
            JukeBox::getInstance()->playSound(JukeBox::COIN, true);
        }
        entity->setVisibility(false);
    }

}
