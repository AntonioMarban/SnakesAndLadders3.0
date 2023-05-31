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

