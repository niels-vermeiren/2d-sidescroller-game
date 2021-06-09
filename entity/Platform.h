//
// Created by niels on 4/11/21.
//

#ifndef INC_2DSIDESCROLLER_PLATFORM_H
#define INC_2DSIDESCROLLER_PLATFORM_H


#include "Entity.h"
#include "../game/Renderer.h"
#include "../sprite/PlatformSprite.h"
#include "../defs.h"

class Platform : public Entity {
public:
    Platform(Vector direction, SDL_Rect * rect, SDL_Rect * clipRect);
    void update() override;
    void draw(Renderer renderer) override;
    virtual ~Platform();

private:
    PlatformSprite * sprite;
    SDL_Rect * clipRect;
};


#endif //INC_2DSIDESCROLLER_PLATFORM_H
