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

//Texture wrapper class
class LTexture {
public:
    //Initializes variables
    LTexture(TTF_Font * gFont);

    //Deallocates memory
    ~LTexture();

    //Loads image at specified path
    bool loadFromFile( std::string path );


    //Creates image from font string
    bool loadFromRenderedText(std::string textureText, SDL_Color textColor, Renderer *pRenderer);

    //Deallocates texture
    void free();

    //Set color modulation
    void setColor( Uint8 red, Uint8 green, Uint8 blue );

    //Set blending
    void setBlendMode( SDL_BlendMode blending );

    //Set alpha modulation
    void setAlpha( Uint8 alpha );

    //Renders texture at given point
    void render( int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE );

    //Gets image dimensions
    int getWidth();
    int getHeight();

private:
    //The actual hardware texture
    std::string oldValue;
    SDL_Texture* mTexture;
    SDL_Surface  * textSurface;
    Renderer * mRenderer;
    //Image dimensions
    int mWidth;
    int mHeight;
    //font
    //Globally used font
    TTF_Font *gFont = NULL;

};


#endif //INC_2DSIDESCROLLER_LTEXTURE_H
