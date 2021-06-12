//
// Created by niels on 12.06.21.
//

#ifndef INC_2DSIDESCROLLER_HEALTHBARSTROKESPRITE_H
#define INC_2DSIDESCROLLER_HEALTHBARSTROKESPRITE_H


#include "StaticSprite.h"

class HealthBarStrokeSprite : public StaticSprite {
public:
    HealthBarStrokeSprite();
    ~HealthBarStrokeSprite() override;
    void draw(Renderer renderer, SDL_Rect * pRect, SDL_Rect * clipRect, SDL_RendererFlip flip) override;

private:
    SDL_Texture * stroke;

};


#endif //INC_2DSIDESCROLLER_HEALTHBARSTROKESPRITE_H
