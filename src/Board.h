#pragma once
#include <iostream>
#include <vector>
#include "Tile.h"
#include "Ladder.h"
#include "Snake.h"
using namespace std;

class Board {
    int numberOfTiles;
    int numberOfSnakes;
    int numberOfLadders;
    vector<Tile*> tiles; // vector con apuntadores tipo box
    
    public:
        Board() = default; // constructor por omisión
        Board(const int&, const int&, const int&, const vector<Tile*>); // constructor por argumentos
        ~Board();

        int getNumberOfTiles();
        int getNumberOfSnakes();
        int getNumberOfLadders();
        vector<Tile*> getTiles();

        void setNumberOfTiles(int);
        void setNumberOfSnakes(int);
        void setNumberOfLadders(int);
        void setTiles(vector<Tile*>);

        void printBoard();
        
};

Board::Board(const int& numberOfTiles, const int& numberOfSnakes, const int& numberOFLadders, const vector<Tile*> tiles) {

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

vector<Tile*> Board::getTiles() {
    return tiles;
}

void Board::setNumberOfTiles(int numberOfTiles) {
    this->numberOfTiles = numberOfTiles;
}
void Board::setNumberOfSnakes(int numberOfSnakes) {
    this->numberOfSnakes = numberOfTiles;
}
void Board::setNumberOfLadders(int numberOfLadders) {
    this->numberOfLadders = numberOfLadders;
}

void Board::setTiles(vector<Tile*> tiles) {
    this->tiles = tiles;
}




