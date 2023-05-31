#pragma once
#include <iostream>
#include <vector>
#include "Box.h"
#include "Ladder.h"
#include "Snake.h"
using namespace std;

class Board {
    int numberOfBoxes;
    vector<Box*> boxes; // vector con apuntadores tipo box
    
    public:
        Board() = default; // constructor por omisión
        Board(const int&, const vector<Box*>); // constructor por argumentos
        ~Board();

        int getNumberOfBoxes();
        vector<Box*> getBoxes();

        void setNumberOfBoxes(int);
        void setBoxes(vector<Box*>);

        void printBoard();
        
};

Board::Board(const int& numberOfBoxes, const vector<Box*> boxes) {

    this->numberOfBoxes = numberOfBoxes;
    this->boxes = boxes;
}

Board::~Board() {}

int Board::getNumberOfBoxes() {
    return numberOfBoxes;
}

vector<Box*> Board::getBoxes() {
    return boxes;
}

void Board::setNumberOfBoxes(int numberOfBoxes) {
    this->numberOfBoxes = numberOfBoxes;
}

void Board::setBoxes(vector<Box*> boxes) {
    this->boxes = boxes;
}




