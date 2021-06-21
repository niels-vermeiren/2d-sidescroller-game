//
// Created by niels on 4/17/21.
//

#include "Game.h"
#include "../entityai/MovingSawAI.h"
#include "../sound/JukeBox.h"
#include "../entity/Deco.h"


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
    if(InputManager::keyPressed(SDL_SCANCODE_N)) {
        player->getRect()->x += 12000;
        player->getRect()->y -= 2000;
    }
    healthBar->update();
    coinMenu->update();
}

void Game::draw(Renderer renderer) {
   this->background->draw(renderer);
    this->spikes->draw(renderer);
    this->saws->draw(renderer);
    this->tileMap->draw(renderer);
    this->deco->draw(renderer);
    this->coins->draw(renderer);
    /*for(auto * skeleton : skeletons->getEntities()) {
        skeleton->draw(renderer);
    }
    for(auto * mage : mages->getEntities()) {
        mage->draw(renderer);
    }*/
    this->player->draw(renderer);
    this->healthBar->draw(renderer);
    this->coinMenu->draw(renderer);
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

void Game::load(SDL_mutex * mutex) {
    SDL_Rect rect = {10, 63*64-175, 150, 150};

    SDL_mutexP(mutex);
    this->player = new Player({0, 0}, &rect);
    this->player->getSprite()->load();
    player->load();
    SDL_mutexV(mutex);
    auto * tilemapParser = new TileMapParser(new TilesetTextureHolder());
    SDL_mutexP(mutex);
    this->tileMap = tilemapParser->mapToEntities();
    SDL_mutexV(mutex);
    Observable * playerObservable = player;
    this->background = &Background::getInstance();
    this->background->load();


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
    SDL_mutexP(mutex);
    spikes = spikesMap->mapToEntities();
    SDL_mutexV(mutex);
    for(auto * obs:this->spikes->getEntities()) {
        Spike * spike = dynamic_cast<Spike *>(obs);
        spike->getSprite()->load();
        playerObservable->addObserver(obs);
    }
    auto * sawMap = new SawMapParser();
    SDL_mutexP(mutex);
    saws = sawMap->mapToEntities();
    SDL_mutexV(mutex);
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
    SDL_mutexP(mutex);
    coins = coinMap->mapToEntities();
    SDL_mutexV(mutex);
    for(auto * obs:this->coins->getEntities()) {
        Coin * coin = dynamic_cast<Coin *>(obs);
        coin->getSprite()->load();
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
    SDL_mutexP(mutex);
    skeletons = skeletonMap->mapToEntities();
    SDL_mutexV(mutex);
    for(auto * obs:this->skeletons->getEntities()) {
        playerObservable->addObserver(obs);
        Skeleton * skeleton  = dynamic_cast<Skeleton*>(obs);
        skeleton->getSprite()->load();
        SkeletonAI *skeletonAI = new SkeletonAI(dynamic_cast<Skeleton *>(obs), tileMap, player);
        playerObservable->addObserver(skeletonAI);
        this->enemieAIs.push_back(skeletonAI);
    }

    auto * mageMap = new MageMapParser();
    SDL_mutexP(mutex);
    mages = mageMap->mapToEntities();
    SDL_mutexV(mutex);
    for(auto * obs:this->mages->getEntities()) {
        Mage * mage  = dynamic_cast<Mage*>(obs);
        mage->getSprite()->load();
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
    SDL_mutexP(mutex);
    this->deco = decoMap->mapToEntities();
    SDL_mutexV(mutex);
    for(auto * obs:this->deco->getEntities()) {
        Deco * deco = dynamic_cast<Deco *>(obs);
        deco->getSprite()->load();
        playerObservable->addObserver(obs);
    }

    healthBar = new HealthBar();
    healthBar->getHealthBarHolder()->load();
    healthBar->getHealthBarStroke()->load();
    healthBar->getHealthBackground()->load();
    coinMenu =new CoinMenu();
    coinMenu->getCoinMenu()->load();



}

void Game::loadToTextures() {

    this->player->loadToTexture();
    this->player->getSprite()->loadToTexture();
    this->background->loadToTexture();
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

}

