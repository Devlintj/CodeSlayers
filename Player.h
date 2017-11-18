#ifndef PLAYER_H
#define PLAYER_H
class Player : Character{
  public:
    //constructor initalizing a player with a file to import stats and level.
    Player(string);
    ~Player();
    //function to attack another player with a certain attack
    void attack(Character, string);
    //function that adds item to item vector
    void addItem(string);
    //function that allows the player to use an item
    void useItem(string);
    //modifies health, strength, and armor of player when they gain enough exp
    void levelUp();
    //function that checks if player has enough exp to level up
    bool canLevelUp(int);
    //function that saves player data into a file
    void savePlayerData(string);
    //function that returns a string of the players stats
    string playerStats();
    //function that couts all your items names
    void outputItems();
  private:
    int exp;
    //vector to keep items
    vector<Item> items;
    //function to find an item in the items vector by returning index. returns -1 if not found.
    int findItem(string);
    //function that return the index of that move in the move array. returns -1 if not found.
    int findMove(string);

};
#endif
