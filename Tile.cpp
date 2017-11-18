#include "Tile.h"
Tile::Tile(string terrain) {
  this->terrain = terrain;
}
Tile::~Tile();
Tile::getTerrain() {
  return terrain;
}
