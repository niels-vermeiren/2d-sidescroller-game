//
// Created by niels on 11.06.21.
//

#ifndef INC_2DSIDESCROLLER_DECO_H
#define INC_2DSIDESCROLLER_DECO_H


#include "Entity.h"
#include "../sprite/DecoSprite.h"

class Deco: public Entity {
public:
    Deco(SDL_Rect * rect, int index);
    void draw(Renderer renderer) override;
    void updatePlayerPos(int playerX, int playerY) override;
private:
    DecoSprite * sprite;

};


#endif //INC_2DSIDESCROLLER_DECO_H
