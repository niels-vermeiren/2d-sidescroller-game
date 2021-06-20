//
// Created by niels on 20.06.21.
//

#ifndef INC_2DSIDESCROLLER_JUKEBOX_H
#define INC_2DSIDESCROLLER_JUKEBOX_H


#include <SDL2/SDL_mixer.h>
#include <unordered_map>
#include <vector>
#include <list>

class JukeBox {
public:
    static JukeBox * getInstance();
    virtual ~JukeBox();
    void loadSounds();
    static std::list<int> freeChannels;

    void playSound(int sound, bool isSoundEffect);
    void playMusic(int sound);
    //MUSIC
    static const int BACKGROUND = 0;
    //SOUND_EFFECT
    static const int COIN = 0;
private:
    std::vector<std::pair<Mix_Chunk *, bool>> music;
    std::vector<std::pair<Mix_Chunk *, bool>> sound_effects;
    int currentChannel = 0;
    static Mix_Chunk * chunk;
    static void channelFinished(int channel);
};


#endif //INC_2DSIDESCROLLER_JUKEBOX_H
