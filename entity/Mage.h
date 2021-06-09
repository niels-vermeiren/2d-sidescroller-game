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
#include "MageBullet.h"
#include "../particles/ParticlePool.h"

class Mage : public FallingEntity {
public:
    Mage(Vector direction, SDL_Rect * rect);
    void draw(Renderer renderer) override;
    void update() override;
    void addBullet(MageBullet * bullet);
    void setState(MageState * state);
    MageState * getState() const;
    AnimatedSprite * getSprite();
    SDL_Rect * getCollisionBox();
    SDL_Rect * getStaffCollisionBox() const;
    ParticlePool * getBulletPool();
    void setFacingLeft(bool facingLeft);
    bool isShouldAttack() const;
    void setShouldAttack(bool shouldAttack);
    void updatePlayerPos(int playerX, int playerY) override;
    void reset() override;
    ~Mage() override;

private:
    ParticlePool * particlePool;
    CollisionBox * collisionBox;
    CollisionBox * staffCollisionBox;
    AnimatedSprite * sprite;
    MageState * state;
    bool isFacingLeft;
    bool canAttack = false;
};


#endif //INC_2DSIDESCROLLER_MAGE_H
