#ifndef MAP_H
#define MAP_H
#include "Enemy.h"
#include "Tile.h"
#include <vector>
#include <string>
class Map{
  public:
    //This Map constructor takes no parameters and will construct the map at random (start of game)
    Map();
    //The Map will load in all the data from a sava game
    Map(std::string);
    ~Map();
    //saves data of tiles and characters in a csv file
    void saveData();
    //function that returns the tile's string from the tile multidimensional vector
    std::string getTileTerrain(int, int);
    //function that return enemy from the enemy vector at a position.
    Enemy getEnemy(int, int);
    //function that removes enemy from array at that x,y position.
    void removeEnemy(int, int);
    //function that checks if spot in character array is empty
    bool isEmpty(int, int);
    //function that returns how many enemies are left
    int getEnemySize();
  private:
    //multidimensional tiles of the map
    Tile tileArray[100][100];
    //character position of the map
    std::vector<Enemy> enemies;

};
#endif
