#include "Enemy.h"
#include "Player.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
Enemy::Enemy(std::string filename, std::string enemyname) : Character() {
  this->name = enemyname;
  std::ifstream enemyData;
  const char * num;
  enemyData.open(filename);
  bool foundName = false;
  std::string line;
  while(!enemyData.eof() && !foundName) {
    std::getline(enemyData,line);
    if(line == enemyname) {
      std::getline(enemyData,line,','); //loads health, armor, strength, and exp of enemy
      num = line.c_str();
      health = std::atoi(num);
      std::getline(enemyData,line,',');
      strength = std::atoi(num);
      std::getline(enemyData,line,',');
      armor = std::atoi(num);
      std::getline(enemyData,line,',');
      level = std::atoi(num);
      std::getline(enemyData,line,','); //loads in moves damage
      moves[0].damageMod = std::atoi(num);
      std::getline(enemyData,line,','); //loads in armor pierce
      moves[0].armorPierce = std::atoi(num);
      std::getline(enemyData,line,',');//loads in moves name
      moves[0].name = line;
      std::getline(enemyData,line,',');
      moves[1].damageMod = std::atoi(num);
      std::getline(enemyData,line,',');
      moves[1].armorPierce = std::atoi(num);
      std::getline(enemyData,line,',');
      moves[1].name = line;
      std::getline(enemyData,line,',');
      moves[2].damageMod = std::atoi(num);
      std::getline(enemyData,line,',');
      moves[2].armorPierce = std::atoi(num);
      std::getline(enemyData,line,',');
      moves[2].name = line;
      std::getline(enemyData,line,',');
      moves[3].damageMod = std::atoi(num);
      std::getline(enemyData,line,',');
      moves[3].armorPierce = std::atoi(num);
      std::getline(enemyData,line);
      moves[3].name = std::atoi(num);
      foundName = true;
    }
  }
  enemyData.close();
}
Enemy::Enemy(std::string line) : Character() {
  std::stringstream ss(line);
  const char * num;
  std::string stats;
  std::getline(ss,stats,','); //loads health, armor, strength, and exp of enemy
  num = stats.c_str();
  health = std::atoi(num);
  std::getline(ss,stats,',');
  strength = std::atoi(num);
  std::getline(ss,stats,',');
  armor = std::atoi(num);
  std::getline(ss,stats,',');
  name = stats;
  std::getline(ss,stats,',');
  x_pos = std::atoi(num);
  std::getline(ss,stats,',');
  y_pos = std::atoi(num);
  std::getline(ss,stats,',');
  level = std::atoi(num);
  std::getline(ss,stats,','); //loads in moves damage
  moves[0].damageMod = std::atoi(num);
  std::getline(ss,stats,','); //loads in armor pierce
  moves[0].armorPierce = std::atoi(num);
  std::getline(ss,stats,',');//loads in moves name
  moves[0].name = stats;
  std::getline(ss,stats,',');
  moves[1].damageMod = std::atoi(num);
  std::getline(ss,stats,',');
  moves[1].armorPierce = std::atoi(num);
  std::getline(ss,stats,',');
  moves[1].name = stats;
  std::getline(ss,stats,',');
  moves[2].damageMod = std::atoi(num);
  std::getline(ss,stats,',');
  moves[2].armorPierce = std::atoi(num);
  std::getline(ss,stats,',');
  moves[2].name = stats;
  std::getline(ss,stats,',');
  moves[3].damageMod = std::atoi(num);
  std::getline(ss,stats,',');
  moves[3].armorPierce = std::atoi(num);
  std::getline(ss,stats);
  moves[3].name = std::atoi(num);
}
Enemy::Enemy() : Character() {

}
Enemy::~Enemy() {

}
void Enemy::adjustStats() {
  for(int i = 1; i < level; i++) {
    health += 5;
    strength += 3;
    armor += 1;
  }
}
std::string Enemy::enemyStats() {
  std::string stat = std::to_string(health) + ',' + std::to_string(strength) + ',' + std::to_string(armor) + ',' + name;
  stat += ',' + std::to_string(x_pos) + ',' + std::to_string(y_pos) + ',';
  stat += ',' + std::to_string(level) + ',' + std::to_string(moves[0].damageMod);
  stat += ',' + std::to_string(moves[0].armorPierce) + ',' + moves[0].name + ',' + std::to_string(moves[1].damageMod);
  stat += ',' + std::to_string(moves[1].armorPierce) + ',' + moves[1].name + ',' + std::to_string(moves[2].damageMod);
  stat += ',' + std::to_string(moves[2].armorPierce) + ',' + moves[2].name + ',' + std::to_string(moves[3].damageMod);
  stat += ',' + std::to_string(moves[3].armorPierce) + ',' + moves[3].name + '\n';
  return stat;
}
void Enemy::setLevel(int level) {
  this->level = level;
}
void Enemy::attack(Player* player, int attack) {
  int damage = (strength * moves[attack].damageMod) - (armor - moves[attack].armorPierce);
  player->receiveDamage(damage);
}
