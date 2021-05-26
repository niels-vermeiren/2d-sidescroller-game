//
// Created by niels on 5/25/21.
//

#ifndef INC_2DSIDESCROLLER_COIN_H
#define INC_2DSIDESCROLLER_COIN_H
#include "Entity.h"
#include "../sprite/CoinSprite.h"

class Coin : public Entity {
public:
    Coin();
    virtual ~Coin();
    void update() override;
    void draw(Renderer renderer) override;

private:
    SDL_Rect * rect;
    CoinSprite * sprite;
};


#endif //INC_2DSIDESCROLLER_COIN_H
