#ifndef ITEMSANDMOVES_H
#define ITEMSANDMOVES_H
struct Item{
  string name;
  int healthGained;
};

struct Move{
  string name;
  int damageMod;
  int armorPierce;
};
#endif
