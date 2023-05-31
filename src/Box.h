#include <iostream>
using namespace std;
#pragma once

class Box {
    char boxType;
    int boxNum;
    public:
        Box() {};
        Box(const char &boxType,const int &boxNum) : boxType(boxType), boxNum(boxNum){};
        ~Box();
        // Getters
        char getboxType();
        int getboxNum();
        // Setters
        void setboxType(char);
        void setboxNum(int);
};

Box::~Box() {}

char Box::getboxType() {
    return boxType;
}

int Box::getboxNum() {
    return boxNum;
}
void Box::setboxType(char _boxType) {
    boxType = _boxType;
}

void Box::setboxNum(int _boxNum) {
    boxNum = _boxNum;
}
