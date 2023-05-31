#include <iostream>
#include "Box.h"
using namespace std;
#pragma once

class Ladder : public Box {
    public:
        Ladder() = default;
        Ladder(const char &boxType, const int &boxNum) : Box(boxType, boxNum) {}
        ~Ladder() {}
};

