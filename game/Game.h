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
#include "../collision/player/PlayerCollisionHandler.h"
#include "../collision/player/PlayerWallCollisionHandler.h"
#include "../collision/player/PlayerSawCollisionHandler.h"
#include "../collision/player/PlayerSpikeCollisionHandler.h"
#include "../map/tilemap/SpikeMapParser.h"
#include "../entity/Coin.h"
#include "../entity/Skeleton1.h"
#include "../collision/skeleton1/Skeleton1CollisionHandler.h"

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
    Skeleton1 * skeleton1;
    EntityManager * saws;
    EntityManager * spikes;
    EntityManager * tileMap;
    EntityManager * coins;
    PlayerCollisionHandler * playerWallCollisionHandler;
    PlayerCollisionHandler * playerSawCollisionHandler;
    PlayerCollisionHandler * playerSpikeCollisionHandler;
    PlayerCollisionHandler * playerCoinCollisionHandler;
    Skeleton1CollisionHandler * skeletonWallCollisionHandler;
    PlayerCollisionHandler * playerSkeletonAttackCollisionHandler;
    void reset();
};


#endif //INC_2DSIDESCROLLER_GAME_H
