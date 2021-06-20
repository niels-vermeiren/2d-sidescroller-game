//
// Created by niels on 11.06.21.
//

#ifndef INC_2DSIDESCROLLER_DECOSPRITE_H
#define INC_2DSIDESCROLLER_DECOSPRITE_H


#include "StaticSprite.h"

class DecoSprite : public StaticSprite {
public:
    DecoSprite(int index);
    static SDL_Point getsize(SDL_Texture *sdlTexture);
    void load() override;
    void loadToTexture() override;
    ~DecoSprite() override;
    void draw(Renderer renderer, SDL_Rect * pRect, SDL_Rect * clipRect, SDL_RendererFlip flip) override;

private:
    SDL_Texture * texture;
    int index;
};


#endif //INC_2DSIDESCROLLER_DECOSPRITE_H
