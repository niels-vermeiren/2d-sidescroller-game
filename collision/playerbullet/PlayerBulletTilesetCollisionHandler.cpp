//
// Created by niels on 12.06.21.
//

#include "PlayerBulletTilesetCollisionHandler.h"
#include  "../CollisionDetection.h"

void PlayerBulletTilesetCollisionHandler::handleCollisions(EntityManager *tileSet, Player *p) {
    for(Entity * bullet : p->getBulletPool()->getParticleManager()->getEntities()) {
        for(Entity * tile : tileSet->getEntities()) {
            PlayerBullet * pBullet = dynamic_cast<PlayerBullet*>(bullet);
            if(!pBullet->shouldBeDrawn() || !tile->shouldBeDrawn() || !pBullet->isVisible()) continue;
            if(pBullet->getDirection().x < 0 && pBullet->getRect()->x + pBullet->getRect()->w < tile->minX()) continue;
            if(pBullet->getDirection().x > 0 && pBullet->getRect()->x > tile->maxX()) continue;
            if(bullet->maxY() < tile->minY() || bullet->minY() > tile->maxY()) continue;

            if(CollisionDetection::rectangleCircleIntersect(tile->getRect(), pBullet->getCollisionBox())) {
                pBullet->setVisibility(false);
                pBullet->setShouldDraw(false);
            }
        }
    }
}
