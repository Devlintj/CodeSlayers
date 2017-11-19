#include "Tile.h"
#include <string>
Tile::Tile(std::string terrain) {
  this->terrain = terrain;
}
Tile::~Tile(){

}
std::string Tile::getTerrain() {
  return terrain;
}
