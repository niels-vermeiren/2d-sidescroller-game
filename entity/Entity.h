//
// Created by niels on 4/10/21.
//

#ifndef INC_2DSIDESCROLLER_ENTITY_H
#define INC_2DSIDESCROLLER_ENTITY_H

#include <SDL2/SDL.h>
#include "../math/Vector.h"
#include "../game/Renderer.h"
#include "../observer/Observable.h"

class Entity : public Observable, public EntityObserver {
public:
    Entity();
    Entity(Vector direction, SDL_Rect * rect);
    void clone(Vector direction, SDL_Rect * rect);
    virtual void draw(Renderer renderer) = 0;
    virtual void update();
    virtual void reset();
    SDL_Rect * getRect();
    bool shouldBeDrawn() const;
    void isVisible(bool isVisible);
    Vector &getDirection();
    void updatePlayerPos(int playerX, int playerY) override;
    int minX() const;
    int minY() const;
    int maxX() const;
    int maxY() const;
protected:
    float x,y;
    SDL_Rect * rect;
    SDL_Rect * initialPosition;
    Vector direction;
    bool visible = true;
    bool shouldDraw = true;
};


#endif //INC_2DSIDESCROLLER_ENTITY_H
