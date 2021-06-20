//
// Created by niels on 07.06.21.
//

#ifndef INC_2DSIDESCROLLER_MAGEBULLETSPRITE_H
#define INC_2DSIDESCROLLER_MAGEBULLETSPRITE_H


#include "StaticSprite.h"
#include "AnimatedSprite.h"

class MageBulletSprite : public AnimatedSprite {
public:
    MageBulletSprite();
    void load() override;
    void loadToTexture() override;
    ~MageBulletSprite() override;
    void draw(Renderer renderer, SDL_Rect * pRect, SDL_Rect * clipRect, SDL_RendererFlip flip) override;

private:
    SDL_Texture * texture;

};


#endif //INC_2DSIDESCROLLER_MAGEBULLETSPRITE_H
