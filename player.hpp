#pragma once
#include <string>
#include <iostream>
using namespace std;

// Class player
class Player {
    // Decide about every field if it need to be private or public

// attributes
public:
string name;

// Constructors
Player()
{}

Player(string new_name) {
    name = new_name;
}

// Destructors

// methods
int stacksize(); //prints the amount of cards left. should be 21 but can be less if a draw was played
int cardesTaken(); 

};

