//
// Created by niels on 12.06.21.
//

#ifndef INC_2DSIDESCROLLER_PLAYERSTATS_H
#define INC_2DSIDESCROLLER_PLAYERSTATS_H


class PlayerStats {
public:
    PlayerStats();
    static PlayerStats &getInstance();
    void takeDamage(float damage);
    void addCoin(int amount);
    float getHealth() const;
    int getCoins() const;

    void setHealth(float health);

    void setCoins(int coins);

private:
    float health;
    int coins;
};


#endif //INC_2DSIDESCROLLER_PLAYERSTATS_H
