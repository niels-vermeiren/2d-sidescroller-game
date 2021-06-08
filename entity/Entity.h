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
    virtual void update() = 0;
    virtual void draw(Renderer renderer) = 0;
    SDL_Rect * getRect();

    bool isShouldDraw() const;

    void setShouldDraw(bool shouldDraw);

    int minX() const;
    int minY() const;
    int maxX() const;
    int maxY() const;
    Vector &getDirection();
    void setVisible(bool visible);
    virtual void reset();
protected:
    SDL_Rect * rect;
    SDL_Rect * initialPosition;
    float x;
    float y;
    Vector direction;
    bool visible = true;
    bool shouldDraw = false;
};


#endif //INC_2DSIDESCROLLER_ENTITY_H
