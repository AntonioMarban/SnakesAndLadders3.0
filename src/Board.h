// Antonio Marbán Regalado & Carol Jatziry Rendon Guerrero
// TC1030 - Mónica Larre Bolaños
// Tarea 3 - Herencia y Polimorfismo

#pragma once
#include <iostream>
#include <vector>
#include "Tile.h"
#include "Ladder.h"
#include "Snake.h"
#include "Dice.h"
using namespace std;

class Board {
    Dice dice;
    int numberOfTiles;
    int numberOfSnakes;
    int numberOfLadders;
    int penalty;
    int reward;
    vector<Tile*> tiles; // vector con apuntadores tipo box
    
    public:
        Board() = default; // constructor por omisión
        Board(const int&, const int&, const int&, const int&, const int&); // constructor por argumentos 1
        Board(const int&, const int&, const int&, const vector<Tile*>); // constructor por argumentos 2
        ~Board();

        int getNumberOfTiles();
        int getNumberOfSnakes();
        int getNumberOfLadders();
        int getPenalty();
        int getReward();
        vector<Tile*> getTiles();

        void setNumberOfTiles(int);
        void setNumberOfSnakes(int);
        void setNumberOfLadders(int);
        void setPenalty(int);
        void setReward(int);
        void setTiles(vector<Tile*>);        
};

Board::Board(const int& numberOfTiles, const int& numberOfSnakes, const int& numberOfLadders, const int& penalty, const int& reward) {

    this->numberOfTiles = numberOfTiles;
    this->numberOfSnakes = numberOfSnakes;
    this->numberOfLadders = numberOfLadders;
    this->penalty = penalty;
    this->reward = reward;
    srand(time(NULL));
    for (int i = 0; i < numberOfTiles; i++) {
        tiles.push_back(new Tile('N', i));
    }

    for (int i = 0; i < numberOfSnakes; i++) { // Repeats this process until all snakes are placed on the board
        int tile;
        do {
            tile = dice.customRoll(penalty, numberOfTiles - 1); // No snakes on the first {penalty} tiles and no snakes on the last tile.
        }
        while(tiles[tile]->getTileType() == 'S' || tiles[tile]->getTileType() == 'L'); // Makes sure to replace a normal tile
        tiles.erase(tiles.begin() + tile); // Removes the normal tile
        tiles.insert(tiles.begin() + tile, new Snake('S', tile)); // Inserts the snake tile where the normal tile used to be
    }

    for (int i = 0; i < numberOfLadders; i++) { // Repeats this process until all ladders are placed on the board
        int tile;
        do {
            tile = dice.customRoll(1, numberOfTiles - reward - 1); // No ladders on the first tile and on the last {reward - 1} tiles 
        }                                                          // The - 1 is so you cannot win by falling on a ladder 
        while(tiles[tile]->getTileType() == 'S' || tiles[tile]->getTileType() == 'L'); // Makes sure to replace a normal tile
        tiles.erase(tiles.begin() + tile); // Removes the normal tile
        tiles.insert(tiles.begin() + tile, new Ladder('L', tile)); // Inserts the ladder tile where the normal tile used to be
    }
    
    for (int i = 0; i < numberOfTiles; i++) {
        tiles[i]->printTile();   
    }
}

Board::Board(const int& numberOfTiles, const int& numberOfSnakes, const int& numberOfLadders, const vector<Tile*> tiles) {

    this->numberOfTiles = numberOfTiles;
    this->numberOfSnakes = numberOfSnakes;
    this->numberOfLadders = numberOfLadders;
    this->tiles = tiles;
}

Board::~Board() {}

int Board::getNumberOfTiles() {
    return numberOfTiles;
}
int Board::getNumberOfSnakes() {
    return numberOfSnakes;
}
int Board::getNumberOfLadders() {
    return numberOfLadders;
}

int Board::getPenalty() {
    return penalty;
}
int Board::getReward() {
    return reward;
}

vector<Tile*> Board::getTiles() {
    return tiles;
}

void Board::setNumberOfTiles(int numberOfTiles) {
    this->numberOfTiles = numberOfTiles;
}
void Board::setNumberOfSnakes(int numberOfSnakes) {
    this->numberOfSnakes = numberOfSnakes;
}
void Board::setNumberOfLadders(int numberOfLadders) {
    this->numberOfLadders = numberOfLadders;
}

void Board::setTiles(vector<Tile*> tiles) {
    this->tiles = tiles;
}

void Board::setPenalty(int penalty) {
    this->penalty = penalty;
}
void Board::setReward(int reward) {
    this->reward = reward;
}



