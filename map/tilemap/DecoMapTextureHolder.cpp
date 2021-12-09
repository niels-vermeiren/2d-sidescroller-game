//
// Created by niels on 11.06.21.
//

#include <SDL2/SDL_image.h>
#include <iostream>
#include "DecoMapTextureHolder.h"
DecoMapTextureHolder::DecoMapTextureHolder() {

}

SDL_Texture *DecoMapTextureHolder::getTextureWithIndex(int index) {
    if (index < 0) return decoSet[0];
    return decoSet[index];
}

void DecoMapTextureHolder::load() {
    SDL_Surface * sdeco1 = IMG_Load("../resources/deco/deco1.png");
    decoSurfaces.push_back(sdeco1);

    SDL_Surface * sdeco2 = IMG_Load("../resources/deco/deco2.png");
    decoSurfaces.push_back(sdeco2);

    SDL_Surface * sdeco3 = IMG_Load("../resources/deco/deco3.png");
    decoSurfaces.push_back(sdeco3);

    SDL_Surface * sdeco4 = IMG_Load("../resources/deco/deco4.png");
    decoSurfaces.push_back(sdeco4);

    SDL_Surface * sdeco5 = IMG_Load("../resources/deco/deco5.png");
    decoSurfaces.push_back(sdeco5);

    SDL_Surface * sdeco6 = IMG_Load("../resources/deco/deco6.png");
    decoSurfaces.push_back(sdeco6);

    SDL_Surface * sdeco7 = IMG_Load("../resources/deco/deco7.png");
    decoSurfaces.push_back(sdeco7);

    SDL_Surface * sdeco8 = IMG_Load("../resources/deco/deco8.png");
    decoSurfaces.push_back(sdeco8);

    SDL_Surface * sdeco9 = IMG_Load("../resources/deco/deco9.png");
    decoSurfaces.push_back(sdeco9);

    SDL_Surface * sdeco10 = IMG_Load("../resources/deco/deco10.png");
    decoSurfaces.push_back(sdeco10);

    SDL_Surface * sdeco11 = IMG_Load("../resources/deco/deco11.png");
    decoSurfaces.push_back(sdeco11);

    SDL_Surface * sdeco12 = IMG_Load("../resources/deco/deco12.png");
    decoSurfaces.push_back(sdeco12);

    SDL_Surface * sdeco13 = IMG_Load("../resources/deco/deco13.png");
    decoSurfaces.push_back(sdeco13);

    SDL_Surface * sdeco14 = IMG_Load("../resources/deco/deco14.png");
    decoSurfaces.push_back(sdeco14);

    SDL_Surface * sdeco15 = IMG_Load("../resources/deco/deco15.png");
    decoSurfaces.push_back(sdeco15);

    SDL_Surface * sdeco16 = IMG_Load("../resources/deco/deco16.png");
    decoSurfaces.push_back(sdeco16);

    SDL_Surface * sdeco17 = IMG_Load("../resources/deco/deco17.png");
    decoSurfaces.push_back(sdeco17);

    SDL_Surface * sdeco18 = IMG_Load("../resources/deco/deco18.png");
    decoSurfaces.push_back(sdeco18);

    SDL_Surface * sdeco19 = IMG_Load("../resources/deco/deco19.png");
    decoSurfaces.push_back(sdeco19);

    SDL_Surface * sdeco20 = IMG_Load("../resources/deco/deco20.png");
    decoSurfaces.push_back(sdeco20);
}

void DecoMapTextureHolder::loadToTexture() {
   // DecoMapTextureHolder::decoSet.clear();
    for(int i = 0 ; i!= decoSurfaces.size();i++) {
        auto texture = SDL_CreateTextureFromSurface(Renderer::getInstance().sdlRenderer, decoSurfaces[i]);
        decoSet.push_back(texture);
    }
}

DecoMapTextureHolder::~DecoMapTextureHolder() {

}
