#include "doctest.h"
#include "sources/game.hpp"
#include "sources/player.hpp"
#include <stdexcept>

TEST_CASE("Correct stacksize in the beginning of the game")
{
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2); 
    CHECK(p1.stacksize() == 26);
    CHECK(p2.stacksize() == 26);
}

TEST_CASE("Correct stacksize after one turn")
{
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2); 
    game.playTurn();
    CHECK(p1.stacksize() < 26);
    CHECK(p2.stacksize() < 26);
}

TEST_CASE("Same stacksize for both players")
{
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2); 
    game.playTurn();
    CHECK(p1.stacksize() == p2.stacksize());
}

TEST_CASE("Stacksize equal to 0 in the end of game")
{
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2); 
    game.playAll();

    CHECK(p1.stacksize() == 0);
    CHECK(p2.stacksize() == 0);
}

TEST_CASE("Winner and looser has different amount of cards that was taken")
{
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2); 
    game.playAll();

    CHECK(p1.cardesTaken() != p2.cardesTaken());
}

TEST_CASE("One player should has cards taken after turn")
{
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2); 
    game.playTurn();

    CHECK((p1.cardesTaken() > 0 || p2.cardesTaken() > 0));
}

TEST_CASE("Both players start the game with zero cards taken")
{
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2); 
    
    CHECK(p1.cardesTaken() == 0);
    CHECK(p2.cardesTaken() == 0);
}

TEST_CASE("Cant play turn after game is over")
{
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2); 
    game.playAll();

    CHECK_THROWS(game.playTurn());
}

TEST_CASE("Amount of cards taken isn't bigger than 26")
{
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2); 
    game.playAll();

    CHECK(p1.cardesTaken() <= 26);
    CHECK(p2.cardesTaken() <= 26);
}

TEST_CASE("There isnt winner in the beginning of the game")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2); 

    CHECK_THROWS(game.printWiner());
}

TEST_CASE("Cant print last turn in the beginning of the game")
{
     Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2); 

    CHECK_THROWS(game.printLastTurn());
}

TEST_CASE("PrintLog func shouldnt work in the beginning of the game")
{
     Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2); 

    CHECK_THROWS(game.printLog());
}

TEST_CASE("Same player cannot play in two different games")
{
    Player p1("Alice");
    Player p2("Bob");
    Player p3("Bibi");

    Game game1(p1,p2); 
    Game game2(p1,p3);

    // Any function shouldnt work, we just gave an example
    CHECK_THROWS(game2.playTurn());
}

TEST_CASE("One player cannot play the game")
{
    Player p1("Alice");
    Game game(p1, p1);

    // Any function shouldnt work, we just gave an example
    CHECK_THROWS(game.playTurn());
}

TEST_CASE("Cant playAll after game is over")
{
     Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2); 
    game.playAll();

    CHECK_THROWS(game.playAll());
}

TEST_CASE("Print Last turn out of bounds error")
{
     Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2); 

    for(int i = 0; i < 5; i++) game.playTurn();

    for (int i = 0; i < 5; i++) game.printLastTurn();

    CHECK_THROWS(game.printLastTurn());  
}

TEST_CASE("Lower bound for amount of cards taken after few turns")
{
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2); 

    for(int i = 0; i < 5; i++) game.playTurn();

    CHECK(p1.cardesTaken() + p2.cardesTaken() >= 5);
}

TEST_CASE("Shouldnt print stats before the game start")
{
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2); 

    CHECK_THROWS(game.printStats());
}

TEST_CASE("Player cant has cards taken without a game")
{
    Player p1("Alice");
    Player p2("Bob");

    CHECK_THROWS(p1.cardesTaken());
    CHECK_THROWS(p2.cardesTaken());
}

TEST_CASE("Player cant has stack size without a game")
{
    Player p1("Alice");
    Player p2("Bob");

    CHECK_THROWS(p1.stacksize());
    CHECK_THROWS(p2.stacksize());
}

// TEST_CASE("")




// TEST_CASE("Factorials of small numbers") {
//     CHECK(factorial(0) == 1);
//     CHECK(factorial(1) == 1);
//     CHECK(factorial(2) == 2);
//     CHECK(factorial(3) == 6);
// }

// TEST_CASE("Factorials of large numbers") {
//     CHECK(factorial(4) == 24);
//     CHECK(factorial(6) == 720);
//     CHECK(factorial(10) == 3628800);

//     // auto f3 = factorial(3);
//     // CHECK((f3==5 || f3==6)); // logic OR requires parentheses!
// }


// TEST_CASE("Factorials of negative numbers") { 
//     CHECK_THROWS(factorial(-1));  // check that some exception is thrown
//     CHECK_THROWS_AS(factorial(-2), std::out_of_range);  // check that a specific exception type is thrown
//     CHECK_THROWS_AS(factorial(-2), std::exception);  // check that a specific exception type (or a descendant) is thrown
// }

