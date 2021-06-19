//
// Created by niels on 12.06.21.
//

#include "CoinMenuSprite.h"
#include "../background/Background.h"
#include "../stats/PlayerStats.h"

CoinMenuSprite::~CoinMenuSprite() {
    SDL_DestroyTexture(holder);
    lTexture->free();
}
CoinMenuSprite::CoinMenuSprite() {
    this->surface = IMG_Load("../resources/stats/coins/coin_menu.png");
    this->holder = SDL_CreateTextureFromSurface(Renderer::getInstance().sdlRenderer,surface);
    TTF_Init();
    TTF_Font * gFont = TTF_OpenFont( "/home/niels/Projects/2d-sidescroller-game/resources/opensans.ttf", 28 );
    lTexture = new LTexture(gFont);
    SDL_FreeSurface(surface);


}

void CoinMenuSprite::draw(Renderer renderer, SDL_Rect *pRect, SDL_Rect *clipRect, SDL_RendererFlip flip) {
    SDL_Point p = {0,0};
    SDL_RenderCopyEx(renderer.sdlRenderer, holder, clipRect, pRect, 0.0, &p, flip);
    int currentCoins = PlayerStats::getInstance().getCoins();
    std::string newCoins = std::to_string(currentCoins);
    //Render text
    SDL_Color textColor = { 236, 230, 50 , 220};

    lTexture->loadFromRenderedText(newCoins , textColor, &renderer);
    lTexture->render( -Background::getInstance().getVpRect()->x+98, -Background::getInstance().getVpRect()->y + 103);

}