//
// Created by niels on 4/10/21.
//

#ifndef INC_2DSIDESCROLLER_ENTITY_H
#define INC_2DSIDESCROLLER_ENTITY_H

#include <SDL2/SDL.h>
#include "../math/Vector.h"
#include "../game/renderer.h"
#include "../observer/Observable.h"

class Entity : public Observable, public EntityObserver {
public:
    Entity();
    Entity(Vector direction, SDL_Rect * rect);
    virtual void update() = 0;
    virtual void draw(Renderer renderer) = 0;
    Vector &getDirection();
    SDL_Rect * getRect();
    void setVisible(const bool visible);
    virtual void reset();
    int minX() const;
    int minY() const;
    int maxX() const;
    int maxY() const;
protected:
    bool visible = true;
    SDL_Rect * rect;
    Vector direction;
};


#endif //INC_2DSIDESCROLLER_ENTITY_H
