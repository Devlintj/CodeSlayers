#include "Map.h"
#include "Tile.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <fstream>
Map::Map() {
  srand(time(NULL));
  for(int i = 0; i < 100; i++) {
    for(int j = 0; j < 100; j++) {
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
    Enemy * a = new Enemy(line);
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
  myMap << "tiles" << std::endl;
  for(int i = 0; i < 100; i++) {
    for(int j =0; j < 100; j++) {
      myMap << tileArray[i][j]->getTerrain() << std::endl;
    }
  }
  myMap << "enemies" << std::endl;
  int index = 0;
  while(enemies.size() > index) {
    myMap << enemies[index]->enemyStats() << std::endl;
    index++;
  }
}
std::string Map::getTileTerrain(int x, int y) {
  return tileArray[x][y]->getTerrain();
}
Enemy Map::getEnemy(int x, int y) {
  for(int i = 0; i < enemies.size(); i++) {
    if(enemies[i]->getX_pos() == x && enemies[i]->getY_pos() == y) {
      return *enemies[i];
    }
  }
}
void Map::removeEnemy(int x, int y) {
  for(int i = 0; i < enemies.size(); i++) {
    if(enemies[i]->getX_pos() == x && enemies[i]->getY_pos() == y) {
      enemies.erase(enemies.begin() + i);
      break;
    }
  }
}
bool Map::isEmpty(int x, int y) {
  for(int i = 0; i < enemies.size(); i++) {
    if(enemies[i]->getX_pos() == x && enemies[i]->getY_pos() == y) {
      return false;
    }
  }
  return true;
}
int Map::getEnemySize() {
  return enemies.size();
}
void Map::spawnEnemies() {
  srand(time(NULL));
  for(int i = 0; i < 100; i = i += 10) {
    for(int j = 0; j < 100; j = j += 10) {
      int opp = rand()%10;
      switch(opp) {
        case 0:
        enemies.push_back(new Enemy("EnemyStats.txt", "missing-curly-bracket"));
        enemies[enemies.size() - 1]->setLevel(rand()%20 + 1);
        enemies[enemies.size() - 1]->adjustStats();
        enemies[enemies.size() - 1]->setX_pos(i);
        enemies[enemies.size() - 1]->setY_pos(j);
        break;
        case 1:
        enemies.push_back(new Enemy("EnemyStats.txt", "uninitialized-variable"));
        enemies[enemies.size() - 1]->setLevel(rand()%20 + 1);
        enemies[enemies.size() - 1]->adjustStats();
        enemies[enemies.size() - 1]->setX_pos(i);
        enemies[enemies.size() - 1]->setY_pos(j);
        break;
        case 2:
        enemies.push_back(new Enemy("EnemyStats.txt", "segmentation-fault"));
        enemies[enemies.size() - 1]->setLevel(rand()%20 + 1);
        enemies[enemies.size() - 1]->adjustStats();
        enemies[enemies.size() - 1]->setX_pos(i);
        enemies[enemies.size() - 1]->setY_pos(j);
        break;
        case 3:
        enemies.push_back(new Enemy("EnemyStats.txt", "array-out-of-bounds"));
        enemies[enemies.size() - 1]->setLevel(rand()%20 + 1);
        enemies[enemies.size() - 1]->adjustStats();
        enemies[enemies.size() - 1]->setX_pos(i);
        enemies[enemies.size() - 1]->setY_pos(j);
        break;
        case 4:
        enemies.push_back(new Enemy("EnemyStats.txt", "poorly-named-variable"));
        enemies[enemies.size() - 1]->setLevel(rand()%20 + 1);
        enemies[enemies.size() - 1]->adjustStats();
        enemies[enemies.size() - 1]->setX_pos(i);
        enemies[enemies.size() - 1]->setY_pos(j);
        break;
        case 5:
        enemies.push_back(new Enemy("EnemyStats.txt", "what()stoi"));
        enemies[enemies.size() - 1]->setLevel(rand()%20 + 1);
        enemies[enemies.size() - 1]->adjustStats();
        enemies[enemies.size() - 1]->setX_pos(i);
        enemies[enemies.size() - 1]->setY_pos(j);
        break;
        case 6:
        enemies.push_back(new Enemy("EnemyStats.txt", "pseudo-code"));
        enemies[enemies.size() - 1]->setLevel(rand()%20 + 1);
        enemies[enemies.size() - 1]->adjustStats();
        enemies[enemies.size() - 1]->setX_pos(i);
        enemies[enemies.size() - 1]->setY_pos(j);
        break;
        case 7:
        enemies.push_back(new Enemy("EnemyStats.txt", "no-tty-present"));
        enemies[enemies.size() - 1]->setLevel(rand()%20 + 1);
        enemies[enemies.size() - 1]->adjustStats();
        enemies[enemies.size() - 1]->setX_pos(i);
        enemies[enemies.size() - 1]->setY_pos(j);
        break;
        case 8:
        enemies.push_back(new Enemy("EnemyStats.txt", "piazza-help-forum"));
        enemies[enemies.size() - 1]->setLevel(rand()%20 + 1);
        enemies[enemies.size() - 1]->adjustStats();
        enemies[enemies.size() - 1]->setX_pos(i);
        enemies[enemies.size() - 1]->setY_pos(j);
        break;
        case 9:
        enemies.push_back(new Enemy("EnemyStats.txt", "not-defined-in-scope"));
        enemies[enemies.size() - 1]->setLevel(rand()%20 + 1);
        enemies[enemies.size() - 1]->adjustStats();
        enemies[enemies.size() - 1]->setX_pos(i);
        enemies[enemies.size() - 1]->setY_pos(j);
        break;
      }
    }
  }
}
