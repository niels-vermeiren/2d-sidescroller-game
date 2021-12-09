//
// Created by niels on 19.06.21.
//

#include <SDL2/SDL_image.h>
#include "LTexture.h"
#include "Renderer.h"

LTexture::LTexture(TTF_Font * gFont) {
    this->gFont = gFont;
    mTexture = nullptr;
    mWidth = 0;
    mHeight = 0;
    mRenderer = &Renderer::getInstance();
    oldValue = "4";

}

LTexture::~LTexture(){
}

bool LTexture::loadFromRenderedText(std::string textureText, SDL_Color textColor) {
    int x = textureText.compare(oldValue);
    if( textSurface == nullptr || x!=0 ) {
        textSurface = TTF_RenderText_Solid( gFont, textureText.c_str(), textColor );
    }

    if( mTexture == nullptr || x!=0){
        mTexture = SDL_CreateTextureFromSurface( mRenderer->sdlRenderer, textSurface );
    }
    mWidth = textSurface->w;
    mHeight = textSurface->h;
    oldValue = textureText;
    return mTexture != nullptr;
}

void LTexture::free(){
    SDL_FreeSurface(textSurface);
    if( mTexture != NULL ){
        SDL_DestroyTexture( mTexture );
        mTexture = NULL;
        mWidth = 0;
        mHeight = 0;
    }
}

void LTexture::render( int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip ) {
    SDL_Rect renderQuad = { x, y, mWidth, mHeight };
    if( clip != NULL ) {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }
    SDL_RenderCopyEx( mRenderer->sdlRenderer, mTexture, clip, &renderQuad, angle, center, flip );
}

int LTexture::getWidth() {
    return mWidth;
}

int LTexture::getHeight() {
    return mHeight;
}