//
// Created by niels on 4/27/21.
//

#ifndef INC_2DSIDESCROLLER_WALL_H
#define INC_2DSIDESCROLLER_WALL_H

#include <vector>
#include "Entity.h"

class Wall : public Entity {
public:
    Wall();
    Wall(int x, int y, int w, int h);
    virtual ~Wall();
    void update() override;
    void draw(Renderer renderer) override;
    void updatePlayerPos(int playerX, int playerY) override;
    void setPlatforms(std::vector<Entity *> platforms);
    void addPlatform(Entity * platform);

private:
    std::vector<Entity *> platforms;
};


#endif //INC_2DSIDESCROLLER_WALL_H
