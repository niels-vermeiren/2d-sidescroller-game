//
// Created by niels on 21.06.21.
//

#ifndef INC_2DSIDESCROLLER_PORTAL_H
#define INC_2DSIDESCROLLER_PORTAL_H


#include "Entity.h"
#include "../sprite/PortalSprite.h"

class Portal : public Entity {
public:
    Portal(SDL_Rect * rect);
    ~Portal() override;
    void draw(Renderer renderer) override;
    PortalSprite *getSprite() const;

private:
    PortalSprite * sprite;

};


#endif //INC_2DSIDESCROLLER_PORTAL_H
