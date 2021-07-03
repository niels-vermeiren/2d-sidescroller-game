//
// Created by niels on 21.06.21.
//

#include "LevelLoader.h"
#include "../map/tilemap/TileMapParser.h"
#include "../entity/Wall.h"
#include "../map/tilemap/SpikeMapParser.h"
#include "../map/tilemap/SawMapParser.h"
#include "../entityai/MovingSawAI.h"
#include "../map/tilemap/CoinMapParser.h"
#include "../entity/Coin.h"
#include "../collision/player/PlayerWallCollisionHandler.h"
#include "../collision/player/PlayerSawCollisionHandler.h"
#include "../collision/player/PlayerSpikeCollisionHandler.h"
#include "../collision/player/PlayerCoinCollisionHandler.h"
#include "../collision/mage/MageWallCollisionHandler.h"
#include "../map/tilemap/SkeletonMapParser.h"
#include "../entityai/MageAI.h"
#include "../map/tilemap/MageMapParser.h"
#include "../collision/playerbullet/PlayerBulletSkeletonCollisionHandler.h"
#include "../collision/playerbullet/PlayerBulletMageCollisionHandler.h"
#include "../map/tilemap/DecoMapParser.h"
#include "../entity/Deco.h"
#include "../entityai/SkeletonAI.h"
#include "../collision/skeleton/SkeletonWallCollisionHandler.h"
#include "Level.h"

const std::string LevelLoader::LEVEL_1 = "level1.txt";
const std::string LevelLoader::LEVEL_2 = "level2.txt";
const std::string LevelLoader::LEVEL_3 = "level3.txt";
const std::string LevelLoader::DEV_LEVEL = "testlevel.txt";


void LevelLoader::load(std::string level, SDL_mutex*mutex) {
    SDL_Rect rect = {10, 40*64, 150, 150};


    Vector direction(0,0);
    player = new Player(direction, &rect);
    player->getSprite()->load();
    player->load();
    this->background = &Background::getInstance();
    this->background->load();
    playerWallCollisionHandler = new PlayerWallCollisionHandler();
    playerSawCollisionHandler = new PlayerSawCollisionHandler();
    playerSpikeCollisionHandler = new PlayerSpikeCollisionHandler();
    playerCoinCollisionHandler = new PlayerCoinCollisionHandler();
    skeletonWallCollisionHandler = new SkeletonWallCollisionHandler();
    mageWallCollisionHandler = new MageWallCollisionHandler();
    playerMageCollisionHandler = new PlayerMageCollisionHandler();
    playerMageBulletCollisionHandler = new PlayerMageBulletCollisionHandler();
    playerPortalCollisionHandler = new PlayerPortalCollisionHandler();
    playerSkeletonAttackCollisionHandler = new PlayerSkeletonCollisionHandler();
    bulletCollisionHandler = new PlayerBulletSkeletonCollisionHandler();
    bulletMageCollisionHandler = new PlayerBulletMageCollisionHandler();
    bulletTilesetCollisionHandler = new PlayerBulletTilesetCollisionHandler();
    healthBar = new HealthBar();
    healthBar->getHealthBarHolder()->load();
    healthBar->getHealthBarStroke()->load();
    healthBar->getHealthBackground()->load();
    coinMenu =new CoinMenu();
    coinMenu->getCoinMenu()->load();

    SDL_Rect * portalRect = new SDL_Rect {200 * 64 - 246, 64 * 64 - 500, 192, 246};
    portal = new Portal(portalRect);
    portal->getSprite()->load();
    auto * tilemapParser = new TileMapParser(new TilesetTextureHolder());

    this->tileMap = tilemapParser->mapToEntities(level);

    Observable * playerObservable = dynamic_cast<Observable *>(player);
    for(auto * obs:this->tileMap->getEntities()) {
        Wall * w = dynamic_cast<Wall *>(obs);
        for (auto * pl:w->getPlatforms()) {
            Platform * plat = dynamic_cast<Platform *>(pl);
            plat->getSprite()->load();
        }

        playerObservable->addObserver(obs);
    }
    playerObservable->addObserver(background);
    auto * spikesMap = new SpikeMapParser();

    spikes = spikesMap->mapToEntities(level);

    for(auto * obs:this->spikes->getEntities()) {
        Spike * spike = dynamic_cast<Spike *>(obs);
        spike->getSprite()->load();
        playerObservable->addObserver(obs);
    }
    auto * sawMap = new SawMapParser();

    saws = sawMap->mapToEntities(level);

    for(auto * obs:this->saws->getEntities()) {
        playerObservable->addObserver(obs);
        Saw * saw = dynamic_cast<Saw*>(obs);
        saw->getSprite()->load();
        if(saw->movingSaw()) {
            auto * sawAI = new MovingSawAI(saw, this->tileMap);
            enemieAIs.push_back(sawAI);
        }
    }
    auto * coinMap = new CoinMapParser();

    coins = coinMap->mapToEntities(level);

    for(auto * obs:this->coins->getEntities()) {
        Coin * coin = dynamic_cast<Coin *>(obs);
        coin->getSprite()->load();
        playerObservable->addObserver(obs);
    }

    auto * skeletonMap = new SkeletonMapParser();

    skeletons = skeletonMap->mapToEntities(level);

    for(auto * obs:this->skeletons->getEntities()) {
        playerObservable->addObserver(obs);
        Skeleton * skeleton  = dynamic_cast<Skeleton*>(obs);
        skeleton->getSprite()->load();
        SkeletonAI *skeletonAI = new SkeletonAI(dynamic_cast<Skeleton *>(obs), tileMap, player);
        playerObservable->addObserver(skeletonAI);
        this->enemieAIs.push_back(skeletonAI);
    }

    auto * mageMap = new MageMapParser();

    mages = mageMap->mapToEntities(level);

    for(auto * obs:this->mages->getEntities()) {
        Mage * mage  = dynamic_cast<Mage*>(obs);
        mage->getSprite()->load();
        playerObservable->addObserver(obs);
        MageAI *mageAI = new MageAI(dynamic_cast<Mage *>(obs), tileMap);
        playerObservable->addObserver(mageAI);
        this->enemieAIs.push_back(mageAI);
    }

    auto * decoMap = new DecoMapParser();

    this->deco = decoMap->mapToEntities(level);

    for(auto * obs:this->deco->getEntities()) {
        Deco * deco = dynamic_cast<Deco *>(obs);
        deco->getSprite()->load();
        playerObservable->addObserver(obs);
    }
}

void LevelLoader::loadTextures(std::string level) {
    this->background->loadToTexture();
    this->player->loadToTexture();
    this->player->getSprite()->loadToTexture();
    for(auto * obs:this->tileMap->getEntities()) {
        Wall * w = dynamic_cast<Wall *>(obs);
        for (auto * pl:w->getPlatforms()) {
            Platform * plat = dynamic_cast<Platform *>(pl);
            plat->getSprite()->loadToTexture();
        }
    }
    for(auto * obs:this->spikes->getEntities()) {
        Spike * spike = dynamic_cast<Spike *>(obs);
        spike->getSprite()->loadToTexture();
    }
    for(auto * obs:this->saws->getEntities()) {
        Saw * saw = dynamic_cast<Saw*>(obs);
        saw->getSprite()->loadToTexture();
    }
    for(auto * obs:this->coins->getEntities()) {
        Coin * coin = dynamic_cast<Coin *>(obs);
        coin->getSprite()->loadToTexture();
    }

    for(auto * obs:this->skeletons->getEntities()) {
        Skeleton * skeleton  = dynamic_cast<Skeleton*>(obs);
        skeleton->getSprite()->loadToTexture();
    }

    for(auto * obs:this->mages->getEntities()) {
        Mage * mage  = dynamic_cast<Mage*>(obs);
        mage->getSprite()->loadToTexture();
    }

    for(auto * obs:this->deco->getEntities()) {
        Deco * deco = dynamic_cast<Deco *>(obs);
        deco->getSprite()->loadToTexture();
    }
    healthBar->getHealthBarHolder()->loadToTexture();
    healthBar->getHealthBarStroke()->loadToTexture();
    healthBar->getHealthBackground()->loadToTexture();
    coinMenu->getCoinMenu()->loadToTexture();
    portal->getSprite()->loadToTexture();
}

void LevelLoader::draw() {
    this->background->draw(Renderer::getInstance());
    this->spikes->draw(Renderer::getInstance());
    this->deco->draw(Renderer::getInstance());
    this->saws->draw(Renderer::getInstance());
    this->tileMap->draw(Renderer::getInstance());
    this->coins->draw(Renderer::getInstance());
    this->portal->draw(Renderer::getInstance());
    for(auto * skeleton : skeletons->getEntities()) {
        skeleton->draw(Renderer::getInstance());
    }
    for(auto * mage : mages->getEntities()) {
        mage->draw(Renderer::getInstance());
    }
    player->draw(Renderer::getInstance());
    healthBar->draw(Renderer::getInstance());
    coinMenu->draw(Renderer::getInstance());
}

void LevelLoader::update() {
    this->player->update();
    this->spikes->update();
    this->saws->update();
    this->coins->update();
    for(auto * skeleton : skeletons->getEntities()) {
        skeleton->update();
    }
    for(auto * ai : enemieAIs) {
        ai->update();
    }
    for(auto * mage : mages->getEntities()) {
        mage->update();
    }
    if(InputManager::keyPressed(SDL_SCANCODE_R)) {
        reset();
    }
    if(InputManager::keyPressed(SDL_SCANCODE_W)) {
        Level::levelDown();
        Level::reset();
    }
    if(InputManager::keyPressed(SDL_SCANCODE_N)) {
        this->player->getRect()->x += 12000;
        this->player->getRect()->y -= 2000;
    }
    healthBar->update();
    coinMenu->update();
    portal->update();
}

void LevelLoader::handleCollisions() {
    playerSawCollisionHandler->handleCollisions(player, saws);
    playerSpikeCollisionHandler->handleCollisions(player, spikes);
    playerWallCollisionHandler->handleCollisions(player, tileMap);
    playerCoinCollisionHandler->handleCollisions(player, coins);
    for(auto * skeleton : skeletons->getEntities()) {
        Skeleton *pSkeleton = dynamic_cast<Skeleton *>(skeleton);
        playerSkeletonAttackCollisionHandler->handleCollision(player, pSkeleton);
        skeletonWallCollisionHandler->handleCollisions(pSkeleton, tileMap);
        bulletCollisionHandler->handleCollisions(pSkeleton, player->getBulletPool()->getParticleManager());
    }
    for(auto * mage : mages->getEntities()) {
        Mage *pMage = dynamic_cast<Mage *>(mage);
        mageWallCollisionHandler->handleCollisions(pMage, tileMap);
        playerMageCollisionHandler->handleCollision(player, pMage);
        playerMageBulletCollisionHandler->handleCollisions(player, pMage->getBulletPool().getParticleManager());
        bulletMageCollisionHandler->handleCollisions(pMage, player->getBulletPool()->getParticleManager());
    }
    this->bulletTilesetCollisionHandler->handleCollisions(tileMap, player);
    this->playerPortalCollisionHandler->handleCollision(player, portal);
}

void LevelLoader::reset() {
    player->reset();
    for(auto * coin : coins->getEntities()) {
        coin->reset();
    }
    for(auto * skeleton : skeletons->getEntities()) {
        skeleton->reset();
    }
    for(auto * mage : mages->getEntities()) {
        mage->reset();
    }
}

LevelLoader *LevelLoader::getInstance() {
    static LevelLoader * INSTANCE = new LevelLoader();
    return INSTANCE;
}

void LevelLoader::loadShared(SDL_mutex* mutex) {

}
