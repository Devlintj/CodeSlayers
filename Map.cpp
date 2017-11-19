#include "Map.h"
#include "Tile.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <fstream>
Map::Map() {
  srand(time(NULL));
  Enemy * temp = new Enemy();
  for(int i = 0; i < 100; i++) {
    for(int j = 0; j < 100; j++) {
      int terrain = rand()%10;
      switch(terrain) {
        case 0:
        tileArray[i][j] = new Tile("grass");
        if(rand()%10 == 1) {
          delete temp;
          temp =  new Enemy("missing-curly-bracket");
        }
        break;
        case 1:
        tileArray[i][j] = new Tile("plain");
        if(rand()%10 == 1) {
          delete temp;
          temp =  new Enemy("uninitialized-variable");
        }
        break;
        case 2:
        tileArray[i][j] = new Tile("hill");
        if(rand()%10 == 1) {
          delete temp;
          temp =  new Enemy("segmentation-fault");
        }
        break;
        case 3:
        tileArray[i][j] = new Tile("rock");
        if(rand()%10 == 1) {
          delete temp;
          temp =  new Enemy("array-out-of-bounds");
        }
        break;
        case 4:
        tileArray[i][j] = new Tile("snow");
        if(rand()%10 == 1) {
          delete temp;
          temp =  new Enemy("poorly-named-variable");
        }
        break;
        case 5:
        tileArray[i][j] = new Tile("desert");
        if(rand()%10 == 1) {
          delete temp;
          temp =  new Enemy("what()stoi");
        }
        break;
        case 6:
        tileArray[i][j] = new Tile("lecture");
        if(rand()%10 == 1) {
          delete temp;
          temp =  new Enemy("pseudo-code");
        }
        break;
        case 7:
        tileArray[i][j] = new Tile("recitation");
        if(rand()%10 == 1) {
          delete temp;
          temp =  new Enemy("no-tty-present");
        }
        break;
        case 8:
        tileArray[i][j] = new Tile("unknown");
        if(rand()%10 == 1) {
          delete temp;
          temp =  new Enemy("piazza-help-forum");
        }
        break;
        case 9:
        tileArray[i][j] = new Tile("jungle");
        if(rand()%10 == 1) {
          delete temp;
          temp =  new Enemy("not-defined-in-scope");
        }
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
  myMap << "enemies" << '\n';
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
