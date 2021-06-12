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
#include "../entity/Skeleton.h"
#include "../collision/player/PlayerSkeletonCollisionHandler.h"
#include "../collision/skeleton/SkeletonCollisionHandler.h"
#include "../entityai/EntityAI.h"
#include "../entity/Mage.h"
#include "../collision/mage/MageCollisionHandler.h"
#include "../collision/player/PlayerMageCollisionHandler.h"
#include "../collision/player/PlayerMageBulletCollisionHandler.h"
#include "../entity/PlayerBullet.h"
#include "../collision/playerbullet/PlayerBulletCollisionHandler.h"
#include "../collision/playerbullet/PlayerBulletTilesetCollisionHandler.h"
#include "../stats/HealthBar.h"

class Game {
public:
    explicit Game(Renderer * renderer);
    void load(Renderer * renderer);
    virtual ~Game();
    void update();
    void draw(Renderer renderer);
    void handleCollisions();
    static void reset();
private:
    Renderer * renderer;
    Background * background;
    static Player * player;
    static EntityManager * coins;
    static EntityManager * skeletons;
    static EntityManager * mages;
    EntityManager * saws;
    EntityManager * spikes;
    EntityManager * tileMap;
    EntityManager * deco;
    HealthBar * healthBar;
    PlayerCollisionHandler * playerWallCollisionHandler;
    PlayerCollisionHandler * playerSawCollisionHandler;
    PlayerCollisionHandler * playerSpikeCollisionHandler;
    PlayerCollisionHandler * playerCoinCollisionHandler;
    MageCollisionHandler * mageWallCollisionHandler;
    SkeletonCollisionHandler * skeletonWallCollisionHandler;
    PlayerSkeletonCollisionHandler * playerSkeletonAttackCollisionHandler;
    PlayerMageCollisionHandler * playerMageCollisionHandler;
    PlayerMageBulletCollisionHandler * playerMageBulletCollisionHandler;
    PlayerBulletCollisionHandler * bulletCollisionHandler;
    PlayerBulletCollisionHandler * bulletMageCollisionHandler;
    PlayerBulletTilesetCollisionHandler * bulletTilesetCollisionHandler;
    std::vector<EntityAI*> enemieAIs;

};


#endif //INC_2DSIDESCROLLER_GAME_H
