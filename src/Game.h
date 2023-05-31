#include <iostream>
#include <ostream>
#include <vector>
#include "Board.h"
#include "Box.h"
#include "Ladder.h"
#include "Snake.h"
// #include "Player.h"
#include "Dice.h"
using namespace std;
#pragma once

class Game {
    Dice dice;
    Board board;
    // vector<Player> players;
    public:
        Game();
        ~Game();
        void start();
};

Game::Game() {}

Game::~Game() {}

void Game::start() {
    srand(time(NULL));
    dice.roll();
    cout << dice.getNumber() << endl;    
}