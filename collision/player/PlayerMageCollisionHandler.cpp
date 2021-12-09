//
// Created by niels on 06.06.21.
//

#include "PlayerMageCollisionHandler.h"
#include "../CollisionDetection.h"
#include "../../magestate/MageDeadState.h"
#include "../../sound/JukeBox.h"

void PlayerMageCollisionHandler::handleCollision(Player *p, Mage *mage) {
    SDL_Rect * pCollisionBox = p->getCollisionBox();
    SDL_Rect * pKnifeBox = p->getKnifeCollisionBox();
    Vector * pDirection = &p->getDirection();
    PState pState = p->getState()->getState();
    SDL_Rect * mCollisionBox = mage->getCollisionBox();
    Vector * mDirection = &mage->getDirection();
    MState mState = mage->getState()->getState();

    if(pState == HURTING || pState == DYING || mState == DOOD) return;

    //Player hits skeleton with knife
    if(CollisionDetection::rectanglesIntersect(pKnifeBox, mCollisionBox) && pState == ATTACKING) {
        mage->setState(new MageDeadState());
        JukeBox::getInstance()->playSound(JukeBox::MAGE_DYING, true);
    }
}
