//
// Created by niels on 4/14/21.
//

#ifndef INC_2DSIDESCROLLER_ANIMATIONDATA_H
#define INC_2DSIDESCROLLER_ANIMATIONDATA_H
#include <string>
#include <vector>
#include "SDL2/SDL.h"
#include <SDL2/SDL_image.h>

class AnimationData {
public:
    AnimationData();
    AnimationData(std::string filePath, int totalFrames, int delay);
    AnimationData(std::string filePath, int totalFrames, int delay, bool repeat);
    void reset();
    SDL_Surface * getNextFrame();
    virtual ~AnimationData();

private:
    std::vector<SDL_Surface *> images;
    int currentFrame = 0;
    int totalFrames{};
    int delay = 2;
    int tick = 0;
    bool repeat = true;
};

#endif //INC_2DSIDESCROLLER_ANIMATIONDATA_H
