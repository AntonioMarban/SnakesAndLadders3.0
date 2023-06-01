// Antonio Marbán Regalado & Carol Jatziry Rendon Guerrero
// TC1030 - Mónica Larre Bolaños
// Tarea 3 - Herencia y Polimorfismo

#include <iostream>
#include "Tile.h"
using namespace std;
#pragma once

class Ladder : public Tile {
    public:
        Ladder() = default;
        Ladder(const char &tileType, const int &tileNumber) : Tile(tileType, tileNumber) {}
        ~Ladder() {}
};

