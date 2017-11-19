#include "Map.h"
#include "Tile.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <fstream>
Map::Map() {
  for(int i = 0; i < 100; i++) {
    for(int j = 0; j < 100; j++) {
      srand(time(NULL));
      int terrain = rand()%10;
      switch(terrain) {
        case 0:
        tileArray[i][j] = new Tile("grass");
        break;
        case 1:
        tileArray[i][j] = new Tile("plain");
        break;
        case 2:
        tileArray[i][j] = new Tile("hill");
        break;
        case 3:
        tileArray[i][j] = new Tile("rock");
        break;
        case 4:
        tileArray[i][j] = new Tile("snow");
        break;
        case 5:
        tileArray[i][j] = new Tile("desert");
        break;
        case 6:
        tileArray[i][j] = new Tile("lecture");
        break;
        case 7:
        tileArray[i][j] = new Tile("recitation");
        break;
        case 8:
        tileArray[i][j] = new Tile("unknown");
        break;
        case 9:
        tileArray[i][j] = new Tile("jungle");
        break;
      }
    }
  }
}
Map::Map(std::string filename) {
  std::ifstream mapFile;
  mapFile.open(filename);
  if(mapFile.fail()) {
    std::cout << "could not load save data" << std::endl;
  }
  std::string line;
  std::getline(mapFile,line);
  for(int i = 0; i < 100; i++) {
    for(int j = 0; j < 100; j++) {
      std::getline(mapFile,line);
      tileArray[i][j] = new Tile(line);
    }
  }
  std::getline(mapFile,line);
  while(!mapFile.eof()) {
    getline(mapFile,line);
    Enemy a(line);
    enemies.push_back(a);
  }
}
Map::~Map() {
  for(int i = 0; i < 100; i++) {
    for(int j = 0; j < 100; j++) {
      delete tileArray[i][j];
    }
  }
}
void Map::saveData() {
  std::ofstream myMap;
  myMap.open("mapdata.txt");
  myMap << "tiles" << '\n';
  for(int i = 0; i < 100; i++) {
    for(int j =0; j < 100; j++) {
      myMap << tileArray[i][j]->getTerrain() << '\n';
    }
  }
  myMap << "enemies" << 'n';
  while(enemies.size() > 0) {
    myMap << enemies.back().enemyStats() << '\n';
    enemies.pop_back();
  }
}
std::string Map::getTileTerrain(int x, int y) {
  return tileArray[x][y]->getTerrain();
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
bool Map::isEmpty(int x, int y) {
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
