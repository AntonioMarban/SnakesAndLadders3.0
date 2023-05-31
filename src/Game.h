#include <iostream>
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
    const int C = 10; // Number of tiles (minimum of 5)
    const int S = 1; // Number of snake tiles
    const int L = 1; // Number of ladder tiles
    const int P = 3; // Snake penalty 
    const int R = 3; // Ladder reward
    const int PL = 2; // Number of players
    const int T = 100; // Maximum number of turns
    const char GT = 'M'; // Game Type: 'A' for automatic / 'M' for manual

    Dice dice;
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
    if ((S + L) > (C - (P + R + 1))) { // Number of special tiles > Number of available legal tiles (Total - Reward - Penalty - 1)
        cout << "Invalid snakes and ladders number; they cannot exceed the number of tiles and they cannot be placed in illegal tiles (start, end, or any other tile that could possibly make the player step out of the board when penalized/rewarded)" << endl;
    }
    else {
        srand(time(NULL));
        dice.roll();
        Board board(C, S, L, P, R); // Tile number, snakes number, ladders number, penalty, reward
    }
}