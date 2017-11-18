#ifndef TILE_H
#define TILE_H
#include <string>
class Tile{
  public:
    //constructs tile with a terrain
    Tile(std::string);
    ~Tile();
    //function that gets terrain
    std::string getTerrain();
  private:
    std::string terrain;
};
#endif
