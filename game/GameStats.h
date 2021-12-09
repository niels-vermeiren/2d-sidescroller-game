//
// Created by niels on 08.12.21.
//

#ifndef INC_2DSIDESCROLLER_GAMESTATS_H
#define INC_2DSIDESCROLLER_GAMESTATS_H


class GameStats {

public:
    int getCoins() const;
    void setCoins(int coins);
    int getDeaths() const;
    void setDeaths(int deaths);
    void addCoins(int coins);
    void addDeath();
    static GameStats & getInstance();
private:
    int coins = 0;
    int deaths = 0;
};


#endif //INC_2DSIDESCROLLER_GAMESTATS_H
