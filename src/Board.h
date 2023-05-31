#pragma once
#include <iostream>
#include <vector>
#include "Tile.h"
#include "Ladder.h"
#include "Snake.h"
using namespace std;

class Board {
    int numberOfBoxes;
    vector<Tile*> boxes; // vector con apuntadores tipo box
    
    public:
        Board() = default; // constructor por omisión
        Board(const int&, const vector<Tile*>); // constructor por argumentos
        ~Board();

        int getNumberOfBoxes();
        vector<Tile*> getBoxes();

        void setNumberOfBoxes(int);
        void setBoxes(vector<Tile*>);

        void printBoard();
        
};

Board::Board(const int& numberOfBoxes, const vector<Tile*> boxes) {

    this->numberOfBoxes = numberOfBoxes;
    this->boxes = boxes;
}

Board::~Board() {}

int Board::getNumberOfBoxes() {
    return numberOfBoxes;
}

vector<Tile*> Board::getBoxes() {
    return boxes;
}

void Board::setNumberOfBoxes(int numberOfBoxes) {
    this->numberOfBoxes = numberOfBoxes;
}

void Board::setBoxes(vector<Tile*> boxes) {
    this->boxes = boxes;
}




