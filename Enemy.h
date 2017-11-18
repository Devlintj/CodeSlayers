#ifndef ENEMY_H
#define ENEMY_H
class Enemy : Character{
  public:
    //constructor initalizing a enemy with a file to import stats, and and level.
    Enemy(string, int);
    Enemy(string);
    //empty constructer so I don't memory leak
    Enemy();
    ~Enemy();
    //function that sets enemy level
    void setLevel(int);
    //function returns as string of enemy stats
    string enemyStats();
  private:
    //function that adjusts stats based on level
    void adjustStats();
};
#endif
