//
// Created by niels on 4/20/21.
//

#ifndef INC_2DSIDESCROLLER_BACKGROUND_H
#define INC_2DSIDESCROLLER_BACKGROUND_H

#include "../defs.h"
#include "../sprite/StaticSprite.h"
#include "../observer/EntityObserver.h"

class Background : public EntityObserver {
public:
    Background();
    ~Background();
    static Background &getInstance();
    void draw(Renderer renderer);
    virtual void updatePlayerPos(int playerX, int playerY) override;

    SDL_Rect *getVpRect() const;

private:
    SDL_Rect * playerPos;
    SDL_Rect * bgRect;
    SDL_Rect * vp;
    SDL_Surface * surface;
    SDL_Texture * bgTexture;
};


#endif //INC_2DSIDESCROLLER_BACKGROUND_H
