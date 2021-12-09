//
// Created by niels on 19.06.21.
//

#ifndef INC_2DSIDESCROLLER_LTEXTURE_H
#define INC_2DSIDESCROLLER_LTEXTURE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <string>
#include <cmath>
#include "Renderer.h"

class LTexture {
public:
    LTexture(TTF_Font * gFont);
    ~LTexture();
    bool loadFromRenderedText(std::string textureText, SDL_Color textColor);
    void free();
    void render( int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE );
    int getWidth();
    int getHeight();

private:
    std::string oldValue;
    SDL_Texture* mTexture;
    SDL_Surface  * textSurface;
    Renderer * mRenderer;
    int mWidth;
    int mHeight;
    TTF_Font *gFont = NULL;
};


#endif //INC_2DSIDESCROLLER_LTEXTURE_H
