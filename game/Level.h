//
// Created by niels on 21.06.21.
//

#ifndef INC_2DSIDESCROLLER_LEVEL_H
#define INC_2DSIDESCROLLER_LEVEL_H


#include "LevelLoader.h"

class Level {
public:
    Level();
    void draw();
    void update();
    void handleCollisions();
    void load(SDL_mutex * mutex);
    void loadTextures();
    static void reset();
    static void levelUp();
    static void levelDown();
private:
    static LevelLoader * level1;
    static LevelLoader * level2;
    static LevelLoader * testlevel;
    static int currentLevel;
};


#endif //INC_2DSIDESCROLLER_LEVEL_H
