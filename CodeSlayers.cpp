#include "CodeSlayers.h"
#include "Player.h"
#include "Map.h"
#include "Enemy.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
CodeSlayers::CodeSlayers() {
  fun_counter = 100;
  while(1 == 1) {
    std::string line;
    std::cout << "would you like to play a new game or load a previous one? press and enter 'n' for a new game, and 'l' to load a saved game" << std::endl;
    std::cin >> line;
    if(line[0] == 'n') {
      map = new Map();
      player = new Player("playerStats.txt");
      opponent = new Enemy();
      boss = new Enemy("EnemyStats.txt", "cog");
      map->spawnEnemies();
      expLevelUp = 5;
      break;
    }
    if(line[0] == 'l') {
      map = new Map("mapdata.txt");
      player = new Player("savedPlayerStats.txt");
      opponent = new Enemy();
      boss = new Enemy("EnemyStats.txt", "cog");
      expLevelUp = 5 * player->getLevel();
      break;
    }
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
  while(map->getEnemySize() > -1) {
    descriptionText();
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
      case 't':
      bossFight();
      break;
    }
  }
  bossFight();
}
void CodeSlayers::fight() {
  std::string line;
  loadOpponent();
  int turnCount = 1;
  while(!isDead() && !gameOver()) {
    if(turnCount%2 == 0) {
      srand(time(NULL));
      int att = rand()%4;
      opponent->attack(player, att);
      std::cout << opponent->getName() << " attacks with " << opponent->moves[att].name << std::endl;
    } else {
      std::cout << "your turn. attack with 'a' and use item with 'i'" << std::endl;
      std::cin >> line;
      while(1 == 1) {
        if(line[0] == 'a') {
          player->outputMoves();
          std::cout << "type in a move: ";
          std::cin >> line;
          player->attack(opponent, line);
          break;
        }
        if(line[0] == 'i') {
          player->outputItems();
          std::cout << "type in an item: ";
          std::cin >> line;
          player->useItem(line);
          break;
        }
      }
    }
    std::cout << player->getHealth() << " sanity points remaining for you" << std::endl;
    turnCount++;
  }
  if(isDead()) {
    player->addExp(opponent->getLevel());
    map->removeEnemy(player->getX_pos(), player->getY_pos());
    player->addItem("c4c-food", 10);
    std::cout << "got c4c food!" << std::endl;
    if(player->canLevelUp(expLevelUp)) {
      player->levelUp();
      std::cout<< "you leveled up!" << std::endl;
      expLevelUp += 5;
    }
  }
  if(gameOver()) {
    std::cout << "you have been defeated";
    exit (0);
  }
  fun_counter -= 50;
}
void CodeSlayers::bossFight() {
  std::string line;
  loadOpponent();
  int turnCount = 1;
  while(!bossIsDead() && !gameOver()) {
    if(turnCount%2 == 0) {
      srand(time(NULL));
      int att = rand()%4;
      boss->attack(player, att);
      std::cout << boss->getName() << " attacks with " << boss->moves[att].name << std::endl;
    } else {
      std::cout << "your turn. attack with 'a' and use item with 'i'" << std::endl;
      std::cin >> line;
      while(1 == 1) {
        if(line[0] == 'a') {
          player->outputMoves();
          std::cout << "type in a move: ";
          std::cin >> line;
          player->attack(boss, line);
          break;
        }
        if(line[0] == 'i') {
          player->outputItems();
          std::cout << "type in an item: ";
          std::cin >> line;
          player->useItem(line);
          break;
        }
      }
    }
    std::cout << player->getHealth() << " sanity points remaining for you" << std::endl;
    if(boss->getHealth() > 150) {
      std::cout << "could not locate files: 0/100 points on submission" << std::endl;
    } else if(boss->getHealth() > 100) {
      std::cout << "expected 16 outputs, only got 13: 11/1oo points on submission" << std::endl;
    } else if(boss->getHealth() > 50) {
      std::cout << "expected output:get good, student output:get,good: 63/100 points on submission" << std::endl;
    }
    turnCount++;
  }
  if(bossIsDead()) {
    std::cout << "100/100" << std::endl;
    std::cout << "you have slayed the greatest for for CSCI-1300 students. Congratulations!";
    exit (0);
  }
  if(gameOver()) {
    std::cout<< "Cog has defeated you like many others.";
    exit (0);
  }
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
      player->setY_pos(player->getY_pos() - 1);
    }
    break;
    case 's':
    if(player->getY_pos() < 99) {
      player->setY_pos(player->getY_pos() + 1);
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
  std::cout << "Hello and welcome brave adventure to CodeSlayers! In this game, you slay various code problems to make .cpp land compile correctly. here is a list of all the keywords you must type to do actions. 'n' to move north, 's' to move south, 'e' to move east, 'w' to move west, 'q' to save game data, 'i' to show stats, and 'f' to fight an error. When you are ready, type 't' to initiate bossfight." << std::endl;
}
void CodeSlayers::descriptionText() {
  std::cout << "fun counter: " << fun_counter << std::endl;
  std::cout << player->getX_pos() << " " << player->getY_pos() << '\n';
  std::cout << "you are walking through " << map->getTileTerrain(player->getX_pos(), player->getY_pos()) << " terrain" << std::endl;
  if(!map->isEmpty(player->getX_pos(), player ->getY_pos())) {
    std::cout << "there is a level " << map->getEnemy(player->getX_pos(), player ->getY_pos()).getLevel() << " monster here." << std::endl;
  }
}
