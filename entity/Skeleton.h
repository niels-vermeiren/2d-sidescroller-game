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
    void setFacingLeft(bool facingLeft);
    bool facingLeft() const;
    void setState(SkeletonState * state);
    SDL_Rect * getCollisionBox();
    SkeletonState * getState() const;
    SDL_Rect * getAxeCollisionBox();
    void reset() override;
    ~Skeleton() override;

private:
    SkeletonState * state;
    SkeletonCollisionBox collisionBox;
    SkeletonAxeCollisionBox axeCollisionBox;
    bool isFacingLeft;
    AnimatedSprite * sprite;
};


#endif //INC_2DSIDESCROLLER_SKELETON_H
