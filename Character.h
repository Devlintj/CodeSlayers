#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
#include "ItemsAndMoves.h"
class Character{
  public:
    //default constructor to fix inheritence issues
    Character();
    ~Character();
    //function to receiveDamage from another character
    void receiveDamage(int);
    //function that returns character's strength
    int getHealth();
    //function that returns character's strength
    int getStrength();
    //function that returns character's armor
    int getArmor();
    //function that returns character's level
    int getLevel();
    //function that returns character's name
    std::string getName();
    //function the couts move names and stats
    void outputMoves();
    int getX_pos();
    int getY_pos();
    void setX_pos(int);
    void setY_pos(int);
    //array of structure move
    Move moves[4];
  protected:
    int health;
    int strength;
    int armor;
    int level;
    int x_pos;
    int y_pos;
    std::string name;
};
#endif
