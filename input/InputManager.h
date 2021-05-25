//
// Created by niels on 4/11/21.
//

#ifndef INC_2DSIDESCROLLER_INPUTMANAGER_H
#define INC_2DSIDESCROLLER_INPUTMANAGER_H


#include <SDL2/SDL.h>
#include <map>

class InputManager {
public:
    static void renew();
    static bool keyDown(Uint8 key);
    static bool keyUp(Uint8 key);
    static bool keyPressed(Uint8 key);
    static void setKeyUp(Uint8 key);
    static void setKeyDown(Uint8 key);

private:
    static std::map<int, bool> keys;
    static std::map<int, bool> old_keys;
};


#endif //INC_2DSIDESCROLLER_INPUTMANAGER_H
