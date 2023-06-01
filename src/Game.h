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

    // Default values
    int C = 30; // Number of tiles (minimum of 5)
    int S = 3; // Number of snake tiles
    int L = 3; // Number of ladder tiles
    int P = 3; // Snake penalty 
    int R = 3; // Ladder reward
    int PL = 2; // Number of players
    int T = 100; // Maximum number of turns
    char GM= 'A'; // Game mode: 'A' for automatic / 'M' for manual

    int turnNumber = 0;
    bool ended = false;

    Dice dice;
    vector<Player> players;

    public:
        Game();
        ~Game();
        void start();
        void askForParameters();
        bool validGame();
        void playTurn(Board);
};

Game::Game() {
}

Game::~Game() {}

void Game::askForParameters() {
    cout << "Please indicate the following..." << endl;
    cout << "Number of tiles: ";
    cin >> C;
    cout << "Number of snake tiles: ";
    cin >> S;
    cout << "Number of ladder tiles: ";
    cin >> L;
    cout << "Penalty for landing on a snake tile: ";
    cin >> P;
    cout << "Penalty for landing on a ladder tile: ";
    cin >> R;
    cout << "Number of players: ";
    cin >> PL;
    cout << "Maximum number of turns: ";
    cin >> T;
    cout << "Game mode ('A' for automatic or 'M' for manual): ";
    cin >> GM;
}

bool Game::validGame() {
    if ((S + L) > (C - (P + R + 1))) { // Number of special tiles > Number of available legal tiles (Total - Reward - Penalty - 1)
        cout << "Invalid snakes and ladders number; they cannot exceed the number of tiles and they cannot be placed in illegal tiles (start, end, or any other tile that could possibly make the player step out of the board when penalized/rewarded)" << endl;
        return false;
    }
    else {
        cout << "Valid game" << endl;
        return true;
    }
}

void Game::playTurn(Board currentBoard) {
    dice.roll();
    int rolled = dice.getNumber();
    Player &playing = players[turnNumber%PL];

    playing.setPosition(playing.getPosition() + rolled); // Moves the player the number of tiles indicated by the dice roll

    Tile * currentTile = currentBoard.getTiles()[playing.getPosition()]; // Pointer to the tile landed on
    Tile &tileObject = * currentTile;
    char currentTileType = 'N';

    cout << playing.getPosition() << endl;

    if (playing.getPosition() < C) {
        currentTileType = tileObject.getTileType();
    }

    if (currentTileType == 'N' ) { // Landed on a normal tile
        if (playing.getPosition() <= C) {
            cout << turnNumber + 1 << " " << playing.getPlayerNum() << " " << playing.getPosition() - rolled + 1 << " " <<  rolled << " " << currentTileType << " " << playing.getPosition() + 1 << endl; // Normal turn output  
        }
        else {
            cout << turnNumber + 1 << " " << playing.getPlayerNum() << " " << playing.getPosition() - rolled + 1 << " " <<  rolled << " " << "N" << " " << 30 << endl; // Normal turn output  (winning)
            cout << "Player " << playing.getPlayerNum() << " is the winner!!!" << endl; // Game Over by victory
            ended = true;  
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


    turnNumber++;
    if (turnNumber >= T) {
        cout << "Maximum number of turns reached!!!" << endl; // Game Over by max turns
        ended = true;
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

    if (GM == 'M') {
        char typed;
        cout << "Welcome to Snakes & Ladders!\nType 'C' to continue to next turn, or 'E' to end the game:" << endl;
        while (!ended) {
            cin >> typed;
            while(typed != 'C' && typed != 'E') {
                cout << "Invalid option, please press C to continue next turn or E to end the game." << endl; 
                cin >> typed;  
            }
            if (typed == 'C') {
                playTurn(board);
            }
            else {
                cout << "Thanks for playing!!!" << endl;
                break;
            }
        }
        cout << "--GAME OVER--" << endl;
    }
    else {
        while(!ended) {
            playTurn(board);
        }
        cout << "--GAME OVER--" << endl;
    }
}