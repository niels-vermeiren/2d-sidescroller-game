//
// Created by niels on 5/10/21.
//

#ifndef INC_2DSIDESCROLLER_MAPREADER_H
#define INC_2DSIDESCROLLER_MAPREADER_H
#include "../defs.h"
#include <string>
#include <vector>

class MapReader {
public:
    MapReader();
    std::vector<std::vector<int>>read(const std::string& path);
};


#endif //INC_2DSIDESCROLLER_MAPREADER_H
