//
// Created by niels on 20.06.21.
//

#include <iostream>
#include "JukeBox.h"
std::list<int> JukeBox::freeChannels;
Mix_Chunk * JukeBox::chunk;

JukeBox * JukeBox::getInstance() {
    static JukeBox INSTANCE;
    return &INSTANCE;
}

void JukeBox::loadSounds() {
    Mix_AllocateChannels(10);
    Mix_OpenAudio(96000, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);

    Mix_Chunk * ee = Mix_LoadWAV("../resources/sounds/background.mp3");
    music.push_back({ee, true});


   chunk = Mix_LoadWAV("../resources/sounds/coin.wav");
   sound_effects.push_back({chunk, false});
    for (int i = 2; i < 10; ++i) {
        JukeBox::freeChannels.push_back(i + 1);
    }
}

JukeBox::~JukeBox() {
    for(auto track: music) {
        Mix_FreeChunk(track.first);
    }
    Mix_CloseAudio();
}

void JukeBox::channelFinished(int channel) {

    freeChannels.push_front(channel);
}

void JukeBox::playSound(int sound, bool isSoundEffect) {


    int &channel = JukeBox::freeChannels.front();
    JukeBox::freeChannels.remove(channel);

    Mix_PlayChannelTimed(channel, sound_effects[sound].first, 0, 300);
    Mix_ChannelFinished(JukeBox::channelFinished);
}

void JukeBox::playMusic(int sound) {
    int &channel = JukeBox::freeChannels.front();
    JukeBox::freeChannels.remove(channel);
    Mix_PlayChannelTimed(channel, music[sound].first, 4, -1);
    Mix_ChannelFinished(JukeBox::channelFinished);
}