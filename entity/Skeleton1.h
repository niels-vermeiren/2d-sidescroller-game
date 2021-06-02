//
// Created by niels on 6/1/21.
//

#ifndef INC_2DSIDESCROLLER_SKELETON1_H
#define INC_2DSIDESCROLLER_SKELETON1_H


#include "../math/Vector.h"
#include "SDL2/SDL.h"
#include "FallingEntity.h"
#include "../sprite/AnimatedSprite.h"
#include "../skeletonstate/SkeletonState.h"

class Skeleton1 : public FallingEntity {
public:
    Skeleton1(Vector direction, SDL_Rect * rect);
    void draw(Renderer renderer) override;
    void update() override;
    AnimatedSprite * getSprite();
    void setFacingLeft(bool facingLeft);
    void setState(SkeletonState * state);
    SDL_Rect * getBoundingRect();
    SkeletonState * getState() const;
    void reset() override;
    ~Skeleton1() override;

private:
    SkeletonState * state;
    bool isFacingLeft;
    AnimatedSprite * sprite;
};


#endif //INC_2DSIDESCROLLER_SKELETON1_H
