#pragma once
#include "player.hpp"
#include "game.hpp"

// Class game
class Game
{
    // Decide about every field if it need to be private or public
     
    // attributes
    Player *p1;
    Player *p2;

    // Constructors
    public:
    Game(Player &new_player1, Player &new_player2);

    // Destructors

    // methods
    
    void playTurn();
    void printLastTurn();
    void playAll(); //playes the game untill the end
   void printWiner(); // prints the name of the winning player
   void printLog(); // prints all the turns played one line per turn (same format as game.printLastTurn())
   void printStats();
};

