//
// Created by niels on 5/14/21.
//

#ifndef INC_2DSIDESCROLLER_SPIKE_H
#define INC_2DSIDESCROLLER_SPIKE_H


#include "Entity.h"
#include "../sprite/SpikesSprite.h"

class Spike : public Entity {
public:
    explicit Spike(SDL_Rect * rect);
    void update() override;
    void draw(Renderer renderer) override;

private:
    SpikesSprite * sprite;
};


#endif //INC_2DSIDESCROLLER_SPIKE_H
