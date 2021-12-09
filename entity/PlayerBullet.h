//
// Created by niels on 09.06.21.
//

#ifndef INC_2DSIDESCROLLER_PLAYERBULLET_H
#define INC_2DSIDESCROLLER_PLAYERBULLET_H


#include "Entity.h"
#include "../sprite/PlayerBulletSprite.h"
#include "collisionbox/PlayerBulletCollisionBox.h"

class PlayerBullet : public Entity {
public:
    PlayerBullet(SDL_Rect * rect, Vector direction, bool isFacingLeft=false);
    void draw(Renderer renderer) override;
    void update() override;
    void updatePlayerPos(int playerX, int playerY) override;
    SDL_Rect * getCollisionBox();
    PlayerBulletSprite *getSprite() const;

private:
    PlayerBulletSprite * sprite;
    PlayerBulletCollisionBox collisionBox;

};


#endif //INC_2DSIDESCROLLER_PLAYERBULLET_H
