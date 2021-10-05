//
// Created by niels on 12.06.21.
//

#include "HealthBar.h"
#include "../sprite/HealthBarHolderSprite.h"
#include "../sprite/HealthBarStrokeSprite.h"
#include "../defs.h"
#include "../background/Background.h"

HealthBar::HealthBar() {
    healthBackground = new HealthBarHolderSprite(true);
    healthBarHolder = new HealthBarHolderSprite(false);
    healthBarStroke = new HealthBarStrokeSprite();
    holderRect = new SDL_Rect {30, LEVEL_HEIGHT-SCREEN_HEIGHT+30, 254, 47};
    strokeRect = new SDL_Rect {65, LEVEL_HEIGHT-SCREEN_HEIGHT+39, 196, 30};
}

HealthBar::~HealthBar() {
    delete healthBarHolder;
    delete healthBarStroke;
    delete holderRect;
    delete strokeRect;
}

void HealthBar::update() {
    SDL_Rect *vp = Background::getInstance().getVpRect();
    holderRect = new SDL_Rect {-vp->x+35, -vp->y+30, 254, 47};
    strokeRect = new SDL_Rect {-vp->x+83, -vp->y+33, static_cast<int>(((float)196/100)*PlayerStats::getInstance().getHealth())+5, 37};
    strokeRect->w = strokeRect->w == 5 ? 0 : strokeRect->w;
}

void HealthBar::draw(Renderer renderer) {
    healthBackground->draw(renderer, holderRect, nullptr, SDL_FLIP_NONE);
    healthBarStroke->draw(renderer, strokeRect , nullptr, SDL_FLIP_NONE);
    healthBarHolder->draw(renderer, holderRect, nullptr, SDL_FLIP_NONE);
}

Sprite *HealthBar::getHealthBarHolder() const {
    return healthBarHolder;
}

Sprite *HealthBar::getHealthBarStroke() const {
    return healthBarStroke;
}

Sprite *HealthBar::getHealthBackground() const {
    return healthBackground;
}
