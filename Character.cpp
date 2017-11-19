#include "Character.h"
#include <fstream>
#include <iostream>
#include <string>
Character::Character() {

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
