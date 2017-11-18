#include "Map.h"
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
Map::Map() {
  for(int i = 0; i < 100; i++) {
    for(int j = 0; j < 100; j++) {
      srand(time(NULL));
      int terrain = rand()%10;
      switch(terrain) {
        case 0:
        tileArray[i][j] = Tile("grass"));
        break;
        case 1:
        tileArray[i][j] = Tile("plain"));
        break;
        case 2:
        tileArray[i][j] = Tile("hill"));
        break;
        case 3:
        tileArray[i][j] = Tile("rock"));
        break;
        case 4:
        tileArray[i][j] = Tile("snow"));
        break;
        case 5:
        tileArray[i][j] = Tile("desert"));
        break;
        case 6:
        tileArray[i][j] = Tile("lecture"));
        break;
        case 7:
        tileArray[i][j] = Tile("recitation"));
        break;
        case 8:
        tileArray[i][j] = Tile("unknown"));
        break;
        case 9:
        tileArray[i][j] = Tile("jungle"));
        break;
      }
    }
  }
}
Map::Map(string filename) {
  ifstream mapFile;
  mapFile.open(filename);
  if(mapFile.fail()) {
    cout << "could not load save data" << endl;
  }
  string line;
  getline(mapFile,line);
  for(int i = 0; i < 100; i++) {
    for(int j = 0; j < 100; j++) {
      getline(mapFile,line);
      tileArray[i][j] = Title(line));
    }
  }
  getline(mapFile,line);
  while(!mapFile.eof()) {
    getlint(mapFile,line);
    Enemy a(line);
    enemies.push_back(a);
  }
}
Map::~Map() {

}
void Map::saveData() {
  ofstream myMap;
  myMap.open("mapdata.txt");
  myMap << "tiles" << endl;
  for(int i = 0; i < 100; i++) {
    for(int j =0; j < 100; j++) {
      myMap << tileArray[i][j].getTerrain() << endl;
    }
  }
  myMap << "enemies" << endl;
  while(enemies.size() > 0) {
    myMap << enemies.at(enemies.end()).enemyStats() << endl;
    enemies.pop_back();
  }
}
string Map::getTileTerrain(int x, int y) {
  return tileArray[x][y].getTerrain();
}
Enemy Map::getEnemy(int x, int y) {
  for(int i = 0; i < enemies.size(); i++) {
    if(enemies[i].getX_pos() == x && enemies[i].getY_pos() == y) {
      return enemies[i];
    }
  }
}
void Map::removeEnemy(int x, int y) {
  for(int i = 0; i < enemies.size(); i++) {
    if(enemies[i].getX_pos() == x && enemies[i].getY_pos() == y) {
      enemies.erase(enemies.begin() + i);
      break;
    }
  }
}
Bool Map::isEmpty(int x, int y) {
  for(int i = 0; i < enemies.size(); i++) {
    if(enemies[i].getX_pos() == x && enemies[i].getY_pos() == y) {
      return false;
    }
  }
  return true;
}
int Map::getEnemySize() {
  return enemies.size();
}
