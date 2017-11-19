#include "Character.h"
#include "Enemy.h"
#include "ItemsAndMoves.h"
#include "Map.h"
#include "Player.h"
#include "CodeSlayers.h"
#include "Tile.h"
#include <iostream>

int main() {
  std::cout <<"test success!";
  CodeSlayers * game;
  game = new CodeSlayers();
  game->playGame();
  return 0;
}
