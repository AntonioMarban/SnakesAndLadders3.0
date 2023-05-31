#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
#pragma once

class Dice {
    int number;
    public:
        Dice();
        ~Dice();
        int getNumber();
        void setNumber(int);
        void roll();
};

Dice::Dice() {
    number = 0;
    }

Dice::~Dice() {}

int Dice::getNumber() {
    return number;
}

void Dice::setNumber(int num) {
    number = num;
}

void Dice::roll() {
    number = 1 + rand()%6;
}