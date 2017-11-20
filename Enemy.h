#ifndef ENEMY_H
#define ENEMY_H
#include <string>
#include "Character.h"
class Player;
class Enemy : public Character{
  public:
    //constructor initalizing a enemy with a file to import stats, and and level.
    Enemy(std::string, std::string);
    Enemy(std::string);
    //empty constructer so I don't memory leak
    Enemy();
    ~Enemy();
    //function to attack player
    void attack(Player*, int);
    //function that sets enemy level
    void setLevel(int);
    //function returns as string of enemy stats
    std::string enemyStats();
    //function that adjusts stats based on level
    void adjustStats();
};
#endif
