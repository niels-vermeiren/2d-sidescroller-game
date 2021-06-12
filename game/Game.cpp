//
// Created by niels on 4/17/21.
//

#include "Game.h"
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

Player * Game::player;
EntityManager * Game::coins;
EntityManager * Game::skeletons;
EntityManager * Game::mages;

Game::Game(Renderer * renderer) {
    this->renderer = renderer;
}

void Game::update() {
    this->player->update();
    this->spikes->update();
    this->saws->update();
    for(auto * skeleton : skeletons->getEntities()) {
        skeleton->update();
    }
    for(auto * mage : mages->getEntities()) {
        mage->update();
    }
    for(auto * ai : enemieAIs) {
        ai->update();
    }
    if(InputManager::keyPressed(SDL_SCANCODE_R)) {
        reset();
    }
    if(InputManager::keyPressed(SDL_SCANCODE_N)) {
        player->getRect()->x += 12000;
        player->getRect()->y -= 2000;
    }
    healthBar->update();
}

void Game::draw(Renderer renderer) {
    this->background->draw(renderer);
    this->spikes->draw(renderer);
    this->saws->draw(renderer);
    this->tileMap->draw(renderer);
    this->deco->draw(renderer);
    this->coins->draw(renderer);
    for(auto * skeleton : skeletons->getEntities()) {
        skeleton->draw(renderer);
    }
    for(auto * mage : mages->getEntities()) {
        mage->draw(renderer);
    }
    this->player->draw(renderer);
    this->healthBar->draw(renderer);
}

void Game::reset() {
    player->reset();
    coins->reset();
    for(auto * skeleton : skeletons->getEntities()) {
        skeleton->reset();
    }
    for(auto * mage : mages->getEntities()) {
        mage->reset();
    }
}

void Game::handleCollisions() {
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
}

Game::~Game() {
    delete background;
    delete player;
    delete tileMap;
    delete coins;
    delete playerWallCollisionHandler;
    delete playerSawCollisionHandler;
    delete playerSpikeCollisionHandler;
    delete playerCoinCollisionHandler;
    delete bulletTilesetCollisionHandler;
    delete skeletons;
    delete spikes;
    delete skeletonWallCollisionHandler;
    delete bulletMageCollisionHandler;
    delete playerMageCollisionHandler;
    delete playerSkeletonAttackCollisionHandler;
    delete bulletCollisionHandler;
}

void Game::load(Renderer *renderer) {
    SDL_Rect rect = {10, 60*64, 150, 150};
    this->player = new Player({0, 0}, &rect);
    auto * tilemapParser = new TileMapParser(new TilesetTextureHolder(renderer));
    this->tileMap = tilemapParser->mapToEntities();
    Observable * playerObservable = player;
    this->background = &Background::getInstance();
    for(Entity * obs:this->tileMap->getEntities()) {
        playerObservable->addObserver(obs);
    }
    playerObservable->addObserver(background);
    auto * spikesMap = new SpikeMapParser();
    spikes = spikesMap->mapToEntities();
    for(auto * obs:this->spikes->getEntities()) {
        playerObservable->addObserver(obs);
    }
    auto * sawMap = new SawMapParser();
    saws = sawMap->mapToEntities();
    for(auto * obs:this->saws->getEntities()) {
        playerObservable->addObserver(obs);
    }
    auto * coinMap = new CoinMapParser();
    coins = coinMap->mapToEntities();
    for(auto * obs:this->coins->getEntities()) {
        playerObservable->addObserver(obs);
    }
    playerWallCollisionHandler = new PlayerWallCollisionHandler();
    playerSawCollisionHandler = new PlayerSawCollisionHandler();
    playerSpikeCollisionHandler = new PlayerSpikeCollisionHandler();
    playerCoinCollisionHandler = new PlayerCoinCollisionHandler();
    skeletonWallCollisionHandler = new SkeletonWallCollisionHandler();
    mageWallCollisionHandler = new MageWallCollisionHandler();
    playerMageCollisionHandler = new PlayerMageCollisionHandler();
    playerMageBulletCollisionHandler = new PlayerMageBulletCollisionHandler();
    auto * skeletonMap = new SkeletonMapParser();
     skeletons = skeletonMap->mapToEntities();
    for(auto * obs:this->skeletons->getEntities()) {
        playerObservable->addObserver(obs);
        SkeletonAI *skeletonAI = new SkeletonAI(dynamic_cast<Skeleton *>(obs), tileMap);
        playerObservable->addObserver(skeletonAI);
        this->enemieAIs.push_back(skeletonAI);
    }

    auto * mageMap = new MageMapParser();
   mages = mageMap->mapToEntities();
     for(auto * obs:this->mages->getEntities()) {
        playerObservable->addObserver(obs);
        MageAI *mageAI = new MageAI(dynamic_cast<Mage *>(obs), tileMap);
        playerObservable->addObserver(mageAI);
        this->enemieAIs.push_back(mageAI);
    }
    playerSkeletonAttackCollisionHandler = new PlayerSkeletonCollisionHandler();
    bulletCollisionHandler = new PlayerBulletSkeletonCollisionHandler();
    bulletMageCollisionHandler = new PlayerBulletMageCollisionHandler();
    bulletTilesetCollisionHandler = new PlayerBulletTilesetCollisionHandler();

    auto * decoMap = new DecoMapParser();
    this->deco = decoMap->mapToEntities();
    for(auto * obs:this->deco->getEntities()) {
        playerObservable->addObserver(obs);
    }
    healthBar = new HealthBar();
}

