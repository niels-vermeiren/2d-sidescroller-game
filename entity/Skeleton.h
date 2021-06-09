//
// Created by niels on 6/1/21.
//

#ifndef INC_2DSIDESCROLLER_SKELETON_H
#define INC_2DSIDESCROLLER_SKELETON_H


#include "../math/Vector.h"
#include "SDL2/SDL.h"
#include "FallingEntity.h"
#include "../sprite/AnimatedSprite.h"
#include "../skeletonstate/SkeletonState.h"
#include "collisionbox/SkeletonCollisionBox.h"
#include "collisionbox/SkeletonAxeCollisionBox.h"

class Skeleton : public FallingEntity {
public:
    Skeleton(Vector direction, SDL_Rect * rect);
    void draw(Renderer renderer) override;
    void update() override;
    AnimatedSprite * getSprite();
    SkeletonState * getState() const;
    void setState(SkeletonState * state);
    bool isFacingLeft() const;
    void setFacingLeft(bool facingLeft);
    SDL_Rect * getCollisionBox();
    SDL_Rect * getAxeCollisionBox();
    void reset() override;
    ~Skeleton() override;

private:
    AnimatedSprite * sprite;
    SkeletonState * state;
    bool facingLeft;
    SkeletonCollisionBox collisionBox;
    SkeletonAxeCollisionBox axeCollisionBox;
};


#endif //INC_2DSIDESCROLLER_SKELETON_H
