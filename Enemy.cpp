#include "Enemy.h"
#include <fstream>
#include <sstream>
#include <string>
Enemy::Enemy(string filename, string enemyname) {
  name = enemyname;
  ifstream enemyData;
  enemyData.open(filename);
  bool foundName = false;
  string line;
  while(!enemyData.eof() && !foundName) {
    getline(enemyData,line);
    if(line == enemyname) {
      getline(enemyData,line,','); //loads health, armor, strength, and exp of enemy
      health = stoi(line);
      getline(enemyData,line,',');
      strength = stoi(line);
      getline(enemyData,line,',');
      armor = stoi(line);
      getline(enemyData,line,',');
      level = stoi(line);
      getline(enemyData,line,','); //loads in moves damage
      moves[0].damageMod = stoi(line);
      getline(enemyData,line,','); //loads in armor pierce
      moves[0].armorPierce = stoi(line);
      getline(enemyData,line,',');//loads in moves name
      moves[0].name = line;
      getline(enemyData,line,',');
      moves[1].damageMod = stoi(line);
      getline(enemyData,line,',');
      moves[1].armorPierce = stoi(line);
      getline(enemyData,line,',');
      moves[1].name = line;
      getline(enemyData,line,',');
      moves[2].damageMod = stoi(line);
      getline(enemyData,line,',');
      moves[2].armorPierce = stoi(line);
      getline(enemyData,line,',');
      moves[2].name = line;
      getline(enemyData,line,',');
      moves[3].damageMod = stoi(line);
      getline(enemyData,line,',');
      moves[3].armorPierce = stoi(line);
      getline(enemyData,line);
      moves[3].name = stoi(line);
      foundName = true;
    }
  }
  enemyData.close();
}
Enemy::Enemy(string line) {
  stringstream s(line);
  string stats;
  getline(enemyData,stats,','); //loads health, armor, strength, and exp of enemy
  health = stoi(stats);
  getline(enemyData,stats,',');
  strength = stoi(stats);
  getline(enemyData,stats,',');
  armor = stoi(stats);
  getline(enemyData,stats,',');
  name = stats;
  getline(enemyData,stats,',');
  x_pos = stoi(stats);
  getline(enemyData,stats,',');
  y_pos = stoi(stats);
  getline(enemyData,stats,',');
  level = stoi(stats);
  getline(enemyData,stats,','); //loads in moves damage
  moves[0].damageMod = stoi(stats);
  getline(enemyData,stats,','); //loads in armor pierce
  moves[0].armorPierce = stoi(stats);
  getline(enemyData,stats,',');//loads in moves name
  moves[0].name = stats;
  getline(enemyData,stats,',');
  moves[1].damageMod = stoi(stats);
  getline(enemyData,stats,',');
  moves[1].armorPierce = stoi(stats);
  getline(enemyData,stats,',');
  moves[1].name = stats;
  getline(enemyData,stats,',');
  moves[2].damageMod = stoi(stats);
  getline(enemyData,stats,',');
  moves[2].armorPierce = stoi(stats);
  getline(enemyData,stats,',');
  moves[2].name = stats;
  getline(enemyData,stats,',');
  moves[3].damageMod = stoi(stats);
  getline(enemyData,stats,',');
  moves[3].armorPierce = stoi(stats);
  getline(enemyData,stats);
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
string Enemy::enemyStats() {
  string stat = to_string(health) + ',' + to_string(strength) + ',' + to_string(armor) + ',' + name;
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
