#include "Enemy.h"
#include <fstream>
#include <sstream>
#include <string>
Enemy::Enemy(std::string filename, std::string enemyname) {
  name = enemyname;
  ifstream enemyData;
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
  stringstream s(line);
  std::string stats;
  std::getline(enemyData,stats,','); //loads health, armor, strength, and exp of enemy
  health = stoi(stats);
  std::getline(enemyData,stats,',');
  strength = stoi(stats);
  std::getline(enemyData,stats,',');
  armor = stoi(stats);
  std::getline(enemyData,stats,',');
  name = stats;
  std::getline(enemyData,stats,',');
  x_pos = stoi(stats);
  std::getline(enemyData,stats,',');
  y_pos = stoi(stats);
  std::getline(enemyData,stats,',');
  level = stoi(stats);
  std::getline(enemyData,stats,','); //loads in moves damage
  moves[0].damageMod = stoi(stats);
  std::getline(enemyData,stats,','); //loads in armor pierce
  moves[0].armorPierce = stoi(stats);
  std::getline(enemyData,stats,',');//loads in moves name
  moves[0].name = stats;
  std::getline(enemyData,stats,',');
  moves[1].damageMod = stoi(stats);
  std::getline(enemyData,stats,',');
  moves[1].armorPierce = stoi(stats);
  std::getline(enemyData,stats,',');
  moves[1].name = stats;
  std::getline(enemyData,stats,',');
  moves[2].damageMod = stoi(stats);
  std::getline(enemyData,stats,',');
  moves[2].armorPierce = stoi(stats);
  std::getline(enemyData,stats,',');
  moves[2].name = stats;
  std::getline(enemyData,stats,',');
  moves[3].damageMod = stoi(stats);
  std::getline(enemyData,stats,',');
  moves[3].armorPierce = stoi(stats);
  std::getline(enemyData,stats);
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
  std::string stat = to_string(health) + ',' + to_string(strength) + ',' + to_string(armor) + ',' + name;
  stat += ',' + to_string(x_pos) + ',' + to_string(y_pos) + ',';
  stat += ',' + to_string(level) + ',' + to_string(move[0].damageMod);
  stat += ',' + to_string(move[0].armorPierce) + ',' + move[0].name + ',' + to_string(move[1].damageMod);
  stat += ',' + to_string(move[1].armorPierce) + ',' + move[1].name + ',' + to_string(move[2].damageMod);
  stat += ',' + to_string(move[2].armorPierce) + ',' + move[2].name + ',' + to_string(move[3].damageMod);
  stat += ',' + to_string(move[3].armorPierc) << ',' + move[3].name + endl;
  return stat;
}
void Enemy::setLevel(int level) {
  this->level = level;
}
