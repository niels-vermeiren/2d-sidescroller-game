//
// Created by niels on 19.06.21.
//

#include <SDL2/SDL_image.h>
#include "LTexture.h"
#include "Renderer.h"

LTexture::LTexture(TTF_Font * gFont) {
    //Initialize
    this->gFont = gFont;
    mTexture = nullptr;
    mWidth = 0;
    mHeight = 0;
    mRenderer = &Renderer::getInstance();
    oldValue = "4";

}

LTexture::~LTexture()
{
    //Deallocate

}

bool LTexture::loadFromFile( std::string path )
{
    //Get rid of preexisting texture
    free();

    //The final texture
    SDL_Texture* newTexture = NULL;

    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    if( loadedSurface == NULL )
    {
        printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
    }
    else
    {
        //Color key image
        SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0xFF ) );

        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( mRenderer->sdlRenderer, loadedSurface );
        if( newTexture == nullptr )
        {
            printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
        }
        else
        {
            //Get image dimensions
            mWidth = loadedSurface->w;
            mHeight = loadedSurface->h;
        }

        //Get rid of old loaded surface
        SDL_FreeSurface( loadedSurface );
    }

    //Return success
    mTexture = newTexture;
    return mTexture != NULL;
}

bool LTexture::loadFromRenderedText(std::string textureText, SDL_Color textColor, Renderer *pRenderer)
{
    //Get rid of preexisting texture
    //freeChannels();\

    //Render text surface
    int x = textureText.compare(oldValue);
    if( textSurface == nullptr || x!=0 )
    {
        textSurface = TTF_RenderText_Solid( gFont, textureText.c_str(), textColor );
    }

    if( mTexture == nullptr || x!=0)
    {
        mTexture = SDL_CreateTextureFromSurface( mRenderer->sdlRenderer, textSurface );
    }
    mWidth = textSurface->w;
    mHeight = textSurface->h;
    oldValue = textureText;
    //Return success
    return mTexture != nullptr;
}

void LTexture::free()
{
    SDL_FreeSurface(textSurface);
    //Free texture if it exists
    if( mTexture != NULL )
    {
        SDL_DestroyTexture( mTexture );
        mTexture = NULL;
        mWidth = 0;
        mHeight = 0;
    }
}

void LTexture::setColor( Uint8 red, Uint8 green, Uint8 blue )
{
    //Modulate texture rgb
    SDL_SetTextureColorMod( mTexture, red, green, blue );
}

void LTexture::setBlendMode( SDL_BlendMode blending )
{
    //Set blending function
    SDL_SetTextureBlendMode( mTexture, blending );
}

void LTexture::setAlpha( Uint8 alpha )
{
    //Modulate texture alpha
    SDL_SetTextureAlphaMod( mTexture, alpha );
}

void LTexture::render( int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip )
{
    //Set rendering space and render to screen
    SDL_Rect renderQuad = { x, y, mWidth, mHeight };

    //Set clip rendering dimensions
    if( clip != NULL )
    {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }

    //Render to screen
    SDL_RenderCopyEx( mRenderer->sdlRenderer, mTexture, clip, &renderQuad, angle, center, flip );
}

int LTexture::getWidth()
{
    return mWidth;
}

int LTexture::getHeight()
{
    return mHeight;
}