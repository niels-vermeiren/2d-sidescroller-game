//
// Created by niels on 09.06.21.
//

#ifndef INC_2DSIDESCROLLER_PLAYERBULLETSPRITE_H
#define INC_2DSIDESCROLLER_PLAYERBULLETSPRITE_H


#include "StaticSprite.h"

class PlayerBulletSprite : public StaticSprite {
public:
    PlayerBulletSprite();
    void draw(Renderer renderer, SDL_Rect * pRect, SDL_Rect * clipRect, SDL_RendererFlip flip) override;
    ~PlayerBulletSprite() override;

private:
    SDL_Texture * texture;

};


#endif //INC_2DSIDESCROLLER_PLAYERBULLETSPRITE_H
