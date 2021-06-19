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
#include "../stats/CoinMenu.h"
#include "LTexture.h"
#include <SDL2/SDL_ttf.h>
#include "../map/tilemap/SawMapParser.h"
#include "../collision/player/PlayerCoinCollisionHandler.h"
#include "../map/tilemap/CoinMapParser.h"
#include "../animation/SkeletonAnimation.h"
#include "../collision/skeleton/SkeletonWallCollisionHandler.h"
#include "../entityai//SkeletonAI.h"
#include "../collision/mage/MageWallCollisionHandler.h"
#include "../entityai/MageAI.h"
#include "../collision/playerbullet/PlayerBulletSkeletonCollisionHandler.h"
#include "../collision/playerbullet/PlayerBulletMageCollisionHandler.h"
#include "../map/tilemap/SkeletonMapParser.h"
#include "../map/tilemap/MageMapParser.h"
#include "../map/tilemap/DecoMapParser.h"
#include "../stats/CoinMenu.h"
#include "LTexture.h"
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
    TTF_Font * gFont;
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
    CoinMenu * coinMenu;
    LTexture * lTexture;
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
