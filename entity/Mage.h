//
// Created by niels on 06.06.21.
//

#ifndef INC_2DSIDESCROLLER_MAGE_H
#define INC_2DSIDESCROLLER_MAGE_H


#include "FallingEntity.h"
#include "../sprite/AnimatedSprite.h"
#include "../sprite/MageSprite.h"
#include "../magestate/MageState.h"
#include "collisionbox/CollisionBox.h"
#include "collisionbox/SkeletonCollisionBox.h"

class Mage : public FallingEntity {
public:
    Mage(Vector direction, SDL_Rect * rect);
    void draw(Renderer renderer) override;
    void update() override;
    AnimatedSprite * getSprite();
    void setFacingLeft(bool facingLeft);
    bool facingLeft() const;
    void setState(MageState * state);
    SDL_Rect * getCollisionBox();
    MageState * getState() const;
    void reset() override;
    ~Mage() override;

private:
    CollisionBox * collisionBox;
    AnimatedSprite * sprite;
    MageState * state;
    bool isFacingLeft;
};


#endif //INC_2DSIDESCROLLER_MAGE_H
