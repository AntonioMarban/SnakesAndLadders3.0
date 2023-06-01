// Antonio Marbán Regalado & Carol Jatziry Rendon Guerrero
// TC1030 - Mónica Larre Bolaños
// Tarea 3 - Herencia y Polimorfismo

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
        int customRoll(int, int);
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

void Dice::roll() { // Choose a random number from 0 to 5 (0:6) and adds 1, making it a random number from 1 to 6
    number = 1 + rand()%6; // Sets the random value to the Dice::number variable
}

int Dice::customRoll(int min, int max) { // Choose a random number from a specified range and returns it
    return min + rand()%max;      
}