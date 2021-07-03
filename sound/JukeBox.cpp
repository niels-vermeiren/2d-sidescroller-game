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
    Mix_AllocateChannels(16);
    Mix_OpenAudio(96000, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);

    Mix_Chunk * ee = Mix_LoadWAV("../resources/sounds/background.mp3");
    music.push_back({ee, true});

   chunk = Mix_LoadWAV("../resources/sounds/coin.wav");
    sound_effects.push_back({chunk, false});

    Mix_Chunk * laser = Mix_LoadWAV("../resources/sounds/laser.wav");
    sound_effects.push_back({laser, false});

    Mix_Chunk * mageAttack = Mix_LoadWAV("../resources/sounds/mage-attack.mp3");
    sound_effects.push_back({mageAttack, false});

    Mix_Chunk * damage = Mix_LoadWAV("../resources/sounds/damage.mp3");
    sound_effects.push_back({damage, false});

    Mix_Chunk * slashing = Mix_LoadWAV("../resources/sounds/slashing.mp3");
    sound_effects.push_back({slashing, false});

    Mix_Chunk * skeletonHit = Mix_LoadWAV("../resources/sounds/skeleton-hit.mp3");
    sound_effects.push_back({skeletonHit, false});

    for (int i = 1; i < 16; ++i) {
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
    JukeBox::freeChannels.remove(channel);
    freeChannels.push_front(channel);
}

void JukeBox::playSound(int sound, bool isSoundEffect) {
    int &channel = JukeBox::freeChannels.front();
    JukeBox::freeChannels.remove(channel);
    Mix_HaltChannel(channel);
    if(sound == 0) {
        Mix_PlayChannelTimed(channel, sound_effects[sound].first, 0, 250);
    } else {
        Mix_PlayChannelTimed(channel, sound_effects[sound].first, 0, 700);
    }
    Mix_ChannelFinished(JukeBox::channelFinished);
    freeChannels.push_back(channel);
}

void JukeBox::playMusic(int sound) {
    int &channel = JukeBox::freeChannels.front();
    JukeBox::freeChannels.remove(channel);
    Mix_PlayChannelTimed(channel, music[sound].first, 1000, -1);
    Mix_ChannelFinished(JukeBox::channelFinished);
}