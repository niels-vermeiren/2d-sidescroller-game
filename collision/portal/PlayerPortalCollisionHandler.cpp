//
// Created by niels on 22.06.21.
//

#include "PlayerPortalCollisionHandler.h"
#include "../CollisionDetection.h"
#include "../../game/Level.h"
#include "../../sound/JukeBox.h"

void PlayerPortalCollisionHandler::handleCollision(Player *player, Entity *entity) {
    SDL_Rect * smallerRect = new SDL_Rect {entity->minX() + entity->getRect()->w/2, entity->minY() + entity->getRect()->h/2, 50, 50};

    if(!CollisionDetection::rectangleCircleIntersect(player->getCollisionBox(), smallerRect)) return;

    JukeBox::getInstance()->playSound(JukeBox::PORTAL, true);

    Level::levelUp();
    Level::reset();
}
