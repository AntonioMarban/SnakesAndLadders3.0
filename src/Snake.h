// Antonio Marbán Regalado & Carol Jatziry Rendon Guerrero
// TC1030 - Mónica Larre Bolaños
// Tarea 3 - Herencia y Polimorfismo

#include <iostream>
#include "Tile.h"
using namespace std;
#pragma once

class Snake : public Tile {
    public:
        Snake() = default;
        Snake(const char &tileType, const int &tileNumber) : Tile(tileType, tileNumber) {}
        ~Snake() {}
};
