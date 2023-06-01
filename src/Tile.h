// Antonio Marbán Regalado & Carol Jatziry Rendon Guerrero
// TC1030 - Mónica Larre Bolaños
// Tarea 3 - Herencia y Polimorfismo

#include <iostream>
using namespace std;
#pragma once

class Tile {
    char tileType;
    int tileNumber;
    public:
        Tile() {};
        Tile(const char &tileType,const int &tileNumber) : tileType(tileType), tileNumber(tileNumber){};
        ~Tile();
        // Getters
        char getTileType();
        int getTileNumber();
        // Setters
        void setTileType(char);
        void setTileNumber(int);

        void printTile();
};

Tile::~Tile() {}

char Tile::getTileType() {
    return tileType;
}

int Tile::getTileNumber() {
    return tileNumber;
}
void Tile::setTileType(char tileType) {
    this->tileType = tileType;
}

void Tile::setTileNumber(int tileNumber) {
    this->tileNumber = tileNumber;
}

void Tile::printTile() {
    cout << tileNumber << tileType << endl;
}