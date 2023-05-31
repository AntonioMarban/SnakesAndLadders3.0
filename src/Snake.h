#include <iostream>
#include "Box.h"
using namespace std;
#pragma once

class Snake : public Box {
    public:
        Snake() = default;
        Snake(const char &boxType, const int &boxNum) : Box(boxType, boxNum) {}
        ~Snake() {}
};
