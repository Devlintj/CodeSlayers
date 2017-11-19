#include "CodeSlayers.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
CodeSlayers::CodeSlayers() {
  fun_counter = 100;
  char start = 'a';
  while(start != 'n' || start != 'l') {
    std::string line;
    std::cout << "would you like to play a new game or load a previous one? press and enter 'n' for a new game, and 'l' to load a saved game" << std::endl;
    std::cin >> line;
    if(line[0] == 'n') {
      map = new Map();
      player = new Player("playerStats.txt");
    }
    if(line[0] == 'l') {
      map = new Map("mapdata.txt");
      player = new Player("savedPlayerStats.txt");
    }
    opponent = new Enemy();
    boss = new Enemy("EnemyStats.txt", "cog");
  }
}
CodeSlayers::~CodeSlayers() {
  delete opponent;
  delete player;
  delete boss;
  delete map;
}
void CodeSlayers::playGame() {
  introText();
  while(map->getEnemySize() > 0) {
    std::cout << "what do you wish to do?" << std::endl;
    std::string line;
    std::cin >> line;
    char action = line[0];
    switch(action) {
      case 'n':
      movePlayer('n');
      break;
      case 'e':
      movePlayer('e');
      break;
      case 's':
      movePlayer('s');
      break;
      case 'w':
      movePlayer('w');
      break;
      case 'f':
      if(!map->isEmpty(player->getX_pos(), player->getY_pos())) {
        fight();
      }
      break;
      case 'i':
      showStats();
      break;
      case 'q':
      saveGame();
      break;
    }
  }
  bossFight();
}
void CodeSlayers::fight() {
  loadOpponent();
  int turnCount = 1;
  while(!isDead() && !gameOver()) {
    if(turnCount%2 == 0) {
      srand(time(NULL));
      int att = rand()%4;
      opponent->attack(player, att);
      std::cout << opponent->getName() << " attacks with " << opponent->moves[att].name << std::endl;
    }
  }
  if(isDead()) {
    map->removeEnemy(player->getX_pos(), player->getY_pos());
  }
  if(gameOver()) {
    exit (0);
  }
  fun_counter -= 50;
}
void CodeSlayers::bossFight() {

}
void CodeSlayers::movePlayer(char direction) {
  switch(direction) {
    case 'w':
    if(player->getX_pos() > 0) {
      player->setX_pos(player->getX_pos() - 1);
    }
    break;
    case 'e':
    if(player->getX_pos() < 99) {
      player->setX_pos(player->getX_pos() + 1);
    }
    break;
    case 'n':
    if(player->getY_pos() > 0) {
      player->setX_pos(player->getY_pos() - 1);
    }
    break;
    case 's':
    if(player->getY_pos() < 99) {
      player->setX_pos(player->getY_pos() + 1);
    }
    break;
  }
}
int CodeSlayers::getFun_Counter() {
  return fun_counter;
}
void CodeSlayers::loadOpponent() {
  delete opponent;
  opponent = new Enemy(map->getEnemy(player->getX_pos(), player->getY_pos()));
}
bool CodeSlayers::isDead() {
  if(opponent->getHealth() <= 0) {
    return true;
  }
  return false;
}
bool CodeSlayers::bossIsDead() {
  if(boss->getHealth() <= 0) {
    return true;
  }
  return false;
}
bool CodeSlayers::gameOver() {
  if(player->getHealth() <= 0) {
    return true;
  }
  return false;
}
void CodeSlayers::showStats() {
  std::cout << "Name: " << player->getName() << std::endl;
  std::cout << "Strength: " << player->getStrength() << std::endl;
  std::cout << "Armor: " << player->getArmor() << std::endl;
  std::cout << "Health: " << player->getHealth() << std::endl;
  std::cout << "Level: " << player->getLevel() << std::endl;
  std::cout << "Exp til next level: " << expLevelUp - player->getExp() << std::endl;
  player->outputMoves();
  player->outputItems();
}
void CodeSlayers::saveGame() {
  player->savePlayerData();
  map->saveData();
}
void CodeSlayers::introText() {

}
