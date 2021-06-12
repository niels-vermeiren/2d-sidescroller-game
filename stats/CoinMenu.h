//
// Created by niels on 12.06.21.
//

#ifndef INC_2DSIDESCROLLER_COINMENU_H
#define INC_2DSIDESCROLLER_COINMENU_H


#include "../observer/EntityObserver.h"
#include "../game/Renderer.h"
#include "../sprite/Sprite.h"

class CoinMenu : EntityObserver {
public:
    CoinMenu();
    void update();
    void draw(Renderer renderer);
    ~CoinMenu();
private:
    SDL_Rect * holderRect;
    Sprite * coinMenu;

};


#endif //INC_2DSIDESCROLLER_COINMENU_H
