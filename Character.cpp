#include "Character.h"
#include <fstream>
#include <string>
Character::Character(string filename) {
  ifstream characterData;
  characterData.open(filename);
  bool fistLine = true;
  string line;
  while(!characterData.eof()) {
    if(firstLine) {
      getline(characterData,line,','); //loads health, armor, strength, and exp of character
      health = stoi(line);
      getline(characterData,line,',');
      strength = stoi(line);
      getline(characterData,line,',');
      armor = stoi(line);
      getline(characterData,line,',');
      level = stoi(line);
      getline(characterData,line,','); //loads in moves damage
      moves[0].damageMod = stoi(line);
      getline(characterData,line,','); //loads in moves armor pierce
      moves[0].armorPierce = stoi(line);
      getline(characterData,line,',');//loads in moves name
      moves[0].name = line;
      getline(characterData,line,',');
      moves[1].damageMod = stoi(line);
      getline(characterData,line,',');
      moves[1].armorPierce = stoi(line);
      getline(characterData,line,',');
      moves[1].name = line;
      getline(characterData,line,',');
      moves[2].damageMod = stoi(line);
      getline(characterData,line,',');
      moves[2].armorPierce = stoi(line);
      getline(characterData,line,',');
      moves[2].name = line;
      getline(characterData,line,',');
      moves[3].damageMod = stoi(line);
      getline(characterData,line,',');
      moves[3].armorPierce = stoi(line);
      getline(characterData,line);
      moves[3].name = stoi(line);
      firstLine = false;
    }
  }
  characterData.close();
}
Character::~Character() {

}
void Character::attack(Character target, int moveIndex) {
  int damage = (strength * moves[moveIndex].damageMod) - (armor - moves[movesIndex].armorPierce);
  target.receiveDamage(damage);
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
string Character::getName() {
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
void outputMoves() {
  for(int i = 0; i < 4; i++) {
    cout << "Move Name: " << moves[i].name << " Move Damage Mod: " << moves[i].damageMod << " Move Armor Pierce: " << moves[i].armorPierce << endl;
  }
}