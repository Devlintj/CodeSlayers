#ifndef CHARACTER_H
#define CHARACTER_H
class Character{
  public:
    //constructor initalizing a character with a file to import stats
    Character(string);
    ~Character();
    //function to attack another character with a certain attack
    void attack(Character, int);
    //function to receiveDamage from another character
    void receiveDamage(int);
    //function that returns character's strength
    int getHealth();
    //function that returns character's strength
    int getStrength();
    //function that returns character's armor
    int getArmor();
    //function that returns character's level
    int getLevel();
    //function that returns character's name
    string getName();
    //function the couts move names and stats
    void outputMoves();
    int getX_pos();
    int getY_pos();
    void setX_pos(int);
    void setY_pos(int)
  private:
    int health;
    int strength;
    int armor;
    int level;
    int x_pos;
    int y_pos;
    string name;
    //array of structure move
    Move moves[4];
};
#endif
