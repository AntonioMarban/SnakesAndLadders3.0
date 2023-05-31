#include <iostream>
#include <ostream>
#include <vector>
#include "Board.h"
#include "Tile.h"
#include "Ladder.h"
#include "Snake.h"
#include "Player.h"
#include "Dice.h"
using namespace std;
#pragma once

class Game {
    const int C = 30; // Number of tiles
    const int S = 3; // Number of snake tiles
    const int L = 3; // Number of ladder tiles
    const int P = 3; // Snake penalty 
    const int R = 3; // Ladder reward
    const int PL = 2; // Number of players
    const int T = 100; // Maximum number of turns
    const char GT = 'M'; // Game Type: 'A' for automatic / 'M' for manual

    Dice dice;
    Board board;
    vector<Player> players;
    public:
        Game();
        ~Game();
        void start();
};

Game::Game() {
}

Game::~Game() {}

void Game::start() {
    srand(time(NULL));
    dice.roll();
    cout << dice.getNumber() << endl;  
    cout << players.size() << players.capacity() << endl;  
}