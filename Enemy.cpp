#include "Enemy.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
Enemy::Enemy(std::string filename, std::string enemyname) {
  this->name = enemyname;
  std::ifstream enemyData;
  enemyData.open(filename);
  bool foundName = false;
  std::string line;
  while(!enemyData.eof() && !foundName) {
    std::getline(enemyData,line);
    if(line == enemyname) {
      std::getline(enemyData,line,','); //loads health, armor, strength, and exp of enemy
      health = stoi(line);
      std::getline(enemyData,line,',');
      strength = stoi(line);
      std::getline(enemyData,line,',');
      armor = stoi(line);
      std::getline(enemyData,line,',');
      level = stoi(line);
      std::getline(enemyData,line,','); //loads in moves damage
      moves[0].damageMod = stoi(line);
      std::getline(enemyData,line,','); //loads in armor pierce
      moves[0].armorPierce = stoi(line);
      std::getline(enemyData,line,',');//loads in moves name
      moves[0].name = line;
      std::getline(enemyData,line,',');
      moves[1].damageMod = stoi(line);
      std::getline(enemyData,line,',');
      moves[1].armorPierce = stoi(line);
      std::getline(enemyData,line,',');
      moves[1].name = line;
      std::getline(enemyData,line,',');
      moves[2].damageMod = stoi(line);
      std::getline(enemyData,line,',');
      moves[2].armorPierce = stoi(line);
      std::getline(enemyData,line,',');
      moves[2].name = line;
      std::getline(enemyData,line,',');
      moves[3].damageMod = stoi(line);
      std::getline(enemyData,line,',');
      moves[3].armorPierce = stoi(line);
      std::getline(enemyData,line);
      moves[3].name = stoi(line);
      foundName = true;
    }
  }
  enemyData.close();
}
Enemy::Enemy(std::string line) {
  std::stringstream ss(line);
  std::string stats;
  std::getline(ss,stats,','); //loads health, armor, strength, and exp of enemy
  health = stoi(stats);
  std::getline(ss,stats,',');
  strength = stoi(stats);
  std::getline(ss,stats,',');
  armor = stoi(stats);
  std::getline(ss,stats,',');
  name = stats;
  std::getline(ss,stats,',');
  x_pos = stoi(stats);
  std::getline(ss,stats,',');
  y_pos = stoi(stats);
  std::getline(ss,stats,',');
  level = stoi(stats);
  std::getline(ss,stats,','); //loads in moves damage
  moves[0].damageMod = stoi(stats);
  std::getline(ss,stats,','); //loads in armor pierce
  moves[0].armorPierce = stoi(stats);
  std::getline(ss,stats,',');//loads in moves name
  moves[0].name = stats;
  std::getline(ss,stats,',');
  moves[1].damageMod = stoi(stats);
  std::getline(ss,stats,',');
  moves[1].armorPierce = stoi(stats);
  std::getline(ss,stats,',');
  moves[1].name = stats;
  std::getline(ss,stats,',');
  moves[2].damageMod = stoi(stats);
  std::getline(ss,stats,',');
  moves[2].armorPierce = stoi(stats);
  std::getline(ss,stats,',');
  moves[2].name = stats;
  std::getline(ss,stats,',');
  moves[3].damageMod = stoi(stats);
  std::getline(ss,stats,',');
  moves[3].armorPierce = stoi(stats);
  std::getline(ss,stats);
  moves[3].name = stoi(stats);
}
Enemy::Enemy() {

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
void attack(Player* player, int attack) {
  int damage = (strength * moves[moveIndex].damageMod) - (armor - moves[moveIndex].armorPierce);
  player->receiveDamage(damage);
}
