//
// Created by niels on 4/17/21.
//

#ifndef INC_2DSIDESCROLLER_GAME_H
#define INC_2DSIDESCROLLER_GAME_H


#include "../entity/Entity.h"
#include "../entity/EntityManager.h"
#include "../map/tilemap/TileMapParser.h"
#include "../background/Background.h"
#include "../entity/Saw.h"
#include "../entity/Spike.h"
#include "../collision/CollisionHandler.h"
#include "../collision/PlayerWallCollisionHandler.h"
#include "../collision/PlayerSawCollisionHandler.h"
#include "../collision/PlayerSpikeCollisionHandler.h"
#include "../map/tilemap/SpikeMapParser.h"

class Game {
public:
    Game(Renderer * renderer);
    virtual ~Game();
    void update();
    void draw(Renderer renderer);
    void handleCollisions();

private:
    Background * background;
    Player * player;
    EntityManager * saws;
    EntityManager * spikes;
    EntityManager * tileMap;
    CollisionHandler * playerWallCollisionHandler;
    CollisionHandler * playerSawCollisionHandler;
    CollisionHandler * playerSpikeCollisionHandler;
    void reset();
};


#endif //INC_2DSIDESCROLLER_GAME_H
