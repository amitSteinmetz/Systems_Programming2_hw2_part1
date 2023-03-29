#include "game.hpp"

void Game::playTurn(){}
void Game::printLastTurn(){}
void Game::playAll(){} //playes the game untill the end
void Game::printWiner(){} // prints the name of the winning player
void Game::printLog(){} // prints all the turns played one line per turn (same format as game.printLastTurn())
void Game::printStats(){}

// Constructor
Game::Game(Player &new_player1, Player &new_player2)
{
    this->p1 = &new_player1;
    this->p2 = &new_player2;
}