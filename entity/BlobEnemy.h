//
// Created by niels on 6/1/21.
//

#ifndef INC_2DSIDESCROLLER_BLOBENEMY_H
#define INC_2DSIDESCROLLER_BLOBENEMY_H


#include "../math/Vector.h"
#include "SDL2/SDL.h"
#include "FallingEntity.h"
#include "../sprite/AnimatedSprite.h"

class BlobEnemy : public FallingEntity {
public:
    BlobEnemy(Vector direction, SDL_Rect * rect);
    void draw(Renderer renderer) override;
    void update() override;
    AnimatedSprite * getSprite();
    void setFacingLeft(bool facingLeft);
    //void setState(PlayerState * state);
    //PlayerState * getState() const;
    void reset() override;
    ~BlobEnemy() override;

private:
    //PlayerState * state;
    bool isFacingLeft;
    AnimatedSprite * sprite;
};


#endif //INC_2DSIDESCROLLER_BLOBENEMY_H
