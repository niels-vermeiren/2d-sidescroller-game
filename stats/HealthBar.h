//
// Created by niels on 12.06.21.
//

#ifndef INC_2DSIDESCROLLER_HEALTHBAR_H
#define INC_2DSIDESCROLLER_HEALTHBAR_H


#include "PlayerStats.h"
#include "../sprite/Sprite.h"
#include "../observer/EntityObserver.h"

class HealthBar : EntityObserver {
public:
    HealthBar();
    void update();
    void draw(Renderer renderer);

    Sprite *getHealthBarHolder() const;

    Sprite *getHealthBarStroke() const;

    Sprite *getHealthBackground() const;

    ~HealthBar();
private:
    int oldHealth;
    SDL_Rect * holderRect;
    SDL_Rect * strokeRect;
    SDL_Rect * clipStrokeRect;
    Sprite * healthBarHolder;
    Sprite * healthBackground;
    Sprite * healthBarStroke;
};


#endif //INC_2DSIDESCROLLER_HEALTHBAR_H
