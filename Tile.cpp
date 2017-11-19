#include "Tile.h"
Tile::Tile(std::string terrain) {
  this->terrain = terrain;
}
Tile::~Tile(){

}
std::string Tile::getTerrain() {
  return terrain;
}
