//
// Created by niels on 5/25/21.
//

#ifndef INC_2DSIDESCROLLER_COIN_H
#define INC_2DSIDESCROLLER_COIN_H
#include "Entity.h"
#include "../sprite/CoinSprite.h"

class Coin : public Entity {
public:
    Coin(SDL_Rect * rect);
    virtual ~Coin();
    void draw(Renderer renderer) override;

private:
    CoinSprite * sprite;
};


#endif //INC_2DSIDESCROLLER_COIN_H
