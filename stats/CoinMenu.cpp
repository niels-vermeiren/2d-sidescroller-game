//
// Created by niels on 12.06.21.
//

#include "CoinMenu.h"
#include "../sprite/CoinMenuSprite.h"
#include "../defs.h"
#include "../background/Background.h"

CoinMenu::CoinMenu()  {
    holderRect =  new SDL_Rect {-Background::getInstance().getVpRect()->x+SCREEN_WIDTH-30-254, -Background::getInstance().getVpRect()->y+30, 145, 54};
    this->coinMenu = new CoinMenuSprite();
}

void CoinMenu::draw(Renderer renderer) {
    this->coinMenu->draw(renderer, holderRect, nullptr,SDL_FLIP_NONE);
}

CoinMenu::~CoinMenu() {
    delete holderRect;
    delete coinMenu;
}

void CoinMenu::update() {
    holderRect = new SDL_Rect {-Background::getInstance().getVpRect()->x+37, -Background::getInstance().getVpRect()->y+30+64, 152, 57};
}

Sprite *CoinMenu::getCoinMenu() const {
    return coinMenu;
}
