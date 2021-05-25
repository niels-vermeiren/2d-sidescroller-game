//
// Created by niels on 4/29/21.
//

#ifndef INC_2DSIDESCROLLER_SAW_H
#define INC_2DSIDESCROLLER_SAW_H


#include "Entity.h"
#include "../sprite/SawSprite.h"

class Saw : public Entity {
public:
    Saw(SDL_Rect * rect);
    void update() override;
    void draw(Renderer renderer) override;

private:
    void drawCircle(SDL_Renderer * renderer, int32_t centreX, int32_t centreY, int32_t radius);
    SawSprite * sprite;
};


#endif //INC_2DSIDESCROLLER_SAW_H
