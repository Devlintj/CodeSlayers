#ifndef CODESLAYERS_H
#define CODESLAYERS_H
class Player;
class Map;
class Enemy;
class CodeSlayers {
  public:
    CodeSlayers();
    ~CodeSlayers();
    //function where the game is run
    void playGame();
    //function that deals with battle sequences
    void fight();
    //function that goes through boss fight
    void bossFight();
    //function that moves the player pos if no enemy occupies the position
    void movePlayer(char);
    //function that checks if enemy is dead
    bool isDead();
    //function that checks if boss is dead
    bool bossIsDead();
    //function that checks if player is dead
    bool gameOver();
    //function that returns fun counter
    int getFun_Counter();
    //loads oppenent to fight it
    void loadOpponent();
    //function that shows players stats, moves, and items
    void showStats();
    //function that saves game
    void saveGame();
    //funtion that couts intro to the game
    void introText();
  private:
    Map * map;
    Player * player;
    Enemy * boss;
    Enemy * opponent;
    int fun_counter;
    int expLevelUp;

};
#endif
