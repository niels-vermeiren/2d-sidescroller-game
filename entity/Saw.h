//
// Created by niels on 4/29/21.
//

#ifndef INC_2DSIDESCROLLER_SAW_H
#define INC_2DSIDESCROLLER_SAW_H


#include "Entity.h"
#include "../sprite/SawSprite.h"

class Saw : public Entity {
public:
    explicit Saw(SDL_Rect * rect, bool movingSaw);
    void update() override;
    void draw(Renderer renderer) override;
    bool isMovingLeft() const;
    void setMovingLeft(bool movingLeft);
    bool movingSaw() const;

private:
    bool movingLeft;
    SawSprite * sprite;
    bool isMovingSaw;
};


#endif //INC_2DSIDESCROLLER_SAW_H
