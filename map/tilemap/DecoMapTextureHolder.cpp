//
// Created by niels on 11.06.21.
//

#include <SDL2/SDL_image.h>
#include "DecoMapTextureHolder.h"

DecoMapTextureHolder::DecoMapTextureHolder() {
    SDL_Surface * sdeco1 = IMG_Load("../resources/deco/deco1.png");
    Renderer &deco1renderer = Renderer::getInstance();
    decoSet.push_back(SDL_CreateTextureFromSurface(deco1renderer.sdlRenderer, sdeco1));

    SDL_Surface * sdeco2 = IMG_Load("../resources/deco/deco2.png");
    Renderer &deco2renderer = Renderer::getInstance();
    decoSet.push_back(SDL_CreateTextureFromSurface(deco2renderer.sdlRenderer, sdeco2));

    SDL_Surface * sdeco3 = IMG_Load("../resources/deco/deco3.png");
    Renderer &deco3renderer = Renderer::getInstance();
    decoSet.push_back(SDL_CreateTextureFromSurface(deco3renderer.sdlRenderer, sdeco3));

    SDL_Surface * sdeco4 = IMG_Load("../resources/deco/deco4.png");
    Renderer &deco4renderer = Renderer::getInstance();
    decoSet.push_back(SDL_CreateTextureFromSurface(deco4renderer.sdlRenderer, sdeco4));

    SDL_Surface * sdeco5 = IMG_Load("../resources/deco/deco5.png");
    Renderer &deco5renderer = Renderer::getInstance();
    decoSet.push_back(SDL_CreateTextureFromSurface(deco5renderer.sdlRenderer, sdeco5));

    SDL_Surface * sdeco6 = IMG_Load("../resources/deco/deco6.png");
    Renderer &deco6renderer = Renderer::getInstance();
    decoSet.push_back(SDL_CreateTextureFromSurface(deco6renderer.sdlRenderer, sdeco6));

    SDL_Surface * sdeco7 = IMG_Load("../resources/deco/deco7.png");
    Renderer &deco7renderer = Renderer::getInstance();
    decoSet.push_back(SDL_CreateTextureFromSurface(deco7renderer.sdlRenderer, sdeco7));

    SDL_Surface * sdeco8 = IMG_Load("../resources/deco/deco8.png");
    Renderer &deco8renderer = Renderer::getInstance();
    decoSet.push_back(SDL_CreateTextureFromSurface(deco8renderer.sdlRenderer, sdeco8));

    SDL_Surface * sdeco9 = IMG_Load("../resources/deco/deco9.png");
    Renderer &deco9renderer = Renderer::getInstance();
    decoSet.push_back(SDL_CreateTextureFromSurface(deco9renderer.sdlRenderer, sdeco9));

    SDL_Surface * sdeco10 = IMG_Load("../resources/deco/deco10.png");
    Renderer &deco10renderer = Renderer::getInstance();
    decoSet.push_back(SDL_CreateTextureFromSurface(deco10renderer.sdlRenderer, sdeco10));

    SDL_Surface * sdeco11 = IMG_Load("../resources/deco/deco11.png");
    Renderer &deco11renderer = Renderer::getInstance();
    decoSet.push_back(SDL_CreateTextureFromSurface(deco11renderer.sdlRenderer, sdeco11));

    SDL_Surface * sdeco12 = IMG_Load("../resources/deco/deco12.png");
    Renderer &deco12renderer = Renderer::getInstance();
    decoSet.push_back(SDL_CreateTextureFromSurface(deco12renderer.sdlRenderer, sdeco12));

    SDL_Surface * sdeco13 = IMG_Load("../resources/deco/deco13.png");
    Renderer &deco13renderer = Renderer::getInstance();
    decoSet.push_back(SDL_CreateTextureFromSurface(deco13renderer.sdlRenderer, sdeco13));

    SDL_Surface * sdeco14 = IMG_Load("../resources/deco/deco14.png");
    Renderer &deco14renderer = Renderer::getInstance();
    decoSet.push_back(SDL_CreateTextureFromSurface(deco14renderer.sdlRenderer, sdeco14));

    SDL_Surface * sdeco15 = IMG_Load("../resources/deco/deco15.png");
    Renderer &deco15renderer = Renderer::getInstance();
    decoSet.push_back(SDL_CreateTextureFromSurface(deco15renderer.sdlRenderer, sdeco15));

    SDL_Surface * sdeco16 = IMG_Load("../resources/deco/deco16.png");
    Renderer &deco16renderer = Renderer::getInstance();
    decoSet.push_back(SDL_CreateTextureFromSurface(deco16renderer.sdlRenderer, sdeco16));

    SDL_Surface * sdeco17 = IMG_Load("../resources/deco/deco17.png");
    Renderer &deco17renderer = Renderer::getInstance();
    decoSet.push_back(SDL_CreateTextureFromSurface(deco17renderer.sdlRenderer, sdeco17));

    SDL_Surface * sdeco18 = IMG_Load("../resources/deco/deco18.png");
    Renderer &deco18renderer = Renderer::getInstance();
    decoSet.push_back(SDL_CreateTextureFromSurface(deco18renderer.sdlRenderer, sdeco18));

    SDL_Surface * sdeco19 = IMG_Load("../resources/deco/deco19.png");
    Renderer &deco19renderer = Renderer::getInstance();
    decoSet.push_back(SDL_CreateTextureFromSurface(deco19renderer.sdlRenderer, sdeco19));

    SDL_Surface * sdeco20 = IMG_Load("../resources/deco/deco20.png");
    Renderer &deco20renderer = Renderer::getInstance();
    decoSet.push_back(SDL_CreateTextureFromSurface(deco20renderer.sdlRenderer, sdeco20));
}

SDL_Texture *DecoMapTextureHolder::getTextureWithIndex(int index) {
    return decoSet[index];
}

DecoMapTextureHolder &DecoMapTextureHolder::getInstance() {
    static DecoMapTextureHolder INSTANCE;
    return INSTANCE;
}
