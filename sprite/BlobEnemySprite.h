//
// Created by niels on 6/1/21.
//

#ifndef INC_2DSIDESCROLLER_BLOBENEMYSPRITE_H
#define INC_2DSIDESCROLLER_BLOBENEMYSPRITE_H


#include "AnimatedSprite.h"
#include "../game/Renderer.h"

class BlobEnemySprite : public AnimatedSprite {
public:
    BlobEnemySprite();
    void draw(Renderer renderer, SDL_Rect * pRect, SDL_Rect * clipRect, SDL_RendererFlip flip) override;
    void resetAnimation() override;

};


#endif //INC_2DSIDESCROLLER_BLOBENEMYSPRITE_H
