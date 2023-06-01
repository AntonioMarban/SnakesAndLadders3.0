#include <iostream>
#include <vector>
#include <string>
#include "Board.h"
#include "Tile.h"
#include "Ladder.h"
#include "Snake.h"
#include "Player.h"
#include "Dice.h"
using namespace std;
#pragma once

class Game {
    const int C = 20; // Number of tiles (minimum of 5)
    const int S = 1; // Number of snake tiles
    const int L = 1; // Number of ladder tiles
    const int P = 3; // Snake penalty 
    const int R = 3; // Ladder reward
    const int PL = 2; // Number of players
    const int T = 100; // Maximum number of turns
    const char GT = 'M'; // Game Type: 'A' for automatic / 'M' for manual

    int turnNumber = 0;
    bool ended = false;

    Dice dice;
    vector<Player> players;

    public:
        Game();
        ~Game();
        void start();
        bool validGame();
        void playTurn(Board);
};

Game::Game() {
}

Game::~Game() {}

bool Game::validGame() {
    if ((S + L) > (C - (P + R + 1))) { // Number of special tiles > Number of available legal tiles (Total - Reward - Penalty - 1)
        cout << "Invalid snakes and ladders number; they cannot exceed the number of tiles and they cannot be placed in illegal tiles (start, end, or any other tile that could possibly make the player step out of the board when penalized/rewarded)" << endl;
        return false;
    }
    else {
        return true;
    }
}

void Game::playTurn(Board currentBoard) {
    dice.roll();
    int rolled = dice.getNumber();
    Player &playing = players[turnNumber%PL];

    playing.setPosition(playing.getPosition() + rolled); // Moves the player the number of tiles indicated by the dice roll


    Tile * currentTile = currentBoard.getTiles()[playing.getPosition()]; // Pointer to the tile landed on
    char currentTileType = currentTile->getTileType(); // Saves type of the tile landed on

    if (currentTileType == 'N' ) { // Landed on a normal tile
        if (playing.getPosition() > C) { // If player reaches the last tile
            cout << turnNumber + 1 << " " << playing.getPlayerNum() << " " << playing.getPosition() - rolled + 1 << " " <<  rolled << " " << currentTileType << " " << C << endl;
            cout << "Player " << playing.getPlayerNum() << " is the winner!!!" << endl; // Game Over by victory
            ended = true; // Ends the game
        }
        else {
            cout << turnNumber + 1 << " " << playing.getPlayerNum() << " " << playing.getPosition() - rolled + 1<< " " <<  rolled << " " << currentTileType << " " << playing.getPosition() + 1 << endl; // Normal turn output
        }        
    } 
    else if (currentTileType == 'S') { // Landed on a snake
        cout << turnNumber + 1 << " " << playing.getPlayerNum() << " " << playing.getPosition() - rolled + 1 << " " << rolled << " " << currentTileType << " " << playing.getPosition() - P + 1 << endl;
        playing.setPosition(playing.getPosition() - P); // Makes the player move P tiles back
    }
    else { // Landed on a ladder
        cout << turnNumber + 1 << " " << playing.getPlayerNum() << " " << playing.getPosition() - rolled + 1 << " " << rolled << " " << currentTileType << " " << playing.getPosition() + R + 1 << endl;
        playing.setPosition(playing.getPosition() + R); // Makes the player move R tiles forward
    }
    
}


void Game::start() {
    if (!validGame()) {return;}
    srand(time(NULL));
    Board board(C, S, L, P, R); // Tile number, snakes number, ladders number, penalty, reward
    for (int i = 0; i < PL; i++) {
        string nombre;
        cout << "Ingrese el nombre del jugador " << i + 1 << ":" << endl;
        cin >> nombre;
        players.push_back(Player(nombre, i + 1));
    }
    playTurn(board);
}