//
// Created by niels on 09.06.21.
//

#ifndef INC_2DSIDESCROLLER_PLAYERBULLET_H
#define INC_2DSIDESCROLLER_PLAYERBULLET_H


#include "Entity.h"
#include "../sprite/PlayerBulletSprite.h"

class PlayerBullet : public Entity {
public:
    PlayerBullet(SDL_Rect * rect, Vector direction);
    void draw(Renderer renderer) override;
    void update() override;
    bool isFacingLeft() const;
    void setFacingLeft(bool facingLeft);
    //  SDL_Rect * getCollisionBox();

private:
    PlayerBulletSprite * sprite;
    bool facingLeft;
   // PlayerBulletCollisionBox collisionBox;

};


#endif //INC_2DSIDESCROLLER_PLAYERBULLET_H
