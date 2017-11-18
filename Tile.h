#ifndef TILE_H
#define TILE_H
class Tile{
  public:
    //constructs tile with a terrain
    Tile(string);
    ~Tile();
    //function that gets terrain
    string getTerrain();
  private:
    string terrain;

};
#endif
