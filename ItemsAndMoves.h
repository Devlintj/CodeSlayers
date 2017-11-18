#ifndef ITEMSANDMOVES_H
#define ITEMSANDMOVES_H
#include <string>
struct Item{
  std::string name;
  int healthGained;
};

struct Move{
  std::string name;
  int damageMod;
  int armorPierce;
};
#endif
