//
// Created by niels on 10.06.21.
//

#include "ShootBulletCommand.h"

ShootBulletCommand::ShootBulletCommand(Player *entity) {
    this->entity = entity;
}

void ShootBulletCommand::execute() {
    bool left = entity->isFacingLeft();
    ParticlePool<PlayerBullet*> * bulletPool = entity->getBulletPool();

    auto * bulletRect = new SDL_Rect {entity->getCollisionBox()->x + (left? -40:40), entity->getCollisionBox()->y + 60, 47, 19};
    auto * reusableBulletObj = bulletPool->getFreeParticle();

    //Reuse bullets not in sight
    if(reusableBulletObj != nullptr) {
        reusableBulletObj->clone({static_cast<float>(left ? -6 : 6), 0}, bulletRect, left);
        reusableBulletObj->setVisibility(true);
        return;
    }

    auto * t = new PlayerBullet(bulletRect, {static_cast<float>(left ? -6: 6), 0}, left);
    t->getSprite()->load();
    t->getSprite()->loadToTexture();
    t->setVisibility(true);
    bulletPool->addParticle(t);
}
