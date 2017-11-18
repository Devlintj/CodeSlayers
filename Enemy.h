#ifndef ENEMY_H
#define ENEMY_H
#include "Character.h"
#include <string>
class Enemy : Character{
  public:
    //constructor initalizing a enemy with a file to import stats, and and level.
    Enemy(std::string, int);
    Enemy(std::string);
    //empty constructer so I don't memory leak
    Enemy();
    ~Enemy();
    //function that sets enemy level
    void setLevel(int);
    //function returns as string of enemy stats
    std::string enemyStats();
  private:
    //function that adjusts stats based on level
    void adjustStats();
};
#endif
