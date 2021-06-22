//
// Created by niels on 21.06.21.
//

#ifndef INC_2DSIDESCROLLER_LEVELLOADER_H
#define INC_2DSIDESCROLLER_LEVELLOADER_H


#include <SDL2/SDL_ttf.h>
#include "Renderer.h"
#include "../entity/Portal.h"
#include "../background/Background.h"

#include "../stats/HealthBar.h"
#include "LTexture.h"
#include "../stats/CoinMenu.h"
#include "../collision/player/PlayerCollisionHandler.h"
#include "../collision/mage/MageCollisionHandler.h"
#include "../collision/skeleton/SkeletonCollisionHandler.h"
#include "../collision/player/PlayerSkeletonCollisionHandler.h"
#include "../collision/player/PlayerMageCollisionHandler.h"
#include "../collision/player/PlayerMageBulletCollisionHandler.h"
#include "../collision/playerbullet/PlayerBulletCollisionHandler.h"
#include "../collision/playerbullet/PlayerBulletTilesetCollisionHandler.h"
#include "../entityai/EntityAI.h"
#include "../collision/portal/PlayerPortalCollisionHandler.h"

class LevelLoader {
public:
    /*void loadCommonElements();
    void loadTexturesCommonElements();*/
    static LevelLoader * getInstance();
    void load(std::string level, SDL_mutex * mutex);
    void loadTextures(std::string level);
    void draw();
    void update();
    void handleCollisions();
    void reset();
    static const std::string LEVEL_1;

    static const std::string LEVEL_2;
    static const std::string DEV_LEVEL;
private:
    TTF_Font * gFont;
    Renderer * renderer;
    Background * background;
    Portal * portal;
    Player * player;
    EntityManager * coins;
    EntityManager * skeletons;
    EntityManager * mages;
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
    PlayerPortalCollisionHandler * playerPortalCollisionHandler;
    std::vector<EntityAI*> enemieAIs;
};


#endif //INC_2DSIDESCROLLER_LEVELLOADER_H
