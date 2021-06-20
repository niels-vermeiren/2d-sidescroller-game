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
    void draw(Renderer renderer) override;
    void setPlatforms(std::vector<Entity *> tiles);

    const std::vector<Entity *> &getPlatforms() const;

    ~Wall() override;
private:
    std::vector<Entity *> platforms;
};


#endif //INC_2DSIDESCROLLER_WALL_H
