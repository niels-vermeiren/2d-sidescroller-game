//
// Created by niels on 5/10/21.
//

#include <fstream>
#include <sstream>
#include "MapReader.h"

MapReader::MapReader() {

}

std::vector<std::vector<int>>MapReader::read(const std::string& path) {
    std::string line;
    std::ifstream file (path);
    std::vector<std::vector<int>> array2D;
    if (file.is_open()) {
        while ( getline (file,line) ) {
            std::stringstream string_stream(line);
            std::vector<int> rowArray;
            while(string_stream.good()) {
                std::string a;
                getline( string_stream, a, ',' );
                int index = std::stoi(a);
                rowArray.push_back(index);
            }
            array2D.push_back(rowArray);
        }
        file.close();
    }
    return array2D;
}
