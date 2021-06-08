//
// Created by niels on 07.06.21.
//

#ifndef INC_2DSIDESCROLLER_MAGEBULLET_H
#define INC_2DSIDESCROLLER_MAGEBULLET_H


#include "Entity.h"
#include "../sprite/MageBulletSprite.h"

class MageBullet : public Entity {
public:
    MageBullet(SDL_Rect * rect, Vector direction);
    void update() override;
    void draw(Renderer renderer) override;
    void updatePlayerPos(int playerX, int playerY) override;

private:
    MageBulletSprite * sprite;

};


#endif //INC_2DSIDESCROLLER_MAGEBULLET_H
