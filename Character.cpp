#include "Character.h"
#include <fstream>
#include <iostream>
#include <string>
Character::Character(std::string filename) {
  std::ifstream characterData;
  characterData.open(filename);
  bool firstLine = true;
  std::string line;
  while(!characterData.eof()) {
    if(firstLine) {
      std::getline(characterData,line,','); //loads health, armor, strength, and exp of character
      health = stoi(line);
      std::getline(characterData,line,',');
      strength = stoi(line);
      std::getline(characterData,line,',');
      armor = stoi(line);
      std::getline(characterData,line,',');
      level = stoi(line);
      std::getline(characterData,line,','); //loads in moves damage
      moves[0].damageMod = stoi(line);
      std::getline(characterData,line,','); //loads in moves armor pierce
      moves[0].armorPierce = stoi(line);
      std::getline(characterData,line,',');//loads in moves name
      moves[0].name = line;
      std::getline(characterData,line,',');
      moves[1].damageMod = stoi(line);
      std::getline(characterData,line,',');
      moves[1].armorPierce = stoi(line);
      std::getline(characterData,line,',');
      moves[1].name = line;
      std::getline(characterData,line,',');
      moves[2].damageMod = stoi(line);
      std::getline(characterData,line,',');
      moves[2].armorPierce = stoi(line);
      std::getline(characterData,line,',');
      moves[2].name = line;
      std::getline(characterData,line,',');
      moves[3].damageMod = stoi(line);
      std::getline(characterData,line,',');
      moves[3].armorPierce = stoi(line);
      std::getline(characterData,line);
      moves[3].name = stoi(line);
      firstLine = false;
    }
  }
  characterData.close();
}
Character::~Character() {

}
void Character::receiveDamage(int damage) {
  health -=damage;
}
int Character::getHealth() {
  return health;
}
int Character::getStrength() {
  return strength;
}
int Character::getArmor() {
  return armor;
}
int Character::getLevel() {
  return level;
}
std::string Character::getName() {
  return name;
}
int Character::getX_pos() {
  return x_pos;
}
int Character::getY_pos() {
  return y_pos;
}
void Character::setX_pos(int x_pos) {
  this->x_pos = x_pos;
}
void Character::setY_pos(int y_pos) {
  this->y_pos = y_pos;
}
void Character::outputMoves() {
  for(int i = 0; i < 4; i++) {
    std::cout << "Move Name: " << moves[i].name << " Move Damage Mod: " << moves[i].damageMod << " Move Armor Pierce: " << moves[i].armorPierce << std::endl;
  }
}
