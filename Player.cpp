#include "Player.h"
#include "Enemy.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
Player::Player(std::string filename) : Character(){
  name = "Student";
  std::ifstream playerData;
  const char * num;
  playerData.open(filename);
  bool firstLine = true;
  std::string line;
  int itemSize = 0;
  while(!playerData.eof()) {
    if(firstLine) {
      std::getline(playerData,line,','); //loads health, armor, strength, and exp of player
      num = line.c_str();
      health = std::atoi(num);
      std::getline(playerData,line,',');
      strength = std::atoi(num);
      std::getline(playerData,line,',');
      armor = std::atoi(num);
      std::getline(playerData,line,',');
      exp = std::atoi(num);
      std::getline(playerData,line,',');
      level = std::atoi(num);
      std::getline(playerData,line,',');
      x_pos = std::atoi(num);
      std::getline(playerData,line,',');
      y_pos = std::atoi(num);
      std::getline(playerData,line,','); //loads in moves damage
      moves[0].damageMod = std::atoi(num);
      std::getline(playerData,line,','); //loads in armor pierce
      moves[0].armorPierce = std::atoi(num);
      std::getline(playerData,line,',');//loads in moves name
      moves[0].name = line;
      std::getline(playerData,line,',');
      moves[1].damageMod = std::atoi(num);
      std::getline(playerData,line,',');
      moves[1].armorPierce = std::atoi(num);
      std::getline(playerData,line,',');
      moves[1].name = line;
      std::getline(playerData,line,',');
      moves[2].damageMod = std::atoi(num);
      std::getline(playerData,line,',');
      moves[2].armorPierce = std::atoi(num);
      std::getline(playerData,line,',');
      moves[2].name = line;
      std::getline(playerData,line,',');
      moves[3].damageMod = std::atoi(num);
      std::getline(playerData,line,',');
      moves[3].armorPierce = std::atoi(num);
      std::getline(playerData,line);
      moves[3].name = line;
      firstLine = false;
    } else {
      this->items.push_back(Item());
      std::getline(playerData,line,',');
      this->items[itemSize].healthGained = std::atoi(num);
      std::getline(playerData,line);
      this->items[itemSize].name = line;
      itemSize++;
    }
  }
  playerData.close();
}
Player::~Player() {

}
void Player::attack(Enemy* target, std::string moveName) {
  int index = findMove(moveName);
  if(index >= 0) {
    int damage = (strength * moves[index].damageMod) - (armor - moves[index].armorPierce);
    target->receiveDamage(damage);
  }
}
void Player::addItem(std::string itemName, int health) {
  this->items.push_back(Item());
  this->items.back().name = itemName;
  this->items.back().healthGained = health;
}
void Player::useItem(std::string itemName) {
  int index = findItem(itemName);
  if(index >=0) {
    health+= this->items[index].healthGained;
    this->items.erase(this->items.begin()+index);
  }
}
void Player::levelUp() {
  health+=50;
  strength+=5;
  armor+=2;
  exp = 0;
}
bool Player::canLevelUp(int expReq) {
  if(exp >= expReq) {
    return true;
  } else {
    return false;
  }
}
void Player::savePlayerData() {
  std::ofstream playerData;
  playerData.open("savedPlayerStats.txt");
  playerData << playerStats();
  while(this->items.size() > 0) {
    playerData << this->items[this->items.size() - 1].healthGained << ',' << this->items[this->items.size() - 1].name << '\n';
    this->items.pop_back();
  }
}
std::string Player::playerStats() {
  std::string stat = std::to_string(health) + ',' + std::to_string(strength) + ',' + std::to_string(armor);
  stat += ',' + std::to_string(exp) + ',' + std::to_string(level) + ',' + std::to_string(x_pos) + ',' + std::to_string(y_pos) + ',' + std::to_string(moves[0].damageMod);
  stat += ',' + std::to_string(moves[0].armorPierce) + ',' + moves[0].name + ',' + std::to_string(moves[1].damageMod);
  stat += ',' + std::to_string(moves[1].armorPierce) + ',' + moves[1].name + ',' + std::to_string(moves[2].damageMod);
  stat += ',' + std::to_string(moves[2].armorPierce) + ',' + moves[2].name + ',' + std::to_string(moves[3].damageMod);
  stat += ',' + std::to_string(moves[3].armorPierce) + ',' + moves[3].name + '\n';
  return stat;
}
int Player::findMove(std::string moveName) {
  for(int i = 0; i < 4; i++) {
    if(moves[i].name == moveName) {
      return i;
    }
  }
  return -1;
}
int Player::findItem(std::string itemName) {
  for(int i; i = this->items.size(); i++) {
    if(this->items[i].name == itemName) {
      return i;
    }
  }
  return -1;
}
void Player::outputItems() {
  for(int i = 0; i < this->items.size(); i++) {
    std::cout << this->items[i].name << std::endl;
  }
}
int Player::getExp() {
  return exp;
}
