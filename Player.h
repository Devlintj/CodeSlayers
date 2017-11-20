#ifndef PLAYER_H
#define PLAYER_H
#include "Character.h"
class Enemy;
#include <string>
#include <vector>
class Player : public Character{
  public:
    //constructor initalizing a player with a file to import stats and level.
    Player(std::string);
    ~Player();
    //function to attack another player with a certain attack
    void attack(Enemy*, std::string);
    //function that adds item to item vector
    void addItem(std::string, int);
    //function that allows the player to use an item
    void useItem(std::string);
    //modifies health, strength, and armor of player when they gain enough exp
    void levelUp();
    //function that checks if player has enough exp to level up
    bool canLevelUp(int);
    //function that saves player data into a file
    void savePlayerData();
    //function that returns a string of the players stats
    std::string playerStats();
    //function that couts all your items names
    void outputItems();
    //function that returns exp
    int getExp();
    //function that adds exp based on opponent level
    void addExp(int);
  private:
    int exp;
    //vector to keep items
    std::vector<Item> items;
    //function to find an item in the items vector by returning index. returns -1 if not found.
    int findItem(std::string);
    //function that return the index of that move in the move array. returns -1 if not found.
    int findMove(std::string);

};
#endif
