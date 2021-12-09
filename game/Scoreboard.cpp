//
// Created by niels on 08.12.21.
//

#include "Scoreboard.h"
#include "Window.h"
#include "GameStats.h"

void Scoreboard::draw() {
    char buff[250];
    snprintf(buff, sizeof(buff), " Total coins gathered: %d", GameStats::getInstance().getCoins());
    std::string totalcoins = buff;

    char buffD[250];
    snprintf(buffD, sizeof(buffD), " Total deaths: %d", GameStats::getInstance().getDeaths());
    std::string totaldeaths = buffD;

    successText->loadFromRenderedText("Well done! You cleared the game!" , {255, 255, 255});
    totalCoins->loadFromRenderedText(totalcoins , {255, 255, 255});
    totalDeaths->loadFromRenderedText(totaldeaths , {255, 255, 255});
    successText->render(SCREEN_WIDTH - SCREEN_WIDTH / 2 - successText->getWidth() / 2, SCREEN_HEIGHT - SCREEN_HEIGHT / 2 - successText->getHeight() / 2 + 200);
    totalCoins->render(SCREEN_WIDTH - SCREEN_WIDTH / 2 - totalCoins->getWidth() / 2, SCREEN_HEIGHT - SCREEN_HEIGHT / 2 - totalCoins->getHeight() / 2 + 275);
    totalDeaths->render(SCREEN_WIDTH - SCREEN_WIDTH / 2 - totalDeaths->getWidth() / 2, SCREEN_HEIGHT - SCREEN_HEIGHT / 2 - totalDeaths->getHeight() / 2 + 325);

}

Scoreboard::Scoreboard() {
    TTF_Init();
    TTF_Font * sFont = TTF_OpenFont( "../resources/font/trulymadly.ttf", 40 );
    TTF_Font * gFont = TTF_OpenFont( "../resources/font/trulymadly.ttf", 28 );
    successText = new LTexture(sFont);
    totalCoins = new LTexture(gFont);
    totalDeaths = new LTexture(gFont);
}
