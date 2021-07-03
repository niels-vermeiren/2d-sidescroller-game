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
    void loadShared(SDL_mutex * mutex, std::string level);
    void load(SDL_mutex * mutex, std::string level);
    void loadTextures(std::string level);
    static LevelLoader * getLevel(std::string level = "");
    static void reset();
    static void levelUp();
    static void levelDown();
private:
    static LevelLoader * level1;
    static LevelLoader * level2;
    static LevelLoader * level3;
    static LevelLoader * testlevel;
    static int currentLevel;
    Player * player;
};


#endif //INC_2DSIDESCROLLER_LEVEL_H
