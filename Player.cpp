#include "Player.h"
#include <vector>
#include <fstream>
#include <string>
Player::Player(string filename) {
  name = "Student";
  ifstream playerData;
  playerData.open(filename);
  bool fistLine = true;
  string line;
  int itemSize = 0;
  while(!playerData.eof()) {
    if(firstLine) {
      getline(playerData,line,','); //loads health, armor, strength, and exp of player
      health = stoi(line);
      getline(playerData,line,',');
      strength = stoi(line);
      getline(playerData,line,',');
      armor = stoi(line);
      getline(playerData,line,',');
      exp = stoi(line);
      getline(playerData,line,',');
      level = stoi(line);
      getline(playerData,line,',');
      x_pos = stoi(line);
      getline(playerData,line,',');
      y_pos = stoi(line);
      getline(playerData,line,','); //loads in moves damage
      moves[0].damageMod = stoi(line);
      getline(playerData,line,','); //loads in armor pierce
      moves[0].armorPierce = stoi(line);
      getline(playerData,line,',');//loads in moves name
      moves[0].name = line;
      getline(playerData,line,',');
      moves[1].damageMod = stoi(line);
      getline(playerData,line,',');
      moves[1].armorPierce = stoi(line);
      getline(playerData,line,',');
      moves[1].name = line;
      getline(playerData,line,',');
      moves[2].damageMod = stoi(line);
      getline(playerData,line,',');
      moves[2].armorPierce = stoi(line);
      getline(playerData,line,',');
      moves[2].name = line;
      getline(playerData,line,',');
      moves[3].damageMod = stoi(line);
      getline(playerData,line,',');
      moves[3].armorPierce = stoi(line);
      getline(playerData,line);
      moves[3].name = stoi(line);
      firstLine = false;
    } else {
      items.push_back(Item());
      getline(playerData,line,',');
      items[i].healthGained = stoi(line);
      getline(playerData,line);
      items[i].name = line;
      i++;
    }
  }
  playerData.close();
}
void Player::attack(Character target, string moveName) {
  int index = findMove(moveName);
  if(index >= 0) {
    int damage = (strength * moves[index].damageMod) - (armor - moves[index].armorPierce);
    target.receiveDamage(damage);
  }
}
void Player::addItem(string itemName, int health) {
  items.push_back(Item());
  items.back().name = itemName;
  items.back().healthGained = health;
}
void Player::useItem(string itemName) {
  int index = findItem(itemName);
  if(index >=0) {
    health+= items[index].healthGained;
    items.erase(items.begin()+index);
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
void savePlayerData() {
  ofstream playerData;
  playerData.open("savedPlayerStats.txt");
  playerData << playerStats;
  while(items.size() > 0) {
    playerData << items[items.size() - 1].healthGained << ',' << items[items.size() - 1].name << endl;
    items.pop_back();
  }
}
string Player::playerStats() {
  string stat = to_string(health) + ',' + to_string(strength) + ',' + to_string(armor);
  stat += ',' + to_string(exp) + ',' + to_string(level) + ',' + to_string(x_pos) + ',' + to_string(y_pos) + ',' + to_string(move[0].damageMod);
  stat += ',' + to_string(move[0].armorPierce) + ',' + move[0].name + ',' + to_string(move[1].damageMod);
  stat += ',' + to_string(move[1].armorPierce) + ',' + move[1].name + ',' + to_string(move[2].damageMod);
  stat += ',' + to_string(move[2].armorPierce) + ',' + move[2].name + ',' + to_string(move[3].damageMod);
  stat += ',' + to_string(move[3].armorPierc) << ',' + move[3].name + endl;
  return stat;
}
int Player::findMove(string moveName) {
  for(int i = 0; i < 4; i++) {
    if(moves[i].name == moveName) {
      return i;
    }
  }
  return -1;
}
int Player::findItem(string itemName) {
  for(int i; i = items.size(); i++) {
    if(items[i].name == itemName) {
      return i;
    }
  }
  return -1;
}
void outputItems() {
  for(int i = 0; i < items.size(); i++) {
    cout << items[i].name << endl;
  }
}
